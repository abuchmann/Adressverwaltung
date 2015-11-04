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

/**
 * Fügt der Liste eine neue Adresse hinzu
 * @param addressToAdd Pointer vom Typ address_t*, welche hinzugefügt werden soll
 */
void addAddressToList(address_t* addressToAdd);

/**
 * Initialisiert die Adressliste bzw. erweitert diese, wenn eine neue Adresse hinzugefügt werden soll
 */
void initializeAddressList();

/**
 * Zeigt das Menü an, um neue Adressen hinzuzufügen
 */
void showAddAddressMenu();

/**
 * Zeigt die aktuellen Adressen an
 */
void listAddresses();

/**
 * Zeigt das Speichern Menü an
 */
void showSaveToFileMenu(void);

/**
 * Zeigt das File-Open-Menü an
 */
void showFileOpenMenu();

/**
 * Startet eine Sortierung der Liste
 * @param mode Gibt an, nach welchem Wert sortiert werden soll, NAME, STREET oder CITY
 */
void sortAddressList(sortmode mode);

/**
 * Compare-Funktion für QSort
 * @param a erster Paramenter für den Vergleich
 * @param b zweiter Parameter der mit dem ersten Verglichen werden soll
 * @return Gibt einen positiven (a < b), negativen (a > b) Wert oder 0 (a=b) zurück)
 */
int compareByName(const void *a, const void *b);
int compareByStreet(const void*,const void*);
int compareByCity(const void* a,const void* b);

