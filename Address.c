/* 
 * File:   main.c
 * Author: abuchmann
 *
 * Created on 26. Oktober 2013, 15:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Address.h"



/* Global VAR: Addresslist */
addressList_t* addressList = NULL;


int main(int argc, char** argv) {
    
    char c;
    
    /* Initialize the List */
    initializeAddressList();
    
    
    do {
        //system("clear");
        printf("\n");
        printf("N --> New address\n");
        printf("L --> List addresses\n");
        printf("R --> Read addresses from file\n");
        printf("S --> Save addresses to file\n");
        printf("1 --> Sort list by name\n");
        printf("2 --> Sort list by street\n");
        printf("3 --> Sort list by city\n");
        printf("Q --> Quit\n\n");
        while (!isalnum(c = getchar())); // Solange einlesen bis Zahl oder Buchstabe
        c = toupper(c);
        switch (c)
        {
            case 'N':
                showAddAddressMenu();
                break;
            case 'L':
                listAddresses();
                break;
            case 'R':
                showFileOpenMenu();
                break;
            case 'S':
                showSaveToFileMenu();
                break;
            case '1':
                sortAddressList(NAME);
                break;
            case '2':
                sortAddressList(STREET);
                break;
            case '3':
                sortAddressList(CITY);
                break;
        }
    } while (c != 'Q');
    
    return (EXIT_SUCCESS);
}

/**
 
 */
void addAddressToList(address_t* addressToAdd)
{
    /* Wenn es sich um den ersten Eintrag handelt */
    if(addressList->size == 0)
    {
        addressList->addr = (address_t*) malloc(sizeof(address_t));      
    }
    /* Wenn bereits Einträge vorhanden */
    else
    {
        addressList->addr = (address_t*) realloc(addressList->addr,(addressList->size + 1) * sizeof(address_t));                
    }
    /* Neu erstellter Speicherplatz mit Daten füllen */
    printf("Pointer1: %p\n\n", &addressList->addr[addressList->size]);
    
    /*static int i=0;
    address_t newAddress;
    strcpy(newAddress.firstname, "Adrian");
    strcpy(newAddress.lastname,"Buchmann");
    strcpy(newAddress.street,"Street");
    newAddress.zip = 6000+ i;
    strcpy(newAddress.city,"Luzern");
    newAddress.index = i+1;
    i++;
     * */
    
    /*?????*/
    addressList->addr[addressList->size] = *addressToAdd;
    
    addressList->size++;
}

/**
 * Creates a new list
 */
void initializeAddressList()
{
    addressList = (addressList_t*) malloc(sizeof (addressList_t));
    addressList->size = 0;
    addressList->addr = NULL;   
}       

void showAddAddressMenu()
{       
    address_t newAddress;
    static int i = 0;
    /*system("clear");
    printf("Name:          ");
    scanf("%s",newAddress->lastname);
    printf("Vorname:       ");
    scanf("%s",newAddress->firstname);
    printf("Strasse:       ");
    scanf("%s",newAddress->street);
    printf("Postleitzahl:  ");
    scanf("%i",&newAddress->zip);
    printf("Wohnort:       ");
    scanf("%s",newAddress->city);
    */
   /* strcpy(newAddress.firstname, "Adrian");
    strcpy(newAddress.lastname,"Buchmann");
    strcpy(newAddress.street,"Street");
    newAddress.zip = 6000 + i;
    strcpy(newAddress.city,"Luzern");
    newAddress.index = i+1;*/
    strcpy(newAddress.firstname, "Adrian");
    strcpy(newAddress.lastname, "Buchmann");
    strcpy(newAddress.street, "Sempacherstrasse 22");
    newAddress.zip = 6000+i;
    newAddress.index = i+1;
    strcpy(newAddress.city, "Luzern");
    
    //Add newly created Address to the list
    addAddressToList(&newAddress);
    
    i++;
    printf("i: %i\n",i);
    //currentAddress = &newAddress;
    //printf("\n\n%s\n",newAddress->lastname);
    
}

void listAddresses(void)
{
    system("clear");
    int i;
    for(i=0;i<(addressList->size);i++)
    {
       printf("=====================\n"); 
       printf("%i\n%s %s\n%s\n%4i %s\n",
               addressList->addr[i].index, 
               addressList->addr[i].firstname, 
               addressList->addr[i].lastname,
               addressList->addr[i].street,
               addressList->addr[i].zip,
               addressList->addr[i].city
               );
    }
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
    int r;
    
    system("clear");
    printf("Bitte geben Sie den Dateinamen an:\n");
    scanf("%s",filename);
    FILE *fp;
    fp = fopen(filename, "r");
    address_t tempAddr;
    /*r = fscanf(fp,"%i;%s;%s;%s;%i;%s\n",
            &tempAddr.index,
            tempAddr.firstname,
            tempAddr.lastname,
            tempAddr.street,
            &tempAddr.zip,
            tempAddr.city);*/
    
    while ((r = fscanf(fp,"%i;%[^;];%[^;];%[^;];%i;%s\n",
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

void sortAddressList(sortmode mode)
{
    //Nach Namen sortieren 
    int i; // temp counter, used for stable sort
    
    // qsort(Beginning address of array, Number of elements, Size of each element, Pointer to compare function
    switch (mode) {
        case NAME:
            qsort(addressList->addr,addressList->size, sizeof(address_t), (compfn)compareByName);
            break;
        case STREET:
            qsort(addressList->addr,addressList->size, sizeof(address_t), (compfn)compareByStreet);
            break;
        case CITY:
            qsort(addressList->addr,addressList->size, sizeof(address_t), (compfn)compareByCity);
            break;
    
    }
}

int compareByIndex(const void* a,const void* b)
{
    address_t *A = (address_t*) a;
    address_t *B = (address_t*) b;
    return A->index - B->index;
}

int compareByName(const void* a,const void* b)
{
    address_t *A = (address_t*) a;
    address_t *B = (address_t*) b;
    
    
    char name1[2*MAXSTRINGLENGTH + 1]; 
    char name2[2*MAXSTRINGLENGTH + 1]; 
    
     // Copy Lastname and Firstname into one String
    strcpy(name1, A->lastname);
    strcat(name1, A->firstname);
    strcpy(name2, B->lastname);
    strcat(name2, B->firstname);

    return strcmp(name1,name2);
}

int compareByStreet(const void* a,const void* b)
{
    address_t *A = (address_t*) a;
    address_t *B = (address_t*) b;
    
    return strcmp(A->street,B->street);
}

int compareByCity(const void* a,const void* b)
{
    address_t *A = (address_t*) a;
    address_t *B = (address_t*) b;
    
    return strcmp(A->city,B->city);
}


