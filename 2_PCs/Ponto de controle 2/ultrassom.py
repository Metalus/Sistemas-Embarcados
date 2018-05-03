## Bibliotecas
import RPi.GPIO as GPIO
import time

## Modo da GPIO
GPIO.setmode(GPIO.BCM)

## Definindo os pinos usados
GPIO_TRIGGER = 6
GPIO_ECHO = 5

## Definindo entrada e saida
GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO_ECHO, GPIO.IN)

def med_distancia():
    ## Inicio de pulso sonoro
    GPIO.output(GPIO_TRIGGER, GPIO.HIGH)

    # fim do pulso sonoro
    time.sleep(0.00000001)
    GPIO.output(GPIO_TRIGGER, GPIO.LOW)

    init = time.time()
    fim = time.time()

    # Guardando tempo de inicio
    while GPIO.input(GPIO_ECHO) == 0:
        init = time.time()

    # Guaradando tempo de fim
    while GPIO.input(GPIO_ECHO) == 1:
        fim = time.time()

    # tempo de viagem da onda
    duracao = fim - init

    # Calculo da distancia
    distancia = (duracao * 34300) / 2

    return distancia

def tirar_foto():
        print("FOTO")
        time.sleep(1)

if __name__ == '__main__':
    try:
        while(1):
            x = med_distancia()
            print ("Distancia medida = %.1f cm" % x)
            time.sleep(0.1)
            if(x <= 20):
                tirar_foto();   

        # Cancelar  CTRL + C
    except KeyboardInterrupt:
        print("FIM!")
        GPIO.cleanup()





