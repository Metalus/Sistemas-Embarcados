#include <iostream>
#include <alpr.h>
using namespace std;
int main(int argc, char *argv[])
{
	alpr::Alpr openalpr("eu");
	auto placas = openalpr.recognize(argv[1]).plates[0];
	for (auto placa : placas.topNPlates)
		printf("Placa: %s\n", placa.characters.c_str());
	
	return 0;
}
