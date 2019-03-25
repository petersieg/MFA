/*
Show directory of a MFA minidos 320k image file
(c) 2019 peter.sieg1@gmx.de CC BY-SA
mostly complete untested! 
Always work on backup files and envorinment!
Use at your own risk!

DAS INHALTSVERZEICHNIS IST WIE FOLGT AUFGEBAUT:
-----------------------------------------------

ES BESTEHT AUS DEN SEKTOREN 1,2,3,4 UND 5 AUF SPUR 0 SEITE 0.

JEDER SEKTOR BESTEHT AUS 16 EINTRÄEGEN A 32 BYTE.
DER LETZTE EINTRAG IM 5. SEKTOR WIRD NICHT GENUTZT.
DAMIT ERGIBT SICH EINE ANZAHL VON 79 GENUTZTEN EINTRÄEGEN.

FUER JEDES FILE WIRD PRO ANGEFANGENE 4K-BYTE EIN EINTRAG BELEGT.
FILES, DIE MEHR ALS EINEN EINTRAG BELEGEN (LAENGE > 4K—BYTE) WERDEN
ALS "MEHREACH-EINTRAG" BEZEICHNET. 

FILES, DIE NUR EINEN EINTRAG BELEGEN (LAENGE <= 4K-BYTE), WERDEN 
ALS "EINZEL-EINTRAG" BEZEICHNET.

BEI MEHRFACH-EINTRÄEGEN BEFINDEN SICH DIE EINTRAEGE ZU DEN EINZELNEN
4K-BYTE-BL0ECKEN IN DER REIHENFOLGE, IN DER DIE EINZELNEN BLOECKE BEIM
ABSPEICHERN IM SPEICHER STANDEN.

EIN EINTRAG ENTHAELT FOLGENDE I N F O R M A T I O N:

1. BYTE         :: KENNBYTE

2. - 13. BYTE   :: FILE-NAME INCL. ".", RECHTS MIT 80h AUFGEFUELLT

14. - 15. BYTE  :: START-ADR (BEI MEHRFACH-EINTRÄEGEN START-ADR DES 1. BLOCKS)
16. - 17. BYTE  :: LAENGE (BEI MEHRFACH—EINTRÄEGEN LAENGE DES GESAMT-FILES)

18. - 32. BYTE OHNE BEDEUTUNG

DAS KENNBYTE HAT FOLGENDE B E D E U T U N G:

0000 0000 - EINTRAG FREI

SONST:
1XXX XXXX - TEIL 1 ... N-1 EINES N-TEILIGEN MEHRFACH-EINTRAGS
OXXX XXXX - TEIL N EINES N-TEILIGEN MEHRFACH-EINTRAGS
            ODER EINZEL-EINTRAG

BEI EINEM BELEGTEN EINTRAG GEBEN DIE BITS 0 BIS 6 AUSKUNFT
UEBER DEN F I L E - T Y P:
XOOO 0001 - MAT
XOOO 0010 - SPS
XOOO 0011 - BAS

DER TYP GIBT AN, VON WO DAS DOS VOR DEM ABSPEICHERN EINES FILES
AUFGERUFEN WURDE.

BEISPIEL: TYP = "BAS": DAS DOS WURDE VON BASIC AUFGERUFEN
DAS FILE IST EIN BASIC-PROGRAMM

DIE POSITION EINES EINTRAGS INNERHALB DES VERZEICHNISES GIBT
AUSKUNFT DARUEBER WO DER IM EINTRAG ANGEGEBENE FILE AUF DER
DISKETTE GESPEICHERT IST.

DAZU WERDEN DIE EINZELNEN DIRECTORY-EINTRAEGE UEBER ALLE DIRECTORY­
SEKTOREN VON 1 BIS 79 DURCHNUMMERIERT.

STELLT MAN DIE EINTRAGS-NUMMER (1 .. 79) BINAER DA, SO GIBT BIT 0
DIE SEITE AN:
XXXX XXXO --- SEITE 0
XXXX XXXI --- SEITE 1

DIE BITS 1 BIS 7 GEBEN DIE SPUR AN:
BEISPIELE: 
EINTRAGS-NUMMER  BINAER-DARSTELLUNG  SEITE   SPUR
1                   0000 0001           1       0
2                   0000 0010           0       1
3                   0000 0011           1       1
4                   0000 0100           0       2
5                   0000 0101           1       2
.
.
.
78                  0100 1110           0       39
79                  0100 1111           1       39


SEITE 0, SPUR 0 IST DURCH DAS VERZEICHNIS BELEGT.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*************************************************************************************************/
/* Conversion-functions */
typedef unsigned char byte, *buffer;

/*************************************************************************************************/
int main(int argc, char *argv[])
{
    FILE* fp;
    buffer buff;
    int idx = 0;
	int adr = 0;
	int pos = 1; // position in directory 1..79
    int fpos= 0; // position in image file
    int len = 0; // file length
    int xfpos= 0; // position in image file for extraction
    int xlen = 0; // file length file for extraction
    char filename[12];

    if(argc > 1)
    {
       
        if( (fp = fopen(argv[1], "rb")) == NULL )
        {
           puts("[!]Problem with opening the file: "); puts(argv[1]);
           exit;
        }
        /*else
           puts("File has been opened successfully.\n");*/

        /* Finds the file size, allocates memory for the buffer and copies the file within the buffer       (faster processing) */
        unsigned int fp_size;
        fseek(fp, 0, SEEK_END);
        fp_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        buff = calloc(fp_size, sizeof(byte));
        fread(buff, sizeof(byte), fp_size, fp);
        fclose(fp);
        
        printf("PO-KB-TYP-FILENAME   -START-LEN-S-TR-FPOS-FPDEC\r\n");
        printf("-----------------------------------------------\r\n");
        for (adr=0; adr < (79 * 32); adr+=32)
        {    
        byte current = buff[adr+0];
        if (current != 0) 
        {         
            printf("%02d-",pos);
//1. BYTE         :: KENNBYTE
//0000 0000 - EINTRAG FREI
//1XXX XXXX - TEIL 1 ... N-1 EINES N-TEILIGEN MEHRFACH-EINTRAGS
//OXXX XXXX - TEIL N EINES N-TEILIGEN MEHRFACH-EINTRAGS - ODER EINZEL-EINTRAG
//BEI EINEM BELEGTEN EINTRAG GEBEN DIE BITS 0 BIS 6 AUSKUNFT UEBER DEN F I L E - T Y P:
//XOOO 0001 - MAT
//XOOO 0010 - SPS
//XOOO 0011 - BAS
            printf("%02X-",current);
            if ((current & 0b11) == 0b11) printf("BAS-");
            if ((current & 0b11) == 0b10) printf("SPS-");
            if ((current & 0b11) == 0b01) printf("MAT-");
//2. - 13. BYTE   :: FILE-NAME INCL. ".", RECHTS MIT 80h AUFGEFUELLT
            for (idx=1; idx<12; idx++)
            {
                byte current = buff[adr+idx];
                if (current == 0x80) current = 0; // 0x80 -> 0
                //printf("%c",current);
                filename[idx-1] = current;
            }
            filename[11] = 0;
            printf("%-11s",filename);
//14. - 15. BYTE  :: START-ADR (BEI MEHRFACH-EINTRÄEGEN START-ADR DES 1. BLOCKS)
            printf("-%02X%02X",buff[adr+14],buff[adr+13]);
//16. - 17. BYTE  :: LAENGE (BEI MEHRFACH—EINTRÄEGEN LAENGE DES GESAMT-FILES)
            printf("-%02X%02X",buff[adr+16],buff[adr+15]);
            len = ((buff[adr+16] * 256) + buff[adr+15]);
/*
STELLT MAN DIE EINTRAGS-NUMMER (1 .. 79) BINAER DA, SO GIBT BIT 0
DIE SEITE AN:
XXXX XXXO --- SEITE 0
XXXX XXXI --- SEITE 1

DIE BITS 1 BIS 7 GEBEN DIE SPUR AN:
BEISPIELE: 
EINTRAGS-NUMMER  BINAER-DARSTELLUNG  SEITE   SPUR
1                   0000 0001           1       0
2                   0000 0010           0       1
3                   0000 0011           1       1
4                   0000 0100           0       2
5                   0000 0101           1       2
.
.
.
78                  0100 1110           0       39
79                  0100 1111           1       39
*/
            if ((pos & 0b1) == 0b1) printf("-1-"); else printf("-0-");
            printf("%02d",(pos >> 1));
            fpos = (pos * 4096);
            printf("-%04X-%05d\r\n",fpos,fpos);
            //printf("=> %s - %05d - %05d\r\n",filename,len,fpos);
            // file to extract?
            if(argc > 2)
            {
                if (xfpos == 0) 
                {
                    if (strcmp(filename,argv[2]) == 0) 
                    {
                        xlen = len;
                        xfpos= fpos;
                    }        
                }        
            }        
        }
        pos++;
        }        
	    printf("\r\n");
        // file to extract?
        if(xfpos > 0)
        {
            if( (fp = fopen(argv[2], "wb")) == NULL )
            {
                puts("[!]Problem with opening the file: "); puts(argv[2]);
            }
            else
            {
                idx = fwrite(buff + xfpos,sizeof(byte),xlen,fp);
                fclose(fp);
                printf("%d bytes extracted to file %s\r\n",idx, argv[2]);
            }
        }
        free(buff);
    }
    else // no argv given - show some help
    {
        puts("md-dir <image> [<file to extract>]");
        puts("Show directory of 320k MFA MiniDOS floppy disk image file.");
        puts("Optionally try to extrakt file given as second parameter.");
        puts("Always use ONLY on backup copies! Mostly untested! Use at own risk!");
    }

}
