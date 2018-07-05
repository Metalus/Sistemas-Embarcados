
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned char byte;

namespace Embarcados
{
	typedef struct
	{
		string Placa;
		string Cor;
		//std::vector<unsigned char> Imagem;
	} Carro;
	
	Carro* EncontrarCarro(string Placa);
	bool ExisteCarro(string Placa);
	bool CadastrarCarro(const Carro& c);
	
}
