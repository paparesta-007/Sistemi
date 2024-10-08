#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 21 // 20 characters + 1 for the null terminator

typedef struct {
    char nome[MAX];
    char cognome[MAX];
    int eta;
    int debito; // Assuming this is the intended field for the user's debt
} Persona;

void caricaUtenti(Persona *utenti, int *nUtenti);
void stampaUtenti(Persona *utenti, int nUtenti);
void ordinamento(Persona *utenti,int nUtenti);
void modificaUtente(Persona *utenti,int nUtenti);
char menu();

int main() {
    char scelta;
    Persona utenti[5]; // Array to hold up to 5 users
    int nUtenti = 0;   // Current number of users

    do {
        scelta = menu();

        switch (scelta) {
            case 'a':
            case 'A':
                caricaUtenti(utenti, &nUtenti); // Pass the address of nUtenti
                break;
            case 'b':
            case 'B':
                stampaUtenti(utenti, nUtenti);
                break;
            case 'c':
            case 'C':
                ordinamento(utenti,nUtenti);
                break;
            case 'd':
            case 'D':
                modificaUtente(utenti,nUtenti);
                break;
            case 'q':
            case 'Q':
                printf("Uscita...\n");
                break;
            default:
                printf("Inserire un valore valido\n");
                break;
        }

        printf("\n\033[1;33mPremere un tasto per continuare\033[0m");
        getchar(); // Consume the newline character
    } while (scelta != 'q' && scelta != 'Q');

    return 0;
}

char menu() {
    char s;
    system("cls");
    printf("\033[0;31m---Esercizi sui Vettori---\033[0m\n\n");
    printf("a. Carica vettore\n");
    printf("b. Stampa tutti\n");
    printf("c. Ordina in base al debito\n");
    printf("q. Uscita\n");
    printf("Scelta: ");
    s = getchar();
    getchar(); // Consume the newline character
    return s;
}

void caricaUtenti(Persona *utenti, int *len) {
    if (*len < 5) {
        Persona *current = utenti + *len;
        printf("Inserisci nome: ");
        scanf("%s", current->nome);
        printf("Inserisci cognome: ");
        scanf("%s", current->cognome);
        printf("Inserisci eta: ");
        scanf("%d", &current->eta);
        printf("Inserisci debito: ");
        scanf("%d", &current->debito);

        (*len)++;
        getchar();
    } else {
        printf("Massimo numero di utenti raggiunto.\n");
    }
}

void stampaUtenti(Persona *utenti, int nUtenti) {
    printf("\nElenco degli utenti:\n");
    Persona *current = utenti;
    int count = 0;

    while (count < nUtenti) {
        printf("Nome: %s\n", current->nome);
        printf("Cognome: %s\n", current->cognome);
        printf("Eta: %d\n", current->eta);
        printf("Debito: %d\n\n", current->debito);

        current++;
        count++;
    }
}
void ordinamento(Persona *utenti,int nUtenti){
    Persona *i;
    Persona *j;
    Persona *posmin;
    for(i=utenti;i<=utenti+nUtenti-1;i++){
        posmin=i;
        for(j=i+1;j<=utenti+nUtenti;j++){
            if (j->debito < posmin->debito) {
                posmin = j; // Find the minimum debito
            }
        }
        if(posmin!=i){
            scambio(i,posmin);
        }
    }
}
void scambio(Persona *a, Persona *b) {
    Persona aus = *a; // Crea una copia di a
    *a = *b;           // Copia b in a
    *b = aus;        // Copia il valore temporaneo in b

}
void modificaUtente(Persona *utenti, int nUtenti) {
    char cogn[MAX];
    printf("Inserisci cognome dell'utente da modificare: ");
    scanf("%s", cogn);  // Legge il cognome dell'utente da modificare

    Persona *current = utenti;
    while (current < utenti + nUtenti) {
        if (strcmp(current->cognome, cogn) == 0) {  // Confronto stringhe
            // Se l'utente è trovato, permette la modifica dei campi
            printf("Utente trovato. Inserisci nuovi dati.\n");

            printf("Inserisci nuovo nome (%s): ", current->nome);
            scanf("%s", current->nome);  // Modifica il nome

            printf("Inserisci nuovo cognome (%s): ", current->cognome);
            scanf("%s", current->cognome);  // Modifica il cognome

            printf("Inserisci nuova eta (%d): ", current->eta);
            scanf("%d", &current->eta);  // Modifica l'età

            printf("Inserisci nuovo debito (%d): ", current->debito);
            scanf("%d", &current->debito);  // Modifica il debito

            printf("Modifica completata.\n");
            return;  // Esci dalla funzione dopo aver modificato l'utente
        }
        current++;  // Passa al prossimo utente nel vettore
    }

    printf("Utente non trovato.\n");
}

