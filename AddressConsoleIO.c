#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"

void addAddress(FILE* fp)
{
    char lastname[64];
    char surname[64];
    char street[64];
    char number[20];
    char plz[5];
    char city[50];
    
    printf("Name:\t");
    scanf("%s",lastname);
    printf("\nVorname:\t");
    scanf("%s",surname);
    printf("\nStrasse und Nummer:\t");
    scanf("%s %s",street, number);
    printf("\nPostleitzahl:\t");
    scanf("%s",plz);
    printf("\nOrt:\t");
    scanf("%s",city);
    
    fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",lastname,surname,street,number,plz,city);
    
}