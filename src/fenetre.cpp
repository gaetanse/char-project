#include "../include/fenetre.h"
#include "../include/librairies.h"

fenetre::fenetre(){
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    hauteur=desktop.height,largeur=desktop.width;
    renderWindow.create(sf::VideoMode(largeur, hauteur, desktop.bitsPerPixel),"char project",sf::Style::Resize);
    renderWindow.setVerticalSyncEnabled(true);
}

sf::RenderWindow &fenetre::getWin(){return renderWindow;}
sf::Event &fenetre::getEvent(){return event;}
float fenetre::getLargeur(){return largeur;}
float fenetre::getHauteur(){return hauteur;}

fenetre::~fenetre(){
    std::cout << "desc fen";
}
