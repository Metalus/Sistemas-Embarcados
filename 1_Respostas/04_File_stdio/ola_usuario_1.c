#include <stdio.h>
#include <string.h>

int main(void)
{
    int idade;
    char arquivo[40];
    char nome[40];

    printf("Digite o seu nome: ");
    scanf("%s",arquivo);
    printf("Digite a sua idade: ");
    scanf("%d",&idade);

    strcpy(nome,arquivo);
    strcat(arquivo,".txt");
    FILE* f;
    if(f = fopen(arquivo,"w"))
    {
        fprintf(f,"Nome: %s\nIdade: %d\n",nome,idade);
        fclose(f);
    }

    return 0;
}
