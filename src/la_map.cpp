#include "../include/la_map.h"
#include "../include/fenetre.h"
#include <fstream>

#define TILE_SIZE 32
#define nbDitems 10

la_map::la_map()
{

}

void la_map::charger_texture(sf::Texture &texture){
    sprite.setTexture(texture);
}

void la_map::generationA() {

	srand(time(NULL));

	for (int y = 0; y < y_taille; y++) {
		for (int x = 0; x < x_taille; x++) {
			set_block(y, x, 1);
		}
	}

	int v1 = rand() % 15+5; ///nombre d'enemies // max 15

	std::vector<int>les_enemies_niv;
	std::vector<int>les_enemies_posX;
	std::vector<int>les_enemies_posY;

	for (int a = 0; a < v1; a++) {
		les_enemies_niv.push_back(rand() % 5); // niv enemies max 4
		les_enemies_posX.push_back(rand() % 28 + 1); // x > && < x
		les_enemies_posY.push_back(rand() % 14 + 2); // y > && < y
	}

	int persoX = rand() % 28 + 1; // perso position
	int persoY = rand() % 14 + 2; // perso position

	set_block(persoY, persoX, 3);

	int v3 = rand() % 20+5; ///nombre de structures // max 20

	std::vector<int>strct_sens;
	std::vector<int>strct_taille;
	std::vector<int>strct_posX;
	std::vector<int>strct_posY;

	for (int c = 0; c < v3; c++) {
		strct_posX.push_back(rand() % (x_taille - 2) + 1); // x
		strct_posY.push_back(rand() % (y_taille - 4) + 2); // y
		strct_sens.push_back(rand() % 4); // sens
		strct_taille.push_back(rand() % 10+3); // taille
		set_blockV2(strct_posY.at(c), strct_posX.at(c), 4, strct_taille.at(c), strct_sens.at(c));
	}

	for (int a = 0; a < v1; a++) {
		set_block(les_enemies_posY.at(a), les_enemies_posX.at(a), les_enemies_niv.at(a)+5);
	}

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < x_taille; x++) {
			set_block(y, x, 2);
		}
	}

	for (int y = y_taille - 2; y < y_taille; y++) {
		for (int x = 0; x < x_taille; x++) {
			set_block(y, x, 2);
		}
	}

	for (int y = 0; y < y_taille; y++) {
		for (int x = 0; x < 1; x++) {
			set_block(y, x, 2);
		}
	}

	for (int y = 0; y < y_taille; y++) {
		for (int x = x_taille - 1; x < x_taille; x++) {
			set_block(y, x, 2);
		}
	}

}

void la_map::afficher(fenetre &fenetre){
    for(int y=0;y<y_taille;y++){
        for(int x=0;x<x_taille;x++){
			if(mapDonne[y][x] - 48!=1){
				int x_2 = ((mapDonne[y][x]-48)%nbDitems)*TILE_SIZE;
				int y_2 = ((mapDonne[y][x]-48)/nbDitems)*TILE_SIZE;
				sprite.setPosition(sf::Vector2f(x*TILE_SIZE, y*TILE_SIZE));
				sprite.setTextureRect(sf::IntRect(x_2, y_2, TILE_SIZE, TILE_SIZE));
				fenetre.getWin().draw(sprite);
			}
        }
    }
}

void la_map::checkContour(sf::Vector2f position) {

	int la_case = 0;

	int x = position.x / 64;
	int y = position.y / 64;

	if(x < x_taille && y < y_taille)
		if(mapDonne[y][x]-48!=2&& mapDonne[y][x] - 48 != 1)
			mapDonne[y][x]=1+48;

	if (x < x_taille && y-1 < y_taille)
		if (mapDonne[y-1][x] - 48 != 2 && mapDonne[y-1][x] - 48 != 1)
			mapDonne[y-1][x] = 1 + 48;

	if (x+1 < x_taille && y-1 < y_taille)
		if (mapDonne[y-1][x+1] - 48 != 2 && mapDonne[y-1][x+1] - 48 != 1)
			mapDonne[y-1][x+1] = 1 + 48;

	if (x+1 < x_taille && y < y_taille)
		if (mapDonne[y][x+1] - 48 != 2 && mapDonne[y][x+1] - 48 != 1)
			mapDonne[y][x+1] = 1 + 48;

	if (x+1 < x_taille && y+1 < y_taille)
		if (mapDonne[y+1][x+1] - 48 != 2 && mapDonne[y+1][x+1] - 48 != 1)
			mapDonne[y+1][x+1] = 1 + 48;

	if (x < x_taille && y+1 < y_taille)
		if (mapDonne[y+1][x] - 48 != 2 && mapDonne[y+1][x] - 48 != 1)
			mapDonne[y+1][x] = 1 + 48;

	if (x-1 < x_taille && y+1 < y_taille)
		if (mapDonne[y+1][x-1] - 48 != 2 && mapDonne[y+1][x-1] - 48 != 1)
			mapDonne[y+1][x-1] = 1 + 48;

	if (x-1 < x_taille && y < y_taille)
		if (mapDonne[y][x-1] - 48 != 2 && mapDonne[y][x-1] - 48 != 1)
			mapDonne[y][x-1] = 1 + 48;

	if (x-1 < x_taille && y-1 < y_taille)
		if (mapDonne[y-1][x-1] - 48 != 2 && mapDonne[y-1][x-1] - 48 != 1)
			mapDonne[y-1][x-1] = 1 + 48;

}

int la_map::get_block(sf::Vector2f position){

int x = position.x/64;
int y = position.y/64;
if(x<x_taille&&y<y_taille){
    return mapDonne[y][x]-48;
}

}

int la_map::get_num(sf::Vector2f position){

int x = position.x/64;
int y = position.y/64;

return y*30+x;

}

int la_map::get_block_2(int y,int x){

	if (y < y_taille && x < x_taille)
		return mapDonne[y][x]-48;

}

int la_map::get_id(sf::Vector2f position1, sf::Vector2f position2) {
	int x1 = position1.x / 64;
	int y1 = position1.y / 64;
	int x2 = position2.x / 64;
	int y2 = position2.y / 64;
	if (x1 < x_taille && y1 < y_taille && x2 < x_taille && y2 < y_taille) {



	}
}

void la_map::charger(int numero){

std::ifstream file;

std::string besoin = "maps/";
besoin += std::to_string(numero);
besoin += ".txt";

file.open(besoin, std::ios::in);
char caractere;
int x=0,y=0;
if(file.is_open()){
    while (!file.eof()){
        file.get(caractere);
        if(x<x_taille&&y<y_taille)
            mapDonne[y][x]=caractere;
        x++;
        if(x>x_taille){
            x=0;
            y++;
        }
    }
}

}

la_map::~la_map()
{
    //dtor
}
