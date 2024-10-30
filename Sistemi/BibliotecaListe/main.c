#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main() {
    nodo* head = NULL;
    char scelta;
    char fileNome[100];

    do {
        scelta = menu();

        switch (scelta) {
            case 'c':
            case 'C':
                printf("Inserisci il nome del file da caricare: ");
                gets(fileNome);
                caricaFile(fileNome, &head);
                break;

            case 'p':
            case 'P':
                mostraLista(head);
                break;
            case 'f':
            case 'F':
                cercaPiuCaro(head);
            case 'i':
            case 'I':
                head=swap(head);

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
