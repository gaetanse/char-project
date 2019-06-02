#include "../include/config.h"

#define nom "config.txt"

config::config()
{
	std::ifstream fichier(nom, std::ios::in); 
	if (fichier)
	{
		lectureTotal();
		lectureTrier();
		existe = true;
	}
	else
		creer();
}

void config::creer(){
	std::ofstream fichier(nom, std::ios::out | std::ios::trunc);
	if (fichier)
	{
		fichier << "audio : 25" << std::endl;
		fichier << "musique : 25";
		fichier.close();
	}
}

void config::creer_v2() {
	std::ofstream fichier(nom, std::ios::out | std::ios::trunc);
	if (fichier)
	{
		for (int a = 0; a < _infos.size(); a++) {
			fichier << _infosT2.at(a) << _infosT.at(a);
			if (a < _infos.size() - 1)
				fichier << std::endl;
		}
		fichier.close();
	}
}

void config::lectureTrier() {

	for (int a = 0; a < _infos.size(); a++) {
		std::size_t found = _infos.at(a).find(":");
		if (found != std::string::npos) {

			std::string test = _infos.at(a);
			test.erase(0, 0 + found + 2);
			_infosT.push_back(test);


			std::string test2 = _infos.at(a);
			test2.erase(found, test2.size());
			std::string test3 = ": ";
			test2 += test3;
			_infosT2.push_back(test2);

		}
	}

}

void config::lectureTotal() {

	std::ifstream fichier(nom, std::ios::in);
	if (fichier.is_open())
	{
		std::string ligne;
		while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
		{
			_infos.push_back(ligne);
		}
		fichier.close();
	}

}

config::~config()
{
	//dtor
}

