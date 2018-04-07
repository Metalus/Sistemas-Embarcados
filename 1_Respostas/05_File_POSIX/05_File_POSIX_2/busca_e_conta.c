

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc, char** argv)
{
    int size = 0;
    int count = 0;
    char* conteudo;
    if(argc >= 2)
    {
        size = tam_arq_texto(argv[2]);
        conteudo = (char*)malloc(sizeof(char) * size);
        le_arq_texto(argv[2],conteudo);
        while(conteudo = strstr(conteudo, argv[1]))
        {
           count++;
           conteudo++;
        }
        printf("'%s' ocorre %d vezes no arquivo '%s'.\n", argv[1],count,argv[2]);
    }

    return 0;
}


