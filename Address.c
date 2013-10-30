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



/*
 * 
 */


int main(int argc, char** argv) {
    char c;
    FILE *fp;
    fp = fopen("Adresses.txt","w");
    fprintf(fp,"Name\tVorname\tStrasse\tNummer\tPostleitzahl\tOrt\n");
    printf("ADRESSVERWALTUNG 0.1 by Adrian Buchmann\n");
    do
    {
        printf("\n");
        printf("[N]eue Adresse hinzufuegen\n");
        printf("[B]eende Programm\n");
        printf("\n");
        while (!isalnum(c = getchar()));
        c = toupper(c);
        switch(c)
        {
            case 'N':
                addAddress(fp);
                break;
            default:
                break;
        }
    } while (c!='Q');
    fclose(fp);

            
           
    return 0;
}

/* filecopy: Kopiere Datei ifp in Datei ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c=getc(ifp)) != EOF)
        putc(c,ofp);
}

