#include "../include/explosion.h"

explosion::explosion(sf::Vector2f pos)
{
	sprite.setScale(1, 1);
	sprite.setPosition(pos);
	sprite.setOrigin(sf::Vector2f(40, 40));
}

explosion::~explosion()
{
	//dtor
}
