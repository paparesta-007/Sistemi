#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

int main()
{
    char my_string[MAX];
    int my_int;

    my_int = 5;
    strcpy(my_string, "TROPPO LUNGA");
    my_string[4]='\0';
    my_string[5]='A';
    my_string[6]='\0';
    my_string[7]='\0';
    printf("%s \n", my_string);
    printf("%d", my_int);
}
