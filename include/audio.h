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

private:

	std::vector<sf::Sound>liste_chemin;
	std::vector<sf::SoundBuffer>best_chemin;

};

#endif // BOT_H
