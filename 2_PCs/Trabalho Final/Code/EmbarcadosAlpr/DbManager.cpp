#include "DbManager.h"

Embarcados::Carro* Embarcados::EncontrarCarro(string Placa)
{
	ifstream arquivo("/home/pi/alpr/" + Placa); 
	if (!arquivo.is_open()) 
		return NULL;

	Carro* c = new Carro;
	c->Placa = Placa;
	getline(arquivo, c->Cor);
	
	arquivo.close();
	return c;
}

inline bool Embarcados::ExisteCarro(string Placa)
{
	struct stat buffer;   
	return (stat(("/home/pi/alpr/" + Placa).c_str(), &buffer) == 0) ; 
}

bool Embarcados::CadastrarCarro(const Carro& c)
{
	if (ExisteCarro("/home/pi/alpr/" + c.Placa)) 
		return false;
	ofstream arquivo("/home/pi/alpr/" + c.Placa);
	arquivo << c.Cor;
	arquivo.close();
	
	return true;
}
