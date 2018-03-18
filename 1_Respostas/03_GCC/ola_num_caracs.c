
#include <stdio.h>
#include "num_caracs.h"

int main(int argc, char** argv)
{
    int i;

    if(argc>=2)
    {
        for(i = 0; i < argc; i++)
            printf("Argumento: %s / Numero de caracteres: %d\n",argv[i],Num_Caracs(argv[i]));
    }
    printf("\n");
    return 0;
}
