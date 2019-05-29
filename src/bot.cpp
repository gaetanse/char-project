#include "../include/bot.h"

#define PI 3.14159265

bot::bot()
{
    srand (time(NULL));
    sprite.setScale(2,2);
    sprite.setOrigin(sf::Vector2f(15,15));
    sprit_cannon.setScale(2,2);
    sprit_cannon.setPosition(32,32);
    sprit_cannon.setOrigin(sf::Vector2f(15,20));
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

void bot::deplace(float temps_recup) {



	for (int a = dejafait; a < path.pathOk().size(); a++) {
		if (path.pathOk().at(a) == 1) {
			sprite.move(-1 * temps_recup * 5, 0);
			if (t_anime.Wait_Temps(1) == 1) {
				dejafait++;
			}
		}
		else if (path.pathOk().at(a) == 2) {
			if (t_anime.Wait_Temps(1) == 1) {
				sprite.move(1 * temps_recup * 5, 0);
				if (t_anime.Wait_Temps(1) == 1) {
					dejafait++;
				}
			}
		}
		else if (path.pathOk().at(a) == 3) {
			sprite.move(0, -1 * temps_recup * 5);
			if (t_anime.Wait_Temps(1) == 1) {
				dejafait++;
			}
		}
		else if (path.pathOk().at(a) == 4) {
			sprite.move(0, 1 * temps_recup * 5);
			if (t_anime.Wait_Temps(1) == 1) {
				dejafait++;
			}
		}
		//sprite.move();
	}




	///parcourir le bon chemin


}

void bot::cherche_joueur(sf::Vector2f joueur, la_map Map) {

	///trouver un chemin vers le joueur
	///tous les blocks vide
	int num = 0;
	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 30; x++) {
			if (Map.get_block_2(y, x) == 1) {
				///push_back les positions
				liste_chemin.push_back(num);
			}
			num++;
		}
	}

	///pos du bot
	int case_de_depart = Map.get_num(getPosition());
	int case_de_fin = Map.get_num(joueur);

	path.debut(case_de_depart, case_de_fin, liste_chemin);

	///trouver le plus rapide parmis les blocks vide
/*
		int depart=0;
		int case_=0;
		for(int nb=0;nb<liste_chemin.size();nb++){
			///pour chaque case il faut compter le nombre de x et

			nb_chemin.push_back(0);
			case_=liste_chemin.at(nb);

			if(est_dans_la_liste(case_-1)){
				std::cout << "-1 : oui" << std::endl;
			}
			if(est_dans_la_liste(case_+1)){
				std::cout << "+1 : oui" << std::endl;
			}
			if(est_dans_la_liste(case_-10)){
				std::cout << "-10 : oui" << std::endl;
			}
			if(est_dans_la_liste(case_+10)){
				std::cout << "+10 : oui" << std::endl;
			}

		}*/
		///ecrire la best soluce

}

void bot::spawn() {


	x = rand() % 30;
	y = rand() % 17;

	std::cout << x << " / " << y << std::endl;

	sprite.setPosition(sf::Vector2f(x * 32, y * 32));


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

	if (t_reload.Wait_Temps(3.0) == 1)
		return true;

	return false;

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
