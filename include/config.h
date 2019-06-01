#ifndef CONFIG_H
#define CONFIG_H

#include "librairies.h"

class config
{
public:

	config();
	~config();

	void creer();
	void lire();
	std::string info(int nb);

private:

	std::vector<std::string>infos;

};

#endif // MUNITION_H
