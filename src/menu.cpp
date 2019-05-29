#include "../include/menu.h"
#include "../include/jeu.h"
#include "../include/option.h"

menu::menu()
{
    //ctor
}

void menu::boucle(fenetre &f){

    f.getWin().setMouseCursorVisible(false);

    std::vector<std::string>liste_string;
    liste_string.push_back("Jouer Mode Normal");

    std::vector<std::string>liste_string2;
    liste_string2.push_back("Difficulté : (Facile) Moyen Difficile");
    liste_string2.push_back("Map : (Basique) Aléatoire");
    liste_string2.push_back("Joueurs : (1) 2 3 4");
    liste_string2.push_back("Son : (25)/100");
    liste_string2.push_back("Musique : (25)/100");

    ///sf est l'objet gestinSf ( c'est une classe pour gérer tous les textes / sprites / rectangles / etc)
    ///sf.donne(0,0,0) va reservé la mémoire des vectors
    /// 0 = pour les sprites /// ... +1 = taille de la liste + 1 (+1 car jen veut un en plus) /// taille de la liste
    sf.donne(1,liste_string.size()+liste_string2.size(),liste_string.size()+liste_string2.size());

    for(unsigned int a=0;a<liste_string.size();a++){
            ///créer un rectangle et un texte avec des parametres donner
            sf.creerRectangle(sf::Vector2f(f.getLargeur()/4,(a*f.getHauteur()/10)+a*2+64),sf::Vector2f(f.getLargeur()/2,f.getHauteur()/12),sf::Color(128,128,128),4,sf::Color::Red);
            sf.creerTexte(liste_string.at(a),sf::Vector2f(f.getLargeur()/2.3,a*f.getHauteur()/10+45+50),25,sf::Color::White);
    }

    /*for(unsigned int a=0;a<liste_string2.size();a++){
            ///créer un rectangle et un texte avec des parametres donner
            sf.creerRectangle(sf::Vector2f(f.getLargeur()/4,(a*f.getHauteur()/10)+a*2+20+(liste_string.size()*200)),sf::Vector2f(f.getLargeur()/2,f.getHauteur()/11),sf::Color(128,100,128),4,sf::Color::Green);
            sf.creerTexte(liste_string2.at(a),sf::Vector2f(f.getLargeur()/3,a*f.getHauteur()/10+45+10+(liste_string.size()*200)),25,sf::Color::White);
    }*/

    int a=0;
    sf.creerRectangle(sf::Vector2f(f.getLargeur()/15,(0*f.getHauteur()/10)+0*2+20+(liste_string.size()*200)),sf::Vector2f(f.getLargeur()/4,f.getHauteur()/11),sf::Color(128,100,128),4,sf::Color::Green);
    sf.creerTexte(liste_string2.at(a),sf::Vector2f(f.getLargeur()/13,0*f.getHauteur()/10+45+10+(liste_string.size()*200)),25,sf::Color::White);
    a=1;
    sf.creerRectangle(sf::Vector2f(f.getLargeur()/1.5,(0*f.getHauteur()/10)+0*2+20+(liste_string.size()*200)),sf::Vector2f(f.getLargeur()/4,f.getHauteur()/11),sf::Color(128,100,128),4,sf::Color::Green);
    sf.creerTexte(liste_string2.at(a),sf::Vector2f(f.getLargeur()/1.4,0*f.getHauteur()/10+45+10+(liste_string.size()*200)),25,sf::Color::White);
    a=2;
    sf.creerRectangle(sf::Vector2f(f.getLargeur()/15,(2*f.getHauteur()/10)+2*2+20+(liste_string.size()*200)),sf::Vector2f(f.getLargeur()/4,f.getHauteur()/11),sf::Color(128,100,128),4,sf::Color::Green);
    sf.creerTexte(liste_string2.at(a),sf::Vector2f(f.getLargeur()/13,2*f.getHauteur()/10+45+10+(liste_string.size()*200)),25,sf::Color::White);
    a=3;
    sf.creerRectangle(sf::Vector2f(f.getLargeur()/1.5,(2*f.getHauteur()/10)+2*2+20+(liste_string.size()*200)),sf::Vector2f(f.getLargeur()/4,f.getHauteur()/11),sf::Color(128,100,128),4,sf::Color::Green);
    sf.creerTexte(liste_string2.at(a),sf::Vector2f(f.getLargeur()/1.4,2*f.getHauteur()/10+45+10+(liste_string.size()*200)),25,sf::Color::White);
    a=4;
    sf.creerRectangle(sf::Vector2f(f.getLargeur()/2.7,(a*f.getHauteur()/10)+a*2+20+(liste_string.size()*200)),sf::Vector2f(f.getLargeur()/4,f.getHauteur()/11),sf::Color(128,100,128),4,sf::Color::Green);
    sf.creerTexte(liste_string2.at(a),sf::Vector2f(f.getLargeur()/2.3,a*f.getHauteur()/10+45+10+(liste_string.size()*200)),25,sf::Color::White);


    sf.modifRectV2(1,sf::Color::Green);


    sf.creerSprite("design/viseur.png",sf::Vector2f(0,0),sf::Vector2f(1,1));


    texture_char.loadFromFile("design/char.png");
    texture_dessus.loadFromFile("design/dessus.png");
    le_joueur.donner_texture(texture_char);
    le_joueur.donner_texture_2(texture_dessus);
    le_joueur.donnerTaille_fenetre(f);
    le_joueur.spawn_milieu();

    //sf.creerRectangle(sf::Vector2f(f.getLargeur()/4,(choix*f.getHauteur()/10)+choix*2+5+(liste_string.size()*250)),sf::Vector2f(f.getLargeur()/2,f.getHauteur()/12),sf::Color::Transparent,8,sf::Color::White);

    while(!fin){

        while(f.getWin().pollEvent(f.getEvent())){

             if(f.getEvent().type == sf::Event::MouseMoved){

                globalPosition = sf::Mouse::getPosition();
                float x=globalPosition.x;float y=globalPosition.y;
                sf.setPos_sprite(0,sf::Vector2f(x,y));
                sf::Vector2f test = sf::Vector2f(x,y);

            }

            if(f.getEvent().type == sf::Event::Closed){
                fin=true;
                choix=999;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //if(choix>=0&&choix<liste_string.size())
                   //fin=true;
            }

            if(f.getEvent().type == sf::Event::MouseMoved){

                /*sf::Vector2i globalPosition = sf::Mouse::getPosition();
                for(unsigned int b=0;b<liste_string.size();b++){
                    if(globalPosition.y>b*(f.getHauteur()/12)+b*16+8&&globalPosition.y<b*(f.getHauteur()/12)+liste_string.size()*19+b*16+8){
                        choix=b;
                        sf.modifRect(liste_string.size(),sf::Vector2f(f.getLargeur(),f.getHauteur()/12),sf::Vector2f(0,(b*f.getHauteur()/10)+choix*2+16));
                    }
                }*/

            }

            if (f.getEvent().type == sf::Event::KeyPressed){

                if (f.getEvent().key.code == sf::Keyboard::Escape){
                    fin=true;
                    f.close();
                   /* delete this;
                    exit(0);
                    break;*/
                }
                if (f.getEvent().key.code == sf::Keyboard::Up){
                    choix--;
                    if(choix<0)
                        choix=liste_string2.size()-1;
                    sf.modifRectV2(choix+1,sf::Color::Green);
                }
                if (f.getEvent().key.code == sf::Keyboard::Down){
                    choix++;
                    if(choix>liste_string2.size()-1)
                        choix=0;
                    sf.modifRectV2(choix+1,sf::Color::Green);
                    //sf.modifRect(liste_string2.size()+1,sf::Vector2f(f.getLargeur(),f.getHauteur()/12),sf::Vector2f(0,(choix*f.getHauteur()/10)+20));
                }
                if (f.getEvent().key.code == sf::Keyboard::Left){
                    string n="";
                    if(choix==0){
                            difficulte--;
                            if(difficulte<1)
                                difficulte=3;
                            n="Difficulté : ";
                            if(difficulte==1){
                                n+="(Facile) Moyen Difficile";
                            }
                            else if(difficulte==2){
                                n+="Facile (Moyen) Difficile";
                            }
                            else if(difficulte==3){
                                n+="Facile Moyen (Difficile)";
                            }
                    }
                    else if(choix==1){
                            mapMode--;
                            if(mapMode<1)
                                mapMode=2;
                            n="Map : ";
                            if(mapMode==1){
                                n+="(Basique) Aléatoire";
                            }
                            else if(mapMode==2){
                                n+="Basique (Aléatoire)";
                            }
                    }
                    else if(choix==2){
                            joueurs--;
                            if(joueurs<1)
                                joueurs=4;
                            n="Joueurs : ";
                            if(joueurs==1){
                                n+="(1) 2 3 4";
                            }
                            else if(joueurs==2){
                                n+="1 (2) 3 4";
                            }
                            else if(joueurs==3){
                                n+="1 2 (3) 4";
                            }
                            else if(joueurs==4){
                                n+="1 2 3 (4)";
                            }
                        }
                    else if(choix==3){
                            son--;
                            if(son<0)
                                son=100;
                            n="Son : (";
                            n+=std::to_string((int)son);
                            n+=")/100";
                    }
                    else if(choix==4){
                            musique--;
                            if(musique<0)
                                musique=100;
                            n="Musique : (";
                            n+=std::to_string((int)musique);
                            n+=")/100";
                    }
                    sf.modifText(choix+1,n);
                }
                if (f.getEvent().key.code == sf::Keyboard::Right){
                    string n="";
                    if(choix==0){
                            difficulte++;
                            if(difficulte>3)
                                difficulte=1;
                            n="Difficulté : ";
                            if(difficulte==1){
                                n+="(Facile) Moyen Difficile";
                            }
                            else if(difficulte==2){
                                n+="Facile (Moyen) Difficile";
                            }
                            else if(difficulte==3){
                                n+="Facile Moyen (Difficile) ";
                            }
                    }
                    else if(choix==1){
                            mapMode++;
                            if(mapMode>2)
                                mapMode=1;
                            n="Map : ";
                            if(mapMode==1){
                                n+="(Basique) Aléatoire";
                            }
                            else if(mapMode==2){
                                n+="Basique (Aléatoire)";
                            }
                        }
                    else if(choix==2){
                            joueurs++;
                            if(joueurs>4)
                                joueurs=1;
                            n="Joueurs : ";
                            if(joueurs==1){
                                n+="(1) 2 3 4";
                            }
                            else if(joueurs==2){
                                n+="1 (2) 3 4";
                            }
                            else if(joueurs==3){
                                n+="1 2 (3) 4";
                            }
                            else if(joueurs==4){
                                n+="1 2 3 (4)";
                            }
                    }
                    else if(choix==3){
                            son++;
                            if(son>100)
                                son=0;
                            n="Son : (";
                            n+=std::to_string((int)son);
                            n+=")/100";
                    }
                    else if(choix==4){
                            musique++;
                            if(musique>100)
                                musique=0;
                            n="Musique : (";
                            n+=std::to_string((int)musique);
                            n+=")/100";
                    }
                    sf.modifText(choix+1,n);
                }
                if (f.getEvent().key.code == sf::Keyboard::Enter){
                        fin=true;
                        jeu objet_jeu(difficulte,mapMode,joueurs,son,musique);
                        objet_jeu.boucle(f);
                }

            }

    }

    f.getWin().clear(sf::Color(234,223,223));
    ///dessiner ici
    sf.affichage(f.getWin());
    le_joueur.diriger_canon(globalPosition);
    le_joueur.affichage(f.getWin());

    f.getWin().display();

    }

}

menu::~menu()
{
    std::cout << "desc menu";
}
