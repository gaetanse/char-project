#include "../include/la_map.h"
#include "../include/fenetre.h"
#include <fstream>

#define TILE_SIZE 32
#define nbDitems 10

la_map::la_map()
{

    liste_blocks.push_back(false);
    liste_blocks.push_back(true);
    liste_blocks.push_back(false);
    liste_blocks.push_back(false);
    liste_blocks.push_back(false);
    liste_blocks.push_back(false);
    liste_blocks.push_back(false);
    liste_blocks.push_back(false);

}

void la_map::charger_texture(sf::Texture &texture){
    sprite.setTexture(texture);
}

void la_map::afficher(fenetre &fenetre){
    for(int y=0;y<y_taille;y++){
        for(int x=0;x<x_taille;x++){
            int x_2 = ((mapDonne[y][x]-48)%nbDitems)*TILE_SIZE;
            int y_2 = ((mapDonne[y][x]-48)/nbDitems)*TILE_SIZE;
            sprite.setPosition(sf::Vector2f(x*TILE_SIZE, y*TILE_SIZE));
            sprite.setTextureRect(sf::IntRect(x_2, y_2, TILE_SIZE, TILE_SIZE));
            fenetre.getWin().draw(sprite);
        }
    }
}

int la_map::get_block(sf::Vector2f position){

int x = position.x/64;
int y = position.y/64;
if(x<x_taille&&y<y_taille){
    //std::cout << "map case valeur : " << mapDonne[y][x]-48 << "map case : " << y << "/" << x  << std::endl;
    return mapDonne[y][x]-48;
}
/*if(mapDonne[y][x]-48<liste_blocks.size())
    return liste_blocks.at(mapDonne[y][x]-48);*/

}

int la_map::get_num(sf::Vector2f position){

int x = position.x/64;
int y = position.y/64;

return y*30+x;

}

int la_map::get_block_2(int y,int x){

if(mapDonne[y][x]-48<liste_blocks.size())
    return liste_blocks.at(mapDonne[y][x]-48);

}

void la_map::charger(int numero){

std::ifstream file;
file.open("bin/Debug/maps/0.txt", std::ios::in);
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
