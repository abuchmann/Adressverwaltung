/* 
 * File:   Address.h
 * Author: abuchmann
 *
 * Created on 30. Oktober 2013, 22:10
 */

#ifndef ADDRESS_H
#define	ADDRESS_H
#endif

#define MAXSTRINGLENGTH 64 


/*
 * Strukturen
 */

typedef struct address_ {
    char firstname[MAXSTRINGLENGTH+1];
    char lastname[MAXSTRINGLENGTH+1];
    char street[MAXSTRINGLENGTH+1];
    unsigned int zip;
    char city[MAXSTRINGLENGTH+1];
    unsigned int index;
} address_t;

typedef struct addressList_ {
    address_t* addr;
    int size;
} addressList_t;

typedef enum { NAME=1, STREET, CITY} sortmode;

typedef int (*compfn)(const void *a, const void *b);


/**
 * Funktionsheader
 */

void addAddressToList(address_t* addressToAdd);

void initializeAddressList();

void showAddAddressMenu();

void listAddresses();

void showSaveToFileMenu(void);

void showFileOpenMenu();

void sortAddressList(sortmode mode);

int compareByIndex(const void *a, const void *b);
int compareByName(const void *a, const void *b);
int compareByStreet(const void*,const void*);
int compareByCity(const void* a,const void* b);


