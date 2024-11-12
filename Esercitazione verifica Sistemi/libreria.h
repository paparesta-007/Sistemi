#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 31
#define MAX_NOMEFILM 50
#define MAX_ATTORI 100

typedef struct s_node {
    int idNodo;
    char nomeFilm[MAX_NOMEFILM + 1];
    int annoUscita;
    char attori[MAX_ATTORI + 1];
    int rating;
    struct s_node* next;
} nodo;

nodo* inserisciCoda(nodo* head, nodo* nuovoNodo);
nodo* inserisciRecord(nodo* head);
void stampa(nodo* head);
void caricaFile(char fileNome[], nodo** head);
nodo* modificaFilm(char nomeFilm[],nodo* head);
nodo* cancellaUltimiNodo(nodo* head);
nodo* cancellaNodoInput(nodo* head);
void contaFilm(nodo* head);
nodo* scambioPrimiDueNodi(nodo* head);
nodo* ordinaPerTitolo(nodo* head);
nodo* swapDueNodi(nodo** current);
nodo* invertiTutto(nodo* head);
nodo* inserisciPosizione(nodo* head, int posizione);
nodo* eliminaRatingInferiore(nodo* head, int soglia);
nodo* cancellaAnnoSuperiore(nodo* head, int soglia);
nodo* scambiaDuePosizioni(nodo* head, int pos1, int pos2);
void stampaFilmPerAttore(nodo* head, char* attore);
char menu();

char menu() {
    char s;
    system("cls");  // Optional, remove or comment out for Linux/MacOS
    printf("\033[0;31m---Esercizi sulle liste---\033[0m\n\n");
    printf("a. Aggiungi nodo\n");
    printf("b. Stampa\n");
    printf("c. Carica dati da csv\n");
    printf("d. Modifica film\n");
    printf("e. Conta film\n");
    printf("f. Elimina ultimo nodo\n");
    printf("g. Elimina nodo in input\n");
    printf("h. Scambia i primi due nodi\n");
    printf("i. Ordina\n");
    printf("j. Inverti\n");
    printf("k. Inserisci nodo in una posizione\n");
    printf("l. Elimina film con rating inferiore\n");
    printf("m. Elimina film con anno superiore\n");
    printf("n. Scambia due posizioni\n");
    printf("o. Stampa film per attore\n");
    printf("w. Scrivi lista in un file CSV\n");
    printf("q. Esci\n");
    printf("Scelta: ");
    s = getchar();
    getchar();  // Consume newline left in input buffer
    return s;
}


nodo* inserisciCoda(nodo* head, nodo* nuovoNodo) {
    if (head == NULL) {
        nuovoNodo->idNodo = 1;
        return nuovoNodo;  // Nuova testa della lista
    }
    nodo* current = head;
    int id = 2;
    while (current->next != NULL) {
        current = current->next;
        id++;
    }
    current->next = nuovoNodo;
    nuovoNodo->idNodo = id;
    return head;  // Testa non cambia
}

nodo* inserisciRecord(nodo* head) {
    int intCampo;

    nodo* nuovoNodo = (nodo*)malloc(sizeof(nodo));
    if (nuovoNodo == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return head;
    }
    nuovoNodo->next = NULL;

    printf("Inserisci nome film: ");
    gets(nuovoNodo->nomeFilm);

    printf("Inserisci anno uscita: ");
    scanf("%d", &intCampo);
    nuovoNodo->annoUscita = intCampo;
    getchar();

    printf("Inserisci attori: ");
    gets(nuovoNodo->attori);

    printf("Inserisci il tuo rating: ");
    scanf("%d", &intCampo);
    nuovoNodo->rating = intCampo;
    getchar();
    head = inserisciCoda(head, nuovoNodo);

    return head;
}
void stampa(nodo* head) {
    nodo* current = head;
    if (current == NULL) {
        printf("La lista e' vuota.\n");
        return;
    }

    while (current != NULL) {
        printf("Nome: %s\n", current->nomeFilm);
        printf("Anno uscita: %d\n", current->annoUscita);
        printf("Attori: %s\n", current->attori);
        printf("Rating: %d\n", current->rating);
        printf("\n");
        current = current->next;
    }
}

void caricaFile(char fileNome[], nodo** head){
    FILE *fp = fopen(fileNome, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char str[SIZE * 3];

    while (fgets(str, sizeof(str), fp)){
        nodo* nuovoNodo = (nodo*)malloc(sizeof(nodo));
        if (nuovoNodo == NULL) {
            printf("Errore di allocazione della memoria.\n");
            fclose(fp);
            return;
        }

        char *campo = strtok(str, ";");

        if (campo != NULL) {
            strcpy(nuovoNodo->nomeFilm, campo);  // Nome del film
        }

        campo = strtok(NULL, ";");
        if (campo != NULL) {
            nuovoNodo->annoUscita = atoi(campo); // Anno di uscita
        }

        campo = strtok(NULL, ";");
        if (campo != NULL) {
            strcpy(nuovoNodo->attori, campo);     // Attori
        }

        campo = strtok(NULL, ";");
        if (campo != NULL) {
            nuovoNodo->rating = atoi(campo);      // Rating
        }

        nuovoNodo->next = NULL;
        *head = inserisciCoda(*head, nuovoNodo);
    }

    fclose(fp);
    printf("File caricato correttamente.\n");
}

nodo* modificaFilm(char nomeFilm[], nodo* head) {
    nodo* current = head;
    int nAus;
    int trovato = 0;

    if (current == NULL) {
        printf("La lista è vuota.\n");
        return head;
    }

    while (current != NULL) {
        if (strcmp(nomeFilm, current->nomeFilm) == 0) {
            trovato = 1;

            printf("Inserisci nuovo nome film (precedente: %s): ", current->nomeFilm);
            gets(current->nomeFilm);

            printf("Inserisci nuovo anno di uscita (precedente: %d): ", current->annoUscita);
            scanf("%d", &nAus);
            current->annoUscita = nAus;
            getchar();  // Consuma il carattere di newline

            printf("Inserisci nuovi attori (precedente: %s): ", current->attori);
            gets(current->attori);

            printf("Inserisci nuovo rating (precedente: %d): ", current->rating);
            scanf("%d", &nAus);
            current->rating = nAus;
            getchar();  // Consuma il carattere di newline

            printf("Modifica completata con successo.\n");
            break;
        }
        current = current->next;
    }

    if (!trovato)
        printf("Film non trovato.\n");

    return head;
}
void contaFilm(nodo* head){
    int i=0;
    nodo* current=head;
    while(current!=NULL){
        i++;
        current=current->next;
    }
    printf("Ci sono %d film nella lista",i);
}
nodo* cancellaUltimoNodo(nodo* head) {
    if (head == NULL) {
        printf("La lista è già vuota.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    nodo* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    printf("Eliminato ultimo nodo...\n");
    return head;
}

nodo* cancellaNodoInput(nodo* head) {
    int pos;
    printf("Inserisci la posizione del nodo da cancellare: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("La lista è vuota.\n");
        return NULL;
    }

    if (pos == 1) {
        nodo* temp = head;
        head = head->next;
        free(temp);
        printf("Nodo in posizione 1 eliminato.\n");
        return head;
    }

    nodo* current = head;
    nodo* previous = NULL;
    while (current != NULL && current->idNodo != pos) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {  // Nodo non trovato
        printf("Posizione non trovata.\n");
        return head;
    }

    previous->next = current->next;
    free(current);
    printf("Nodo in posizione %d eliminato.\n", pos);

    return head;
}
nodo *scambioPrimiDueNodi(nodo *head)
{
    if (head == NULL || head->next == NULL) {
        return head; // Non ci sono nodi da scambiare
    }

    nodo *first = head;            // Nodo 8
    nodo *second = head->next;     // Nodo 5

    first->next = second->next;    // Nodo 8 ora punta a Nodo 7
    second->next = first;          // Nodo 5 ora punta a Nodo 8

    return second;                 // Nuova testa della lista
}
nodo* ordinaPerTitolo(nodo* head) {
    nodo* i = head;

    while (i != NULL) {
        nodo* posmin = i;
        nodo* j = i->next;

        while (j != NULL) {
            if (strcmp(j->nomeFilm, posmin->nomeFilm) < 0) {
                posmin = j;
            }
            j = j->next;
        }

        if (posmin != i) {
            swapDueNodi(&i);
        }

        i = i->next;
    }

    printf("Ordinamento completato\n");
    return head;
}

nodo* swapDueNodi(nodo** current) {

    nodo* first = *current;
    nodo* second = (*current)->next;

    first->next = second->next;

    *current = second;

    return *current;
}
nodo* invertiTutto(nodo* head) {
    nodo* prev = NULL;
    nodo* current = head;
    nodo* next = NULL;

    while (current != NULL) {
        next = current->next;  // Memorizza il nodo successivo
        current->next = prev;  // Inverte il puntatore del nodo corrente
        prev = current;        // Sposta il puntatore prev in avanti
        current = next;        // Sposta il puntatore current in avanti
    }

    head = prev;  // La nuova testa della lista è l'ultimo nodo
    return head;
}
nodo* inserisciPosizione(nodo* head, int posizione) {
    nodo* nuovoNodo = (nodo*)malloc(sizeof(nodo));
    if (nuovoNodo == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return head;
    }

    printf("Inserisci nome film: ");
    gets(nuovoNodo->nomeFilm);

    printf("Inserisci anno uscita: ");
    scanf("%d", &nuovoNodo->annoUscita);
    getchar();

    printf("Inserisci attori: ");
    gets(nuovoNodo->attori);

    printf("Inserisci il tuo rating: ");
    scanf("%d", &nuovoNodo->rating);
    getchar();

    nuovoNodo->next = NULL;

    if (posizione == 1) {
        nuovoNodo->next = head;
        return nuovoNodo;
    }

    nodo* current = head;
    int i = 1;
    while (current != NULL && i < posizione - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Posizione fuori dalla lista. Il nodo sarà aggiunto alla fine.\n");
        head = inserisciCoda(head, nuovoNodo);
    } else {
        nuovoNodo->next = current->next;
        current->next = nuovoNodo;
    }

    return head;
}
nodo* eliminaRatingInferiore(nodo* head, int soglia) {
    nodo* current = head;
    nodo* prev = NULL;

    while (current != NULL) {
        if (current->rating < soglia) {
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}
nodo* cancellaAnnoSuperiore(nodo* head, int soglia) {
    nodo* current = head;
    nodo* prev = NULL;

    while (current != NULL) {
        if (current->annoUscita > soglia) {
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

nodo* scambiaDuePosizioni(nodo* head, int pos1, int pos2) {
    if (pos1 == pos2) return head;

    nodo *node1 = NULL, *node2 = NULL, *prev1 = NULL, *prev2 = NULL, *temp = head;

    int i = 1;
    while (temp != NULL) {
        if (i == pos1) {
            node1 = temp;
        }
        if (i == pos2) {
            node2 = temp;
        }
        temp = temp->next;
        i++;
    }

    if (node1 != NULL && node2 != NULL) {
        temp = head;
        while (temp != NULL) {
            if (temp->next == node1)
                prev1 = temp;
            if (temp->next == node2)
                prev2 = temp;
            temp = temp->next;
        }

        if (prev1) prev1->next = node2;
        if (prev2) prev2->next = node1;

        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        if (pos1 == 1)
            head = node2;
        if (pos2 == 1)
            head = node1;
    }

    return head;
}
void stampaFilmPerAttore(nodo* head, char* attore) {
    nodo* current = head;
    int trovato = 0;

    while (current != NULL) {
        if (strstr(current->attori, attore) != NULL) {
            printf("Nome: %s\n", current->nomeFilm);
            printf("Anno uscita: %d\n", current->annoUscita);
            printf("Attori: %s\n", current->attori);
            printf("Rating: %d\n", current->rating);
            printf("\n");
            trovato = 1;
        }
        current = current->next;
    }

    if (!trovato) {
        printf("Nessun film trovato con l'attore: %s\n", attore);
    }
}

#endif // LIBRERIA_H_INCLUDED
