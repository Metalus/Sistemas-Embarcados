
#include <stdio.h>
#include <stdlib.h>
#include "bib_args.h"

int main(int argc, char** argv)
{
    int size = 0;
    char* conteudo;
    if(argc >= 2)
    {
        size = tam_arq_texto(argv[1]);
        conteudo = (char*)malloc(sizeof(char) * size);
        le_arq_texto(argv[1],conteudo);
        printf("%s", conteudo);
    }

    return 0;
}
