#include <stdio.h>

int main()
{
    FILE* f;
    if(f = fopen("ola_mundo.txt","w"))
    {
        fprintf(f,"Olá mundo!");
        fclose(f);
    }
    return 0;
}
