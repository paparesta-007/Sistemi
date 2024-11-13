#ifndef LIBBANCA_H_INCLUDED
#define LIBBANCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_NOME 100 + 1

typedef struct s_bank {
    int id_Nodo;
    char Nome[MAX_NOME];
    char Cognome[MAX_NOME];
    float denaroTot;
    struct s_bank* next;
}  banca;

typedef struct s2_bank {
    int id_Nodo;
    char Nome[MAX_NOME];
    char Cognome[MAX_NOME];
    float denaroTot;
    struct s2_bank* next;
}  banca2;

banca* caricaFile(char* str, banca* head, int* id);
char ScriviMenu();
banca* inserisciInTesta(banca* head, int* id);
banca* inserisciInCoda(banca* head, int* id);
banca* inserisciInPos(banca* head, int pos, int* id);
void visualizzaLista(banca* head);
banca* eliminaNodoInTesta(banca* head);
banca* eliminaNodoInCoda(banca* head);
banca* eliminaNodoInPos(banca* head, int pos);
int contaNodi(banca* head);
banca* swap(banca* head);
banca* ordinaInBaseId(banca* head);
void trovaContoConPiuDenaro(banca* head);
banca* concatenaListe(banca* head, banca2* headLista2,int* id);
banca* moltiplicaListaPerNVolte(banca* head,int volte);
void contaContiMaggioriDiTot(banca* head,float denaro);

banca* caricaFile(char* strFile,banca* head,int* id)
{
    FILE *fp;
    char str[MAX_NOME + MAX_NOME + 10];
    char* campo;

    fp = fopen(strFile, "r");
    if (fp == NULL) {
        return NULL;
    }
    while(!feof(fp))
        {
            banca* newNode = (banca*)malloc(sizeof(banca));
            if(!feof(fp))
            {
                fgets(str, sizeof(str), fp);
                newNode->id_Nodo = *(id)+=1;
                newNode->next = head;
                campo = strtok(str, "#");
                strcpy(newNode->Nome, campo);
                campo = strtok(NULL, "#");
                strcpy(newNode->Cognome, campo);
                campo = strtok(NULL, "#");
                newNode->denaroTot = atof(campo);

                head = newNode;
            }
        }
        fclose(fp);

    return head;
}



char ScriviMenu()
{
    char sc;

    system("cls");
    printf("MENU' PREPARAZIONE ALLA VERIFICA LISTE\n");
    printf("a - Inserisci un nuovo nodo in testa\n");
    printf("b - Inserisci un nuovo nodo in coda\n");
    printf("c - Inserisci un nuovo nodo data la pos\n");
    printf("d - Visualizza Lista\n");
    printf("e - Elimina nodo in testa\n");
    printf("f - Elimina nodo in coda\n");
    printf("g - Elimina nodo data la posizione\n");
    printf("h - Conta il numero di nodi della lista\n");
    printf("i - Swap\n");
    printf("j - Ordina in base all'id\n");
    printf("k - Trova il conto con piu' denaro\n");
    printf("l - Concatena due liste(NON PERFETTO)\n");
    printf("m - Moltiplica la lista per n volte(NON VA)\n");
    printf("n - Conta quanti conti superano un tot di denaro inserito in input\n");
    printf("q - Esci\n");
    printf("Scelta: ");
    sc = getchar();
//  scanf("%c",&sc);
    fflush(stdin);

    return sc;
}

banca* inserisciInTesta(banca* head,int *id_Nodo)
{
    banca* newNode;

    newNode = (banca*)malloc(sizeof(banca));
    newNode->next = head;
    newNode->id_Nodo = *(id_Nodo)+=1;

    fflush(stdin);
    printf("Inserisci il nome: ");
    gets(newNode->Nome);

    fflush(stdin);
    printf("Inserisci il cognome: ");
    gets(newNode->Cognome);

    printf("Inserisci il denaro depositato: ");
    scanf("%f",&(newNode->denaroTot));

    printf("Conto aggiunto correttamnete\n");

    return newNode;
}

banca* inserisciInCoda(banca* head,int* id)
{
    banca* nodo = head;
    if(nodo==NULL)
        return inserisciInTesta(nodo, id);
    while(nodo->next!=NULL)
        nodo=nodo->next;

    nodo->next=inserisciInTesta(NULL, id);
    return head;
}

banca* inserisciInPos(banca* head, int pos, int* id)
{
    int numNodi= contaNodi(head);
    if(pos == 1 )
        return inserisciInTesta(head,id);
    else if(pos==(numNodi+1))
        return inserisciInCoda(head,id);
    else if(pos>numNodi || pos<=0)
    {
        printf("Non \212 possibile aggiumgere in pos %d",pos);
        return head;
    }
    else
    {
        banca* nodo;
        nodo = head;
        for (int i = 1; i < pos - 1; i++)
        {
            nodo = nodo->next;
        }
        banca* aus = nodo->next;

        nodo->next=inserisciInTesta(aus,id);
        return head;
    }
}


void visualizzaLista(banca* nodo)
{
    while(nodo!=NULL)
    {
        printf("Id: %d\n",nodo->id_Nodo);
        printf("Nome: %s\n",nodo->Nome);
        printf("Cognome: %s\n",nodo->Cognome);
        printf("Denaro depositato: %.2f\n\n",nodo->denaroTot);
        nodo=nodo->next;
    }
    printf("NULL\n");
}

banca* eliminaNodoInTesta(banca* head)
{
    if(head==NULL)
    {
        printf("Lista vuota!Inserire qualche elemento per poter cancellare!");
        getchar();
        fflush(stdin);
        return head;
    }
    else
    {
        banca* aus;
        aus=head->next;
        printf("Cancellando il nodo %d",head->id_Nodo);
        free(head);
        return aus;
    }
}

banca* eliminaNodoInCoda(banca* head)
{
    if(head==NULL)
    {
        printf("Lista vuota!Inserire qualche elemento per poter cancellare!");
        return head;
    }
    else
    {
        if(head->next==NULL)
            return eliminaNodoInTesta(head);
        else
        {
            banca* node;
            node = head;
            while(node->next->next!=NULL)
                node=node->next;
            printf("Cancellando il nodo %d",node->next->id_Nodo);
            free(node->next->next);
            node->next=NULL;
            return head;
        }
    }
}

banca* eliminaNodoInPos(banca* head,int pos)
{
    if(head==NULL)
    {
        printf("Lista vuota!Inserire qualche elemento per poter cancellare!");
        return head;
    }
    else
    {
        int numNodi = contaNodi(head);
        if(pos<=0 || pos>numNodi)
        {
            printf("Non \212 presente nessun nodo in pos %d",pos);
            return head;
        }
        else if(pos==1)
            return eliminaNodoInTesta(head);
        else if(pos==numNodi)
            return eliminaNodoInCoda(head);
        else
        {
            banca* nodo = head;
            for (int i = 1; i < pos - 1; i++)
            {
                nodo = nodo->next;
            }

            banca* aus = nodo->next;
            nodo->next = aus->next;
            printf("Cancellando il nodo %d\n", aus->id_Nodo);
            free(aus);

            return head;
        }
    }
}

int contaNodi(banca* head)
{
    int cont=1;
    if(head==NULL)
    {
        cont--;
        return cont;
    }
    else
    {
        while(head->next!=NULL)
        {
            cont++;
            head=head->next;
        }
    }
    return cont;
}

banca* swap(banca* primo)
{
    if(contaNodi(primo)<2)
    {
        printf("Impossibile eseguire la swap!");
        return primo;
    }
    else
    {
//        banca* secondo;
//        banca* terzo;
//
//        secondo=primo->next;
//        terzo=secondo->next;
//
//        primo->next=terzo;
//        secondo->next=primo;
//
//        return secondo;

        banca* secondo;

        secondo=primo->next;

        primo->next=secondo->next;
        secondo->next=primo;

        return secondo;
    }
}

banca* ordinaInBaseId(banca* head)
{
    if (head == NULL || head->next == NULL) {
        printf("Impossibile eseguire l'ordinamento!");
        return head;
    }

    int swapped;
    do {
        swapped = 0;
        banca* current = head;
        banca* prev = NULL;

        while (current != NULL && current->next != NULL) {
            //Dal più piccolo al più grande
            if (current->id_Nodo > current->next->id_Nodo) {
                if (prev == NULL) {
                    head = swap(head);
                } else {
                    prev->next = swap(current);
                }
                swapped = 1;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);

    return head;
}

void trovaContoConPiuDenaro(banca* head)
{
    if(head==NULL)
    {
        printf("Lista vuota!Impossibile trovare il conto con piu' denaro");
    }
    else
    {
        float max = -100;
        char nome[MAX_NOME],cognome[MAX_NOME];
        while(head!=NULL)
        {
            if(head->denaroTot > max)
            {
                max = head->denaroTot;
                strcpy(nome,head->Nome);
                strcpy(cognome,head->Cognome);
            }
            head=head->next;
        }
        printf("Il conto con piu' denaro \212 il conto di %s %s con %.2f euro",nome,cognome,max);
    }
}

banca* concatenaListe(banca* head, banca2* headLista2,int* id)
{

    if(head==NULL && headLista2 == NULL)
    {
        printf("Impossibile concatenare due liste vuote!");
        return head;
    }
    else if(head==NULL)
    {
        return headLista2;
    }
    else if(headLista2==NULL)
    {
        return head;
    }
    else
    {
        banca* head1;
        banca* head2;

        head2=headLista2;
        head1=head;


        while(head1->next!=NULL)
            head1=head1->next;
        head1->next=head2;
        while(head2!=NULL)
        {
            *(id)+=1;
            head2->id_Nodo=*(id);
            head2=head2->next;
        }
        printf("Concatenamento correttamente eseguito!");
        return head;
    }
}

banca* moltiplicaListaPerNVolte(banca* head,int volte)
{
    if (volte == 1) {
        return head;
    }
    else if(volte==0)
        return NULL;
    else if(volte<0)
    {
        printf("Impossibile moltiplicare la lista per un numero negativo");
        return head;
    }
    else
    {
        banca* headNew;
        headNew=head;

        for(int i = 0; i < volte;i++)
        {
            while(headNew->next!=NULL)
                headNew=headNew->next;
            headNew->next=head;
        }
        return headNew;
    }
}

void contaContiMaggioriDiTot(banca* head,float denaro)
{
    if(head==NULL)
    {
        printf("Lista vuota!Impossibile contare i conti con denaro maggiore a %.2f",denaro);
    }
    else
    {
        int cont = 0;
        int numNodi = contaNodi(head);
        while(head!=NULL)
        {
            if(head->denaroTot > denaro)
                cont++;
            head=head->next;
        }
        printf("I conti con denaro maggiore a %.2f sono %d",denaro,cont);
    }
}


#endif // LIBBANCA_H_INCLUDED
