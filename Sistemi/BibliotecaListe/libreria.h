#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 31
#define MAX_AUTORE 50
#define MAX_TITOLO 100
#define MAX_ISBN 20
#define MAX_EDITORE 50

typedef struct s_node {
    int id_Nodo;
    char autore[MAX_AUTORE + 1];
    char titolo[MAX_TITOLO + 1];
    char ISBN[MAX_ISBN + 1];
    int anno;
    char editore[MAX_EDITORE + 1];
    float prezzo;
    struct s_node* next;
} nodo;

char menu();
void caricaFile(char fileNome[], nodo** head);
nodo* inserisciCoda(nodo* head, nodo* nuovoNodo);
void mostraLista(nodo* head);
nodo* swap(nodo* head);
nodo* swap(nodo* head){
    nodo* first = head; //es 1
    nodo* second = head->next; //es 2

    second->next = first;// es 3 mi metto 1
    first->next = second->next;// es 2 metto 3


    return second;
}
char menu() {
    char s;
    system("cls");
    printf("\033[0;31m---Esercizi sulle liste---\033[0m\n\n");
    printf("C. Carica file csv nella lista\n");
    printf("P. Stampa\n");
    printf("F. trova libro piu' caro\n");
    printf("I. swap\n");

    printf("Q. Esci\n");
    printf("Scelta: ");
    s = getchar();
    getchar();
    return s;
}

void caricaFile(char fileNome[], nodo** head) {
    FILE *fp = fopen(fileNome, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char str[SIZE * 3];
    while (fgets(str, sizeof(str), fp)) {
        nodo* nuovoNodo = (nodo*)malloc(sizeof(nodo));
        if (nuovoNodo == NULL) {
            printf("Errore di allocazione della memoria.\n");
            fclose(fp);
            return;
        }
        char *campo = strtok(str, "#");
        if (campo != NULL) {
            strcpy(nuovoNodo->titolo, campo);
        }

        campo = strtok(NULL, "#");
        if (campo != NULL) {
            strcpy(nuovoNodo->autore, campo);
        }

        campo = strtok(NULL, "#");
        if (campo != NULL) {
            strcpy(nuovoNodo->ISBN, campo);
        }

        campo = strtok(NULL, "#");
        if (campo != NULL) {
            nuovoNodo->anno = atoi(campo);
        }

        campo = strtok(NULL, "#");
        if (campo != NULL) {
            strcpy(nuovoNodo->editore, campo);
        }

        campo = strtok(NULL, "#");
        if (campo != NULL) {
            nuovoNodo->prezzo = atof(campo);
        }

        nuovoNodo->next = NULL;
        *head = inserisciCoda(*head, nuovoNodo);
    }


    fclose(fp);
    printf("File caricato correttamente.\n");
}

nodo* inserisciCoda(nodo* head, nodo* nuovoNodo) {
    if (head == NULL) {
        nuovoNodo->id_Nodo = 1;
        return nuovoNodo;
    }

    nodo* aus = head;
    int id = 2;
    while (aus->next != NULL) {
        aus = aus->next;
        id++;
    }

    aus->next = nuovoNodo;
    nuovoNodo->id_Nodo = id;
    return head;
}

void mostraLista(nodo* head) {
    nodo* p_node = head;
    while (p_node != NULL) {
        printf("Libro n.%i:\nTitolo: %s\nAutore: %s\nISBN: %s\nAnno: %d\nEditore: %s\nPrezzo: %.2f euro\n\n",
               p_node->id_Nodo, p_node->titolo, p_node->autore, p_node->ISBN,
               p_node->anno, p_node->editore, p_node->prezzo);
        p_node = p_node->next;
    }

}
void cercaPiuCaro(nodo* head) {
    if (head == NULL) {
        printf("La lista č vuota. Non ci sono libri da cercare.\n");
        return;
    }

    nodo* p_node = head;
    nodo* libroPiuCaro = head;
    float prezzoMassimo = head->prezzo;
    while (p_node != NULL) {
        if (p_node->prezzo > prezzoMassimo) {
            prezzoMassimo = p_node->prezzo;
            libroPiuCaro = p_node;
        }
        p_node = p_node->next;
    }

    printf("Il libro piu' caro č:\n");
    printf("Titolo: %s\n", libroPiuCaro->titolo);
    printf("Autore: %s\n", libroPiuCaro->autore);
    printf("ISBN: %s\n", libroPiuCaro->ISBN);
    printf("Anno: %d\n", libroPiuCaro->anno);
    printf("Editore: %s\n", libroPiuCaro->editore);
    printf("Prezzo: %.2f euro\n", libroPiuCaro->prezzo);
}


#endif // LIBRERIA_H_INCLUDED
