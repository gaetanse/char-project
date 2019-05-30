#include "../include/bot.h"

#define PI 3.14159265

bot::bot(int id)
{
	numero = id;
    srand (time(NULL));
    sprite.setScale(2,2);
    sprite.setOrigin(sf::Vector2f(15,15));
    sprit_cannon.setScale(2,2);
    sprit_cannon.setPosition(32,32);
    sprit_cannon.setOrigin(sf::Vector2f(15,20));
	if (numero == 0) {
		sprite.setColor(sf::Color::Yellow);
		sprit_cannon.setColor(sf::Color::Yellow);
	}
	else if (numero == 1) {
		sprite.setColor(sf::Color::Green);
		sprit_cannon.setColor(sf::Color::Green);
	}
}

int bot::check_col(sf::Vector2f test) {

	if (test.x > getPosition().x && test.x < getPosition().x + 32) {
		if (test.y > getPosition().y && test.y < getPosition().y + 32) {
			return 1;
		}
	}

}

sf::Vector2f bot::orentation() { return sprit_cannon.getPosition(); }

void bot::donner_texture(sf::Texture& texture) {
	sprite.setTexture(texture);
}
void bot::donner_texture_2(sf::Texture& texture) {
	sprit_cannon.setTexture(texture);
}

int bot::getX() { return x; }
int bot::getY() { return y; }

void bot::spawn() {

	x = rand() % 30;
	y = rand() % 17;

	sprite.setPosition(sf::Vector2f(x*64+32,y*64+32));

}

bool bot::est_dans_la_liste(int nb) {

	for (int a = 0; a < liste_chemin.size(); a++) {
		if (liste_chemin.at(a) == nb)
			return true;
	}

	return false;

}

int bot::testMapDeCase(int v) {

	if (v == 2)
		v = 3;

	std::cout << v << std::endl;

	return v;

}

bool bot::tirer() {
	if (numero == 0) {
		if (t_reload.Wait_Temps(3.0))
			return true;
		else
			return false;
	}
	else if (numero == 1) {
		return false;
	}
}
sf::Vector2f bot::getPosition(){
    return sprite.getPosition();
}
void bot::tournerLeViseur(sf::Vector2f LeVector){
            float result = atan2 ( LeVector.y-sprit_cannon.getPosition().y , LeVector.x-sprit_cannon.getPosition().x ) * 180 / PI + 90;
            sprit_cannon.setRotation(result);
}
void bot::affichage(sf::RenderWindow &window){

window.draw(sprite);
sprit_cannon.setPosition(sprite.getPosition().x-1,sprite.getPosition().y);
window.draw(sprit_cannon);

}

void bot::diriger_canon(sf::Vector2i position){
    float result = atan2 ( position.y-sprit_cannon.getPosition().y , position.x-sprit_cannon.getPosition().x ) * 180 / PI + 90;
    sprit_cannon.setRotation(result);
}

bot::~bot()
{
    //dtor
}
