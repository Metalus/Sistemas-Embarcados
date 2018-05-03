import RPi.GPIO as GPIO
import time
import signal

GPIO.setmode(GPIO.BCM)

## Definicao dos pinos de saida
STEP = 16
DIR = 26

def setup():
        print("Setando a GPIO...")
        GPIO.setup(STEP,GPIO.OUT)
        GPIO.setup(DIR,GPIO.OUT)
        time.sleep(0.5)
def close():
        GPIO.cleanup()
        print("Fechando programa...")
        time.sleep(0.5)
        exit()


def driver(ligar, direcao):

        if(ligar == 1):
                print("Ligado")
                if(direcao == 1):
                        print("Direita")
                        GPIO.output(DIR, GPIO.HIGH)
                        GPIO.output(STEP, GPIO.HIGH)
                        time.sleep(0.05)
                        GPIO.output(STEP, GPIO.LOW)
                        time.sleep(0.05)

                if(direcao == 0):
                        print("Esquerda")
                        GPIO.output(DIR, GPIO.LOW)
                        GPIO.output(STEP, GPIO.HIGH)
                        time.sleep(0.05)
                        GPIO.output(STEP, GPIO.LOW)
                        time.sleep(0.05)  

        if(ligar == 0):
                print("Desligado")
                GPIO.output(STEP, GPIO.LOW)
                GPIO.output(DIR, GPIO.LOW)


if __name__ == "__main__":
        try:
                setup()
                while(1):
                        Abre = 2
                        Abre = input("Abre: (1) || Fecha: (0) - ")
                        if(Abre == 1):
                                for x in range(1,50):
                                        driver(1,1)
                        else:
                                for x in range(1,50):
                                        driver(1,0)


        # Cancelar  CTRL + C
        except KeyboardInterrupt:
                close()

