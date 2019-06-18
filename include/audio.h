#ifndef AUDIO_H
#define AUDIO_H

#include "librairies.h"
#include "temps.h"
#include <vector>

class audio
{
public:

	audio();
	~audio();

	void ajouter_Buffer(std::string files1, std::string files2) {
		if (!l_buffer1.loadFromFile(files1)) {
			std::cout << "erreur chargement du son " << std::endl;
		}
		else {
			test1.setBuffer(l_buffer1);
		}
		if (!l_buffer2.loadFromFile(files2)) {
			std::cout << "erreur chargement du son " << std::endl;
		}
		else {
			test2.setBuffer(l_buffer2);
		}
	}
	void creer_son(int buff) {
		/*
		if (buff >= 0 && buff < 2) {
			if(buff==0)
				test1.play();
			else if(buff==1)
				test2.play();
		}
		*/
	}

	void clear() {
		/*
		test1.stop();
		test2.stop();*/
	}

private:

	float son = 20;
	float musique = 20;
	sf::Sound test1;
	sf::Sound test2;
	sf::SoundBuffer l_buffer1;
	sf::SoundBuffer l_buffer2;

};

#endif // BOT_H
