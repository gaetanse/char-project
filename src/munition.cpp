#include "../include/munition.h"

munition::munition(int speed)
{
    sprite.setScale(0.75,0.75);
    sprite.setOrigin(sf::Vector2f(7.5,7.5));
	if (speed == 99) {
		this->speed = 650;

	}
	else if(speed == 0)
		this->speed = 650;
	else if (speed == 1)
		this->speed = 750;
	else if (speed == 2) {
		this->speed = 850;
	}


}

munition::~munition()
{
    //dtor
}
