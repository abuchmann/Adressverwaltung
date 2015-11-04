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



void listAddresses(void)
{
    system("clear");
    int i;
    for(i=0;i<(addressList->size);i++)
    {
       printf("=====================\n"); 
       printf("%s %s\n%s\n%4i %s\n",
               addressList->addr[i].firstname, 
               addressList->addr[i].lastname,
               addressList->addr[i].street,
               addressList->addr[i].zip,
               addressList->addr[i].city
               );
    }
}




