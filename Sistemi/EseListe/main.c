#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int x;
	//
	//void* next; // Indirizzo al nodo successivo
    struct node* next;
}nodo;

nodo* Inserisci(void* next);
nodo* EliminaNodo(nodo* n_p); // cambiare n_p
int contaNodi(nodo* node);
void mostraLista(nodo* node);
void inserisciCoda(nodo* node);


/* TBD:
int controlla_lista_vuota(...)
nodo* NuovoNodo();
nodo* inserisciTesta(...)
nodo* inserisciCoda(...)
nodo* inserisciPosizione(...,int pos)
nodo* eliminaNodo(...)
nodo* eliminaByPos(..., int pos);
void mostraLista(...);
nodo* aggiungiByPos(..., int pos);
nodo* aggiungiOrdinato(nodo *testa);
*/

int main() {
    nodo* head=NULL;
    //head=InserisciTesta(NULL); // Ha senso il nome?
    //head->x=0;

    for(int i = 0; i < 10; i++)
    {
        head = Inserisci(head);
        head->x = i;
    }

    mostraLista(head);

    inserisciCoda(head);

    mostraLista(head);

    //head = EliminaNodo(head);

    printf("Numero nodi: %d\n",contaNodi(head));
    return 0;
}

void inserisciCoda(nodo* node)
{
    nodo* current;

    while(node!=NULL)
    {
        current = node;
        node = current->next;
    }

    current->next = Inserisci(node);
    current->next->x = 100;
}

void mostraLista(nodo* node)
{
    while(node!=NULL)
    {
        printf("%i, ",node->x,node);
        node=node->next;
    }
    printf("\n");
}

nodo* Inserisci(void* attuale) {
    nodo* n_p;

    n_p=(nodo*)malloc(sizeof(nodo));
    ///Crea un'allocazione nella memoria per una struct nodo

    n_p->next=attuale;
    ///Imposta nel puntatore della struct l'indirizzo dell'ultimo nodo

    return n_p;
}

///Ritorna un puntatore al nodo successivo
nodo* EliminaNodo(nodo* n_p){
    nodo* aus = n_p->next;

    printf("Ho cancellato nodo %d \n\n",n_p->x);

    free(n_p);

    return aus;
}

int contaNodi(nodo* node)
{
    int i=0;

    while(node!=NULL)
    {
        node=node->next;
        i++;
    }

    return i;
}
