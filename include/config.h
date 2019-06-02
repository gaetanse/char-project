#ifndef CONFIG_H
#define CONFIG_H

#include "librairies.h"

class config
{
public:

	config();
	~config();

	void creer();
	void lectureTotal();
	void lectureTrier();
	void creer_v2();

	bool get_qualite() { return qualite; }
	bool get_existe() { return existe; }

	int get_tailleInfos() { return _infos.size(); }
	std::string get_info(int num) { 
		if(num< _infosT.size())
			return _infosT.at(num); 
	}
	std::string get_infoT(int num) {
		if (num < _infosT.size())
			return _infosT.at(num);
	}
	void set_info(int num, std::string val) {
		if (num < _infosT.size()) {
			_infos.at(num) = val;
			creer_v2();
		}
	}
	void set_infoT(int num, std::string val) {
		if (num < _infos.size()) {
			_infosT.at(num) = val;
			std::cout << "nombre recuperer : " << val << std::endl;
			creer_v2();
		}
	}

	void save(int num);

protected:

private:

	bool qualite = true;
	std::fstream f_config;
	std::vector<std::string>_infos;
	std::vector<std::string>_infosT2;
	std::vector<std::string>_infosT;
	bool existe = false;

};

#endif // MUNITION_H
