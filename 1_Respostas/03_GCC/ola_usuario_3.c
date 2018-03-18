#include <stdio.h>

int main(int argc, char** argv)
{
    char nome[40];
    if(argc>=2)
    {
        printf("Olá %s\n",argv[1]);
        printf("Número de entradas = %d\n", argc);
    }
    return 0;
}
