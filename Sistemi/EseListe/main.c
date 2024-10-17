#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    int x;
    int *p;
} nodo;

nodo* NuovoNodo();
void EliminaNodo();
int contaNodi(nodo* head);
int main()
{
    nodo *HEAD;
    HEAD=NuovoNodo(NULL);
    HEAD->x=12;

    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);
    HEAD=NuovoNodo(HEAD);

    printf("Nodi totali: %d\n",contaNodi(HEAD));
    printf("Hello world!\n");
    return 0;
}
nodo* NuovoNodo(nodo* next)
{
    nodo *n_p = (nodo*)malloc(sizeof(nodo));
    n_p->p = next;
    return n_p;
}
void EliminaNodo(nodo* n_p)
{
    printf("Ho cancellato nodo %d\n",n_p->x);
    free(n_p);
}
int contaNodi(nodo* head)
{
    int cont=0;
    if(head->p==NULL)
        return 0;
    while(head!=NULL)
    {
        cont++;
        head=head->p;
    }
    return cont;
}
