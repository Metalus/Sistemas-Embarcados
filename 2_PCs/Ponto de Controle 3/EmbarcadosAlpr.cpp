#include <alpr.h>
#include <string.h>
#include <raspicam/raspicam_cv.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wiringPi.h>
#include <algorithm>
#include <iostream>
#include <pthread.h>
#include <sched.h>

#include "DbManager.h"

#define STEP 27
#define DIR 25
#define PASSOS 50

#define ECHO 21
#define TRIGGER 22

using namespace std;
bool Continuar;
alpr::Alpr openalpr("br");
raspicam::RaspiCam_Cv Camera;

float medir_distancia(void);
void InitUltra();
void InitDriver();
void driver(int control, int passos);
bool ValidarPlacas(vector<alpr::AlprPlate>& placas);
void* ScanPlate(void* arg);

int main(int argc, char *argv[])
{
	cout << "Carregando câmera" << endl;
//	if (!Camera.open())
//		cerr << "Erro ao abrir câmera" << endl;
//	else
//		cout << "Câmera carregada" << endl;
	   /**Sets a property in the VideoCapture. 
	 * 
	 * 
	 * Implemented properties:
	 * cv::CAP_PROP_FRAME_WIDTH,cv::CAP_PROP_FRAME_HEIGHT,
	 * cv::CAP_PROP_FORMAT: CV_8UC1 or CV_8UC3
	 * cv::CAP_PROP_BRIGHTNESS: [0,100]
	 * cv::CAP_PROP_CONTRAST: [0,100]
	 * cv::CAP_PROP_SATURATION: [0,100]
	 * cv::CAP_PROP_GAIN: (iso): [0,100]
	 * cv::CAP_PROP_EXPOSURE: -1 auto. [1,100] shutter speed from 0 to 33ms
     * cv::CAP_PROP_WHITE_BALANCE_RED_V : [1,100] -1 auto whitebalance
     * cv::CAP_PROP_WHITE_BALANCE_BLUE_U : [1,100] -1 auto whitebalance
     * cv::CAP_PROP_MODE : [1,7] 0 auto mode
     *
         */
//	Camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
//	Camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	
	cout << "Iniciando driver para o motor e ultrassom" << endl;
	driver(0, PASSOS);
	wiringPiSetup();
	InitDriver();
	InitUltra();
	
	pthread_attr_t tattr;
	pthread_t tid;
	int ret;
	int newprio = 20;
	sched_param param;
	Continuar = true;
	pthread_attr_init(&tattr);
	pthread_attr_getschedparam(&tattr, &param);
	param.sched_priority = newprio;
	pthread_attr_setschedparam(&tattr, &param);
	pthread_create(&tid, &tattr, ScanPlate, NULL); 
	cout << "Pressione qualquer tecla para fechar" << endl;
	getchar();
	Continuar = false;
	pthread_join(tid, NULL);
	return 0;
}

void* ScanPlate(void* arg)
{
	openalpr.setTopN(3); // Pegar 3 placas
	cv::Mat image;
	for (; Continuar;)
	{
		cout << "Distancia: " << medir_distancia() << endl;
		if (medir_distancia() > 10)
			continue;
		cout << "Tirando foto do veiculo" << endl;
		Camera.grab();
		Camera.retrieve(image);

		vector<uchar> buffer;
		cv::imencode(".jpg", image, buffer);
		auto placas = openalpr.recognize(vector<char>(buffer.begin(), buffer.end()));
		
		
		
		if (placas.plates.size() == 0) 
			continue;
		
		if (ValidarPlacas(placas.plates[0].topNPlates))
		{
			cout << "Placa encontrada, abrindo cancela" << endl;
			driver(1, PASSOS);
			sleep(1);
			while (medir_distancia() < 10)
			{
				sleep(1);
				cout << "Esperando carro passar" << endl;
			}
			driver(0, PASSOS);
		}
		else
			cout << "Placa não cadastrada" << endl;
		
	}
	
	Camera.release();
	return NULL;
}

bool ValidarPlacas(vector<alpr::AlprPlate>& placas)
{
	vector<string> str_placas;
	transform(placas.begin(),
		placas.end(), 
		back_inserter(str_placas),
		[](const alpr::AlprPlate& placa) { return placa.characters; });
	
	for (auto placa : str_placas)
	{
		//Verificar se há letras no lugar de números na placa
		if (find_if(placa.begin() + 3, placa.end(), [](char c) { return !isdigit(c); }) != placa.end())
		{
			replace(placa.begin() + 3, placa.end(), 'I', '1');
			replace(placa.begin() + 3, placa.end(), 'B', '8');
			replace(placa.begin() + 3, placa.end(), 'S', '5');
			replace(placa.begin() + 3, placa.end(), 'O', '0');
		}
		cout << "Placa: " << placa << endl;
		if (Embarcados::ExisteCarro(placa))
		{

			return true;
		}

	}

	return false;
}

float medir_distancia(void)
{
	clock_t init, fim;
	double duracao = 0;
	double distancia = 0;

	digitalWrite(TRIGGER, 1);
	delay(1);
	digitalWrite(TRIGGER, 0);

	init = clock();
	fim = clock();

	while ((digitalRead(ECHO)) == 0)
	{
		init = clock();
	}

	while ((digitalRead(ECHO)) == 1)
	{

		fim = clock();
	}
	duracao = ((double)(fim - init)) / (CLOCKS_PER_SEC);

	distancia = (duracao * 34300) / 2;

	//      printf("%d \n", distancia);

	return distancia;
}

void InitUltra()
{
	float distancia = 0.0;
	double d;

	pinMode(TRIGGER, OUTPUT);
	pinMode(ECHO, INPUT);
}

void InitDriver()
{
	pinMode(STEP, OUTPUT);
	pinMode(DIR, OUTPUT);
}

void driver(int control, int passos)
{
	int i = 0;
	if (control == 1)
	{
		for (i = 0; i < passos; i++)
		{
			digitalWrite(DIR, 1);
			digitalWrite(STEP, 1);
			delay(10);
			digitalWrite(STEP, 0);
			delay(1);
		}
	}
	else
	{
		for (i = 0; i < passos; i++)
		{
			digitalWrite(DIR, 0);
			digitalWrite(STEP, 1);
			delay(10);
			digitalWrite(STEP, 0);
			delay(1);
		}
	}

}
