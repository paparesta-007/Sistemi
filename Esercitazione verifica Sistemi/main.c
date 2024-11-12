#include <stdio.h>
#include "libreria.h"

int main() {
    nodo* head = NULL;
    char scelta;
    char fileNome[100];
    char nomeFilm[100];
    int sogliaRating, sogliaAnno, pos1, pos2;
    do {
        scelta = menu();

        switch (scelta) {
            case 'a':
            case 'A':
                head = inserisciRecord(head);
                break;
            case 'b':
            case 'B':
                stampa(head);
                break;
            case 'c':
            case 'C':
                printf("Inserisci il nome del file da caricare: ");
                gets(fileNome);
                caricaFile(fileNome, &head);
                break;
            case 'd':
            case 'D':
                printf("Inserisci il nome del film da modificare: ");
                gets(nomeFilm);
                head = modificaFilm(nomeFilm, head);
                break;
            case 'e':
            case 'E':
                contaFilm(head);
                break;
            case 'f':
            case 'F':
                head = cancellaUltimoNodo(head);
                break;
            case 'g':
            case 'G':
                head = cancellaNodoInput(head);
                break;
            case 'h':
            case 'H':
                head = scambioPrimiDueNodi(head);
                break;
            case 'i':
            case 'I':
                head = ordinaPerTitolo(head);
                break;
            case 'j':
            case 'J':
                head = invertiTutto(head);
                break;
            case 'k':
            case 'K':
                printf("Inserisci la posizione del nodo da inserire: ");
                scanf("%d", &pos1);
                getchar(); // Consuma il carattere newline
                head = inserisciPosizione(head, pos1);
                break;
            case 'l':
            case 'L':
                printf("Inserisci una soglia di rating: ");
                scanf("%d", &sogliaRating);
                head = eliminaRatingInferiore(head, sogliaRating);
                break;
            case 'm':
            case 'M':
                printf("Inserisci un anno: ");
                scanf("%d", &sogliaAnno);
                head = cancellaAnnoSuperiore(head, sogliaAnno);
                break;
            case 'n':
            case 'N':
                printf("Inserisci due posizioni da scambiare: ");
                scanf("%d %d", &pos1, &pos2);
                head = scambiaDuePosizioni(head, pos1, pos2);
                break;
            case 'o':
            case 'O':
                printf("Inserisci il nome dell'attore: ");
                gets(nomeFilm);
                stampaFilmPerAttore(head, nomeFilm);
                break;
            case 'q':
            case 'Q':
                printf("Uscita...\n");
                break;
            default:
                printf("Inserire un valore valido\n");
                break;
        }

        printf("\nPremere un tasto per continuare\n");
        getchar();
    } while (scelta != 'q' && scelta != 'Q');

    return 0;
}
