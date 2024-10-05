#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//caricare FOTO .bmp

//typedef unsigned char byte; //prendi il tipo unsigned char e chiamalo byte (unsigned char senza niente)

#define WIDTH 5000
#define HEIGHT 5000

struct pixel{
    int R;
    int G;
    int B;
};

//void resize(struct pixel* img);

int main()
{
    int c;
    int s_p; //puntatore stack
    const char* h_p; //puntatore heap
    s_p = &c;
    h_p = (int*) malloc(sizeof(int)*300 /*in byte*/); //sintassi più pulita di tutte
    //malloc(5*1024*1024); //byte -> kilobyte -> megabyte

    printf("%p, %p \n", s_p, h_p);
    h_p++;
    printf("%p, %p \n", s_p, h_p);

    /*
    struct pixel immagine[WIDTH][HEIGHT];
    resize(immagine);
    */
    return 0;
}
