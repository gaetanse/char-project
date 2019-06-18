#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "librairies.h"
#include "temps.h"

class explosion
{
public:
	explosion(int nb);
	~explosion();

	void transfere(sf::Vector2f pos) {
		if (id) {
			sprite.setColor(sf::Color::Black);
			sprite.setScale(4, 4);
			sprite.setPosition(pos);
			sprite.setOrigin(sf::Vector2f(40, 40));
		}
		else {
		sprite.setScale(1, 1);
		sprite.setPosition(pos);
		sprite.setOrigin(sf::Vector2f(40, 40));
		}
	}

	bool animation() {
 		if (destruction.Wait_Temps(0.5)) {
			return true;
		}
		else {
			x++;
			if (x > 10) {
				x = 0;
				y++;
				if (y > 10) {
					y = 0;
				}
			}
			sprite.setTextureRect(sf::IntRect(x, y, 80, 80));
			return false;
		}
			
	}

	void donner_texture(sf::Texture& texture) {
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 80, 80));
	}

	void affichage(sf::RenderWindow& window) {
		window.draw(sprite);
	}

private:

	int id = 0;
	int x, y = 0;
	temps destruction;
	sf::Sprite sprite;

};

#endif // MUNITION_H
