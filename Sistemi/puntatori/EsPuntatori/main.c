#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void caricaVettore(int *vet, int lunghezza);
void stampaVettore(int *vet, int lunghezza);
void invertiVettore(int *vet,int lunghezza);
void ordinaVettore(int *vet,int lunghezza);
char menu();

int main() {
    int vet[MAX];
    char scelta;

    do {
        scelta = menu();

        switch(scelta) {
            case 'a':
            case 'A':
                caricaVettore(vet, MAX);
                break;
            case 'b':
            case 'B':
                stampaVettore(vet, MAX);
                break;
            case 'c':
            case 'C':
                invertiVettore(vet, MAX);
                stampaVettore(vet, MAX);
                break;
            case 'd':
            case 'D':
                ordinaVettore(vet, MAX);
                break;
            case 'q':
            case 'Q':
                printf("Uscita...\n");
                break; // Aggiunto il break
            default:
                printf("Inserire un valore valido\n");
                break;
        }

        printf("Premere un tasto per continuare...\n");
        getchar(); // Usa getchar() per aspettare un input
    } while(scelta != 'q' && scelta != 'Q');

    return 0;
}

void caricaVettore(int* vet, int len) {
    for(int i = 0; i < len; i++) {
        printf("Inserire il valore del vettore: ");
        scanf("%d", &vet[i]); // Corretto l'uso di &vet[i]
    }
}

void stampaVettore(int *vet, int lunghezza) {
    for(int i = 0; i < lunghezza; i++) {
        printf("%i ", vet[i]); // Stampiamo i valori direttamente
    }
    printf("\n");
}

void invertiVettore(int *vet, int lunghezza) {
    int *p = vet;
    int *p2 = vet + lunghezza - 1;
    int aus;

    while(p < p2) {
        aus = *p;
        *p = *p2;
        *p2 = aus;
        p++;
        p2--;
    }
}

void ordinaVettore(int *vet, int lunghezza) {
    int *i;
    int *j;
    int *posmin;
    int aus;
    for(i = vet; i < vet + lunghezza - 1; i++) {
        posmin = i; // posmin ha l'indirizzo di i
        for(j = i + 1; j < vet + lunghezza; j++) {
            if(*j < *posmin) // Corretto il confronto
                posmin = j;
        }
        if(posmin != i) {
            aus = *i;
            *i = *posmin;
            *posmin = aus;
        }
    }
}

char menu() {
    char s;
    system("cls");
    printf("a. Carica vettore\n");
    printf("b. Stampa vettore\n");
    printf("c. Inverti vettore\n");
    printf("d. Ordina vettore\n");
    printf("Q. Uscita\n");
    printf("Scelta: ");
    s = getchar();
    getchar(); // Consuma il newline rimasto nel buffer
    return s;
}
