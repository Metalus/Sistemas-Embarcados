#include <stdio.h>

int main(int argc, char** argv)
{
    char nome[40];
    int i;
    printf("Argumentos: ");
    if(argc>=2)
    {
        for(i = 1; i < argc; i++)
            printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}
