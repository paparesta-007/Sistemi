#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MAXFIBONACCI 10
#define MAXSTR 15

void caricaVettore(int *vet, int lunghezza);
void stampaVettore(int *vet, int lunghezza);
void invertiVettore(int *vet,int lunghezza);
void ordinaVettore(int *vet,int lunghezza);
void verificaFibonacci(int *vet,int lunghezza);
void invertiStringa(char *str);
void convertiMaiuscoloMinuscolo(char *str);
void concatenaStringhe(char *str, char *str2, char *str3);
void cifraturaCesare(char *str);
void visualizzaRicorrenze(char *str);
char menu();

int main() {
    int vet[MAX];
    int vetFibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    char str[MAXSTR];
    char str2[MAXSTR]="Stringa";
    char strConcat[MAXSTR*2];
    char scelta;

    do {
        scelta = menu();

        switch(scelta) {
            case 'a':
            case 'A':
                caricaVettore(&vet, MAX);
                break;
            case 'b':
            case 'B':
                stampaVettore(&vet, MAX);
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
            case 'e':
            case 'E':

                verificaFibonacci(vetFibonacci,MAXFIBONACCI);
                break;
            ///////////////////////////////////////
            case 'f':
            case 'F':
                printf("Inserisci una stringa: ");
                gets(str);
                break;
            case 'g':
            case 'G':
                printf("Stringa: %s\n",str);

                break;
            case 'h':
            case 'H':
                invertiStringa(str);
                printf("Stringa invertita: %s\n",str);
                break;
            case 'i':
            case 'I':
                convertiMaiuscoloMinuscolo(str);
                printf("Stringa: %s\n",str);
                break;
            case 'j':
            case 'J':
                concatenaStringhe(str,str2,strConcat);
                printf("Stringa concatenata: %s\n",strConcat);
                break;
            case 'k':
            case 'K':
                cifraturaCesare(str);
                printf("Stringa cifrata: %s",str);
                break;
            case 'l':
            case 'L':
                //printf("prova");
                visualizzaRicorrenze(str);
                break;
            case 'q':
            case 'Q':
                printf("Uscita...\n");
                break; // Aggiunto il break
            default:
                printf("Inserire un valore valido\n");
                break;
        }

       printf("\n\033[1;33mPremere un tasto per continuare\033[0m");
        getchar();
    } while(scelta != 'q' && scelta != 'Q');

    return 0;
}

void caricaVettore(int* vet, int len) {

    int *p=vet;
    while(p<vet+len){
         printf("Inserire il valore del vettore: ");
        scanf("%d", p);
        p++;
    }

}

void stampaVettore(int *vet, int lunghezza) {
     int *p=vet;
    while(p<vet+lunghezza){
         printf("%d ",*p);

        p++;
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
        posmin = i;
        for(j = i + 1; j < vet + lunghezza; j++) {
            if(*j < *posmin)
                posmin = j;
        }
        if(posmin != i) {
            aus = *i;
            *i = *posmin;
            *posmin = aus;
        }
    }
}
void verificaFibonacci(int *vet, int lunghezza){

    int serie=0;
    int *p1=vet;
    int *p2=vet+1;
    int *p3=vet+2;
    while(serie!=1 && p3 < vet + lunghezza){
        if(*p3!=(*p2+*p1)){
            serie=1;
        }
        else
        {
            p1++;
            p2++;
            p3++;
        }

    }
    if(serie==0){
        printf("Il vettore rappresenta una serie di Fibonacci\n");
    }
    else
        printf("Il vettore non rappresenta una serie di Fibonacci\n");

}
void invertiStringa(char *str){
    char aus;
    char *p1=str;
    char *p2=str;
    while(*p2!='\0'){
        p2++;
    }
    p2--;
    while(p1<p2){
        aus=*p1;
        *p1=*p2;
        *p2=aus;
        p1++;
        p2--;
    }
}
void convertiMaiuscoloMinuscolo(char *str){
    char *p=str;
    while(*p!='\0'){
        if(*p<='Z' && *p>='A')
            *p+=32;
        else if(*p<='z' && *p>='a')
            *p-=32;

        p++;
    }

}
void concatenaStringhe(char *str, char *str2, char *str3){
    char *p=str;
    char *p2=str2;
    char *p3=str3;
    while(*p!='\0'){
        *p3=*p;
        p++;
        p3++;
    }
    while(*p2!='\0'){
        *p3=*p2;
        p2++;
        p3++;
    }
    *p3='\0';
}
void cifraturaCesare(char *str){
    char *p=str;

    while(*p!='\0'){
        if(*p>='a' && *p<='z')
        {
            if(*p<='u')
                *p=*p+5;
            else
                *p='a'+(*p-'v');
        }
        else
        {
             if(*p>='A' && *p<='Z'){
                     if(*p<='U')
                *p=*p+5;
            else
                *p='A'+(*p-'V');
             }

        }

        p++;
    }
    str='\0';

}
void visualizzaRicorrenze(char *str){
    char *p=str;

    int alfabeto[26]={};// lungo 26 caratteri, ogni volta che vedo un carattere lo metto nella posizione
    int *p2=alfabeto;

   while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            alfabeto[*p - 'a']++;
        }
        p++;
    }


    while (p2 != alfabeto + 26) {
        if (*p2 != 0) {
           char c = 'a' + (p2 - alfabeto);
            printf("%c: %i\n", c, *p2);
        }
        p2++;
    }
}
char menu() {
    char s;
    system("cls");
    printf("\033[0;31m---Esercizi sui Vettori---\033[0m\n\n");///testo rosso
    printf("a. Carica vettore\n");
    printf("b. Stampa vettore\n");
    printf("c. Inverti vettore\n");
    printf("d. Ordina vettore\n");
    printf("e. Verifica serie Fibonacci\n");
    printf("\n\033[0;31m---Esercizi sulle stringhe---\033[0m\n\n");
    printf("f. Inserisci una stringa\n");
    printf("g. Stampa una stringa\n");
    printf("h. Inverti stringa\n");
    printf("i. Converti maiuscolo in minuscolo (e viceversa)\n");
    printf("j. Concatena 2 stringhe\n");
    printf("k. Cifratura Cesare (4 lettere)\n");
    printf("l. Visualizzare le ricorrenze\n");
    printf("Q. Uscita\n");
    printf("Scelta: ");
    s = getchar();
    getchar(); // Consuma il newline rimasto nel buffer
    return s;
}
