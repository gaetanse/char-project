#include "../include/config.h"

#define nom "config.txt"

config::config()
{
	std::ifstream fichier(nom, std::ios::in); 
	if (fichier)
	{
		lire();
	}
	else
		creer();
}

void config::creer(){}
void config::lire() {}
std::string config::info(int nb) {
	if (nb < infos.size())
		return infos.at(nb); 
}

config::~config()
{
	//dtor
}

