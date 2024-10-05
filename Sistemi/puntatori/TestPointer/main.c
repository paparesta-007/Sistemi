#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[10]= "testo di prova";
    short* p_x;  //int = capire solo grandezza | * = puntatore

    //short = 2 byte

    printf("Valore: %c, Posizione: %p\n",x[0], &x);

    p_x = &x;

    printf("Valore: %c, Posizione: %p\n",*p_x, p_x);

    p_x++;

    printf("Valore: %c, Posizione: %p\n",*p_x, p_x);

    return 0;
}
