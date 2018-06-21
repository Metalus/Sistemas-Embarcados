#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <wiringPi.h>

#define ECHO 21
#define TRIGGER 22



void ctrl_c()
{
        printf("\n Fechando o programa! \n");
        exit(0);
}

float medir_distancia(void)
{
        clock_t init, fim;
        double duracao = 0;
        double distancia =0;

        digitalWrite(TRIGGER, 1);
        delay(1);
        digitalWrite(TRIGGER, 0);

        init = clock();
        fim = clock();

        while((digitalRead(ECHO)) == 0)
        {
                init = clock();
        }

        while((digitalRead(ECHO)) == 1)
        {

                fim = clock();
	}
        duracao = ((double) (fim-init))/(CLOCKS_PER_SEC);

        distancia = (duracao*34300)/2;

//      printf("%d \n", distancia);

        return distancia;
}

int main()
{
        float distancia = 0.0;
        double d;

        signal(SIGINT, ctrl_c);

        wiringPiSetup();
        pinMode(TRIGGER, OUTPUT);
        pinMode(ECHO, INPUT);
        while(1)
        {
                d = medir_distancia();
                printf("%lf \n", d);
                delay(100);
        }

        return 0;
}
