#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <wiringPi.h>

#define STEP 27
#define DIR 25

void ctrl_c()
{
        printf("\n Fechando o programa! \n");
        exit(0);
}

void driver(int control, int passos)
{
        int i =0;
        if(control == 1)
        {
                for(i = 0; i < passos; i++)
                {
                        digitalWrite(DIR, 1);
                        digitalWrite(STEP, 1);
                        delay(1);
                        digitalWrite(STEP, 0);
                        delay(1);
                }
        }
        else
        {
                for(i = 0; i < passos; i++)
                {
                        digitalWrite(DIR, 0);
                        digitalWrite(STEP, 1);
                        delay(1);
                        digitalWrite(STEP, 0);
                        delay(1);
                }
        }

}
int main()
{
        int control = -1;
        int passos = 50;

        signal(SIGINT, ctrl_c);

        wiringPiSetup();
        pinMode(STEP, OUTPUT);
        pinMode(DIR, OUTPUT);

        while(1)
        {
                control = -1;
                printf("Abre (1) e Fecha (0): ");
                scanf("%d", &control);
                printf("%d \n", control);
                driver(control,passos);
        }

        return 0;
}


