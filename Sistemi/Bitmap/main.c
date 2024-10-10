#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define WIDTH 50
#define HEIGHT 50

typedef struct {
    int R;
    int G;
    int B;
}t_pixel;

void colora(t_pixel img[][WIDTH]);
int main()
{
     /// alloco t_pixel in heap
    t_pixel* p_mem;

    p_mem=(t_pixel*) malloc(WIDTH*HEIGHT*sizeof(t_pixel)); //byte -> kilobyte -> megabyte
    printf("%p",*p_mem);
    getchar();

    colora(p_mem);
    p_mem+=WIDTH+1;
    printf("%p\n",p_mem);
    printf("%d\n",p_mem->B);
    printf("%d\n",p_mem->G);



    getchar();
    return 0;
}
void colora(t_pixel img[][WIDTH]){
    int i,j;
    for(i=0;i<HEIGHT;i++){
         for(j=0;j<WIDTH;j++){
            img[i][j].B=255-i;
            img[i][j].G=128-i;
         }

    }
}
