#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"


extern addressList_t* addressList;

void showAddAddressMenu()
{       
    address_t newAddress;
    int length;
    char tStreet[MAXSTRINGLENGTH-6], tStreetNr[5];
    static int i = 1;
    
    system("clear");
    printf("Name:          ");
    scanf("%s",newAddress.lastname);
    printf("Vorname:       ");
    scanf("%s",newAddress.firstname);
    printf("Strasse:       ");
    scanf("%s %s",tStreet, tStreetNr);
    printf("Postleitzahl:  ");
    scanf("%i",&newAddress.zip);
    printf("Wohnort:       ");
    scanf("%s",newAddress.city);
    
    length = strlen(tStreet);
    tStreet[length] = ' ';
    tStreet[length+1] = '\0';
    strcat(tStreet, tStreetNr);
    strcpy(newAddress.street,tStreet);
    newAddress.index = i;

    //Add newly created Address to the list
    addAddressToList(&newAddress);
    
    //Increment the Index for next String add;
    i++;   
}

void showSaveToFileMenu(void)
{
    char filename[MAXSTRINGLENGTH];
    system("clear");
    printf("Bitte geben Sie den Dateinamen an:\n");
    scanf("%s",filename);
    FILE *fp;
    fp = fopen(filename, "w+");
    int i;
    for(i = 0; i<addressList->size; i++)
    {
        fprintf(fp,"%i;%s;%s;%s;%i;%s\n",
                addressList->addr[i].index,
                addressList->addr[i].firstname,
                addressList->addr[i].lastname,
                addressList->addr[i].street,
                addressList->addr[i].zip,
                addressList->addr[i].city
                );
    }
    fclose(fp);        
}

void showFileOpenMenu(void)
{
    char filename[MAXSTRINGLENGTH];
    address_t tempAddr;
    int r;
    
    system("clear");
    FILE *fp;
    do
    {
        
        printf("Bitte geben Sie den Dateinamen an:\n");
        scanf("%s",filename);
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
            system("clear");
            printf("Die Datei %s konnte nicht geoeffnet werden! Versuchen Sie es erneut. \n",filename);            
        }
    } while(fp == NULL);
 
    while ((r = fscanf(fp,"%i;%[^;];%[^;];%[^;];%i;%s\n", //Gepimpt fürs Einlesen von Strings, welche mit einem Semikolon abgeschlossen werden
            &tempAddr.index,
            tempAddr.firstname,
            tempAddr.lastname,
            tempAddr.street,
            &tempAddr.zip,
            tempAddr.city))
             != EOF)
    {
        addAddressToList(&tempAddr);
    }
    fclose(fp);
}

