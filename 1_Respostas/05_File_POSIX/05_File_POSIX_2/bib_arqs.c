#include "bib_arqs.h"


void le_arq_texto(char *nome_arquivo, char *conteudo)
{
    int fp = open (nome_arquivo, O_RDONLY);
    read(fp,conteudo,tam_arq_texto(nome_arquivo));
    close(fp);
}

int tam_arq_texto(char *nome_arquivo)
{
    struct stat st;
    stat(nome_arquivo, &st);
    return st.st_size;
}
