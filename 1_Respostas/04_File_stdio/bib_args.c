#include "bib_args.h"


int tam_arq_texto(char *nome_arquivo)
{
    FILE *f;
    int sz = 0;
    if(f = fopen(nome_arquivo,"r"))
    {
        fseek(f, 0L, SEEK_END);
        sz = ftell(f);
        fclose(f);
    }
    return sz;
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
    FILE *f;
    int size = 0;
    if(f = fopen(nome_arquivo,"r"))
    {
        size = tam_arq_texto(nome_arquivo);
        fread(conteudo,1,size,f);
        fclose(f);
    }
}
