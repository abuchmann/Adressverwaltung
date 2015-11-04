#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"

extern addressList_t* addressList;


void sortAddressList(sortmode mode)
{
    // QSort Implementation
    switch (mode) {
        case NAME:
            qsort(addressList->addr,addressList->size, sizeof(address_t), compareByName);
            break;
        case STREET:
            qsort(addressList->addr,addressList->size, sizeof(address_t), compareByStreet);
            break;
        case CITY:
            qsort(addressList->addr,addressList->size, sizeof(address_t), compareByCity);
            break;    
    }
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
    int res;
    res = strcmp(name1,name2);
    
    printf("Vergleiche %s mit %s\n",name1,name2);

    return res;
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


