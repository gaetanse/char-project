#include "../include/option.h"
#include "../include/menu.h"

option::option()
{
    //ctor
}

void option::boucle(fenetre &f){

    sf.donne(0,0,0);

    while(!fin){
        while(f.getWin().pollEvent(f.getEvent())){
            if(f.getEvent().type == sf::Event::Closed){
                fin=true;
            }
            if (f.getEvent().type == sf::Event::KeyPressed){
                if (f.getEvent().key.code == sf::Keyboard::Escape){
                    fin=true;
                }
            }
    }

    f.getWin().clear(sf::Color::Green);
    ///dessiner ici
    sf.affichage(f.getWin());
    f.getWin().display();

    }

    menu *objet_menu = new menu();
    ///supprimer le new du menu (créer dans le menu)
    delete this;
    objet_menu->boucle(f);

}

option::~option()
{
    //dtor
}
