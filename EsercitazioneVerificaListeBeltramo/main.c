#include "libBanca.h"

int main()
{
    banca* head = NULL;
    banca2* headLista = NULL;
    int id=0;
    int id2=0;
    char scelta;
    int pos;
    float denaro;
    char strFile[MAX_NOME];

//    printf("Inserisci il nome del file: ");
//    gets(strFile);
//    head=caricaFile(strFile, head, &id);

    headLista = caricaFile("file2.txt", headLista, &id2);
    head=caricaFile("file.txt", head, &id);
    if(head==NULL)
    {
        printf("Errore nell'apertura del file\n");
        printf("Premi INVIO per uscire\n");
        getchar();
    }
    else
    {

        do
        {
            scelta=ScriviMenu();
            switch(scelta)
            {
            case 'a':
            case 'A':
                head = inserisciInTesta(head,&id);
                break;
            case 'b':
            case 'B':
                head = inserisciInCoda(head,&id);
                break;
            case 'c':
            case 'C':
                printf("Inserisci la posizione in cui vuoi aggiungere il nodo: ");
                scanf("%d",&pos);
                head = inserisciInPos(head,pos,&id);
                getchar();
                break;
            case 'd':
            case 'D':
                visualizzaLista(head);
                break;
            case 'e':
            case 'E':
                head = eliminaNodoInTesta(head);
                break;
            case 'f':
            case 'F':
                head = eliminaNodoInCoda(head);
                break;
            case 'g':
            case 'G':
                printf("Inserisci la posizione del nodo eliminare: ");
                scanf("%d",&pos);
                head = eliminaNodoInPos(head,pos);
                getchar();
                break;
            case 'h':
            case 'H':
                printf("Il numero di libri memmorizzati \212 %d",contaNodi(head));
                break;
            case 'i':
            case 'I':
                head = swap(head);
                printf("Swap correttamente eseguita");
                break;
            case 'j':
            case 'J':
                head = ordinaInBaseId(head);
                if(head!=NULL && head->next!=NULL)
                {
                    printf("Ordinamento in base all'id correttamente eseguito");
                }
                break;
            case 'k':
            case 'K':
                trovaContoConPiuDenaro(head);
                break;
            case 'l':
            case 'L':
                head = concatenaListe(head,headLista,&id);
                break;
            case 'm':
            case 'M':
                printf("Inserisci per quante volte vuoi moltiplicare la lista: ");
                scanf("%d",&pos);
                head =  moltiplicaListaPerNVolte(head,pos);
                break;
            case 'n':
            case 'N':
                do
                {
                    printf("Inserisci la somma di denaro (maggiore o uguale a 0): ");
                    scanf("%f",&denaro);
                }while(denaro<0);
                contaContiMaggioriDiTot(head,denaro);
                getchar();
                break;
            case 'Q':
            case 'q':
                printf("Grazie per aver utilizzato il programma!");
                break;
            default:
                printf("Inserisci una scelta disponibile!");
                break;
            }
            getchar();
            fflush(stdin);
        }while(scelta!='Q' && scelta!='q');
    }
    return 0;
}
