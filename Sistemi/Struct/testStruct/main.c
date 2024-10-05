#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    char c;
    int* p;
} t_struct;

/*
struct def_struct
{
    int n;
    char c;
    int* p;
};
*/

void assegnaStruct(t_struct* my_s);

int main()
{

    int x;
    //struct def_struct my_struct;

    t_struct my_struct[4];

    assegnaStruct(my_struct);

    printf("%d - %c - %p\n", my_struct[0].n, my_struct[0].c, my_struct[0].p);
    printf("%d - %c - %p\n", my_struct[1].n, my_struct[1].c, my_struct[1].p);
    printf("%d - %c - %p\n", my_struct[2].n, my_struct[2].c, my_struct[2].p);
    printf("%d - %c - %p\n", my_struct[3].n, my_struct[3].c, my_struct[3].p);

    x=5;

    return 0;
}

void assegnaStruct(t_struct* my_s)
{
    /*
    my_s++;
    my_s[0].n ...
    my_s[0].c ...
    my_s[0].p ...

    ATTENZIONE! (non mischiare) perchè così ti trovi al secondo elemento del vettore di struct, perchè 0 sta per saltare di 0 dal puntatore
    */

    int x=8;

    (*my_s).n = 0;    //sintassi uguale
    my_s -> c = 'A';
    my_s -> p = &x;

    my_s++; //salta di 13 byte perchè la struct è grande 13 byte (int = 4 byte + char = 1 byte + puntatore = 8 byte == 13 byte)

    (*my_s).n = 1;
    my_s -> c = 'B';
    my_s -> p = &x;

    my_s++;

    (*my_s).n = 2;
    my_s -> c = 'C';
    my_s -> p = &x;

    my_s++;

    (*my_s).n = 3;
    my_s -> c = 'D';
    my_s -> p = &x;
}
