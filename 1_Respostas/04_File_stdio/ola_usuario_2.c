
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int idade;
    char arquivo[40];
    char nome[40];

    if(argc >=2)
    {
        strcpy(arquivo, argv[1]);
        idade = atoi(argv[2]);
        strcpy(nome,arquivo);
        strcat(arquivo,".txt");
        FILE* f;
        if(f = fopen(arquivo,"w"))
        {
            fprintf(f,"Nome: %s\nIdade: %d\n",nome,idade);
            fclose(f);
        }
    }
    return 0;
}
