#include "../include/jeu.h"
#include "../include/menu.h"
#include "../include/joueur.h"

#define mode false /// TRUE = mode loris / FALSE = mode Gaetan
#define blocks 10 /// nb de block existant dans le dossier blocks

jeu::jeu(int difficulte,int mapMode,int nbjoueurs,float son,float musique)
{
        diff=difficulte;
        mapMod=mapMode;
        joueurs=nbjoueurs;
        volume_son=son;
        //joueurs=musique;
}

void jeu::boucle(fenetre &f){

	srand(time(NULL));

    /// AUDIO
    sound.setVolume(volume_son);
    /// setvolume volume_audio
    std::vector<string>listes_son;
    listes_son.push_back("audio/expl10.wav");
    listes_son.push_back("audio/expl15.wav");

    for(int a=0;a<listes_son.size();a++){
        sf::SoundBuffer besoin;
        sons.push_back(besoin);
        if (!sons.at(a).loadFromFile(listes_son.at(a)))
            std::cout << "erreur chargement du son : " << listes_son.at(a) << std::endl;
    }


    /// // POUR LA MAP // ///
    view1.reset(sf::FloatRect(0, 0, 960, 540));
    texture_map.create(320,3200);
    int y=0, x=0;
    ///blocks dessiner
    for(int a=0;a<blocks;a++){
        if (test_map.loadFromFile("design/blocks/"+std::to_string(a)+".png")){
            texture_map.update(test_map,x*32,y*32);
        }
        x++;
        if(x>10){
            y++;
            x=0;
        }
    }
    Map.charger_texture(texture_map);
    /// chargement map 0
    Map.charger(0);
    /// /// /// /// /// /// /// /// ///

    texture_munition.loadFromFile("design/munition.png");
    liste_munition.reserve(joueurs);

	texture_explosion.loadFromFile("design/tilesheet/16_sunburn_spritesheet.png");
	liste_explosions.reserve(joueurs);

    /// // POUR LES JOUEURS CREER // ///
    texture_char.loadFromFile("design/char.png");
    texture_dessus.loadFromFile("design/dessus.png");
    liste_player.reserve(joueurs);
    /// /// /// /// /// /// /// /// ///

    sf.donne(1,0,1);
    f.getWin().setMouseCursorVisible(false);

    sf.creerSprite("design/viseur.png",sf::Vector2f(0,0),sf::Vector2f(1,1));
    sf.creerTexte("Vie : 5 | Niveau : 1 | Difficulté : Normal | Map aléatoire : Non",sf::Vector2f(f.getLargeur()/3.5,f.getHauteur()/20),25,sf::Color::Black);

    while(!fin){

        sf::Time frameTime = frameClock.restart();
        float temps_recup=frameTime.asSeconds();

        if(liste_bot.size()==0){
            finDePartie=true;
        }

        if(liste_player.size()==0){
            joueur j_creer;
			///TESTER LES BOTS
				///TESTER LES JOUEURS
					///TESTER SI C UNE BONNE CASE
			/*for (int b = 0; b < liste_player.size(); b++) {
				for (int a = 0; a < liste_bot.size(); a++) {*/
			//j_creer.getX() == liste_bot.at(a).getX() && j_creer.getX() == liste_bot.at(a).getX() && j_creer.getX() == liste_player.at(b).getX() && j_creer.getX() == liste_player.at(b).getX() && 
					while (j_creer.testMapDeCase(Map.get_block(sf::Vector2f(j_creer.getPosition()))) != 1) {
						j_creer.spawn();
				/*	}
				}*/
			}
            j_creer.donner_texture(texture_char);///ASSEMBLEZ EN UNE CHOSE
            j_creer.donner_texture_2(texture_dessus);
            j_creer.donnerTaille_fenetre(f);///CHANGER ET DONNEZ JUSTE LES BONNES VALEURS
            liste_player.push_back(j_creer);
        }

        if(finDePartie){
            bot bot_num(0);
				/*for (int b = 0; b < liste_player.size(); b++) {
					for (int a = 0; a < liste_bot.size(); a++) {*/
			//&&bot_num.getX() == liste_bot.at(a).getX() && bot_num.getX() == liste_bot.at(a).getX() && bot_num.getX() == liste_player.at(b).getX() && bot_num.getX() == liste_player.at(b).getX()
						while(bot_num.testMapDeCase(Map.get_block(sf::Vector2f(bot_num.getPosition()))) != 1) {
							bot_num.spawn();
					/*	}
					}*/
				}
            bot_num.donner_texture(texture_char);
            bot_num.donner_texture_2(texture_dessus);
            liste_bot.push_back(bot_num);
			bot bot_num_2(1);
				/*for (int b = 0; b < liste_player.size(); b++) {
					for (int a = 0; a < liste_bot.size(); a++) {*/
			//&&bot_num_2.getX() == liste_bot.at(a).getX() && bot_num_2.getX() == liste_bot.at(a).getX() && bot_num_2.getX() == liste_player.at(b).getX() && bot_num_2.getX() == liste_player.at(b).getX()
						while (bot_num_2.testMapDeCase(Map.get_block(sf::Vector2f(bot_num_2.getPosition()))) != 1) {
							bot_num_2.spawn();
					/*	}
					}*/
				}
			bot_num_2.donner_texture(texture_char);
			bot_num_2.donner_texture_2(texture_dessus);
			liste_bot.push_back(bot_num_2);
            finDePartie=false;
        }

         for(int z=0;z<liste_player.size();z++){
            if(liste_player.at(z).tirer()){
                munition mun_creer;
                mun_creer.donner_texture(texture_munition);
                mun_creer.donner_pos_des(liste_player.at(z).getPosition(),sf::Vector2f(x,y));
                liste_munition.push_back(mun_creer);
            }
         }

		 

        while (f.getWin().pollEvent(f.getEvent())){

            if(f.getEvent().type == sf::Event::Closed){
                fin=true;
            }

                 for(int nb=0;nb<liste_player.size();nb++){
                    if (sf::Joystick::isConnected(liste_player.at(nb).getNum())){
                        if(mode)
                            liste_player.at(nb).deplacement_normal(f.getEvent().key.code,temps_recup);
                        else
                            liste_player.at(nb).deplacement_complexe(f.getEvent().key.code,temps_recup);
                    }
                }

            if (f.getEvent().type == sf::Event::KeyPressed){

                int num_x=0, num_y=0;
                int num_2x=0, num_2y=0;
                int num_3x=0, num_3y=0;

                if(f.getEvent().key.code == sf::Keyboard::Left){
                    num_2y=-20;
                    num_3y=20;
                    num_x=-30;
                }
                if(f.getEvent().key.code == sf::Keyboard::Right){
                    num_2y=20;
                    num_3y=-20;
                    num_x=30;
                }
                if(f.getEvent().key.code == sf::Keyboard::Up){
                    num_2x=-20;
                    num_3x=20;
                    num_y=-30;
                    }
                if(f.getEvent().key.code == sf::Keyboard::Down){
                    num_2x=20;
                    num_3x=-20;
                    num_y=30;
                }

                for(int nb=0;nb<liste_player.size();nb++){
                        std::cout << joueurs << std::endl;
                if(Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x+num_x+num_2x,liste_player.at(0).getPosition().y+num_y+num_2y))==1&&
                    Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x+num_x+num_3x,liste_player.at(0).getPosition().y+num_y+num_3y))==1){
                    if(joueurs==1){
                        if(mode)
                            liste_player.at(0).deplacement_normal(f.getEvent().key.code,temps_recup);
                        else
                            liste_player.at(0).deplacement_complexe(f.getEvent().key.code,temps_recup);
                    }
                }
                }

                if (f.getEvent().key.code == sf::Keyboard::Escape){
                    fin=true;
                    //delete this;
                        //delete this;
                    menu objet_menu;
                    objet_menu.boucle(f);
                    //delete pvalue;
                }

            }

            if(f.getEvent().type == sf::Event::MouseMoved){

                globalPosition = sf::Mouse::getPosition();
                float x=globalPosition.x;float y=globalPosition.y;
                sf.setPos_sprite(0,sf::Vector2f(x,y));
                sf::Vector2f test = sf::Vector2f(x,y);

            }

        }

        f.getWin().clear(sf::Color::Blue);
        ///dessiner ici
        f.getWin().setView(view1);
        Map.afficher(f);
        f.getWin().setView(f.getWin().getDefaultView());



        bool touchM=false;

        for(int nbe=0;nbe<liste_munition.size();nbe++){

           if(Map.get_block(sf::Vector2f(liste_munition.at(nbe).getPosition()))!=1){
                if(liste_munition.at(nbe).getVie()>0){
                    liste_munition.at(nbe).changer_sens();
                }
                else{
                    liste_munition.erase(liste_munition.begin()+nbe);
                    touchM=true;
                }
            }

            if(!touchM){
                liste_munition.at(nbe).bouger(temps_recup);
                liste_munition.at(nbe).affichage(f.getWin());
            }

        }

        bool toucherJ=false;

        for(int nb=0;nb<liste_player.size();nb++){
            for(int a=0;a<liste_munition.size();a++){
                if(liste_munition.at(a).check_col(liste_player.at(nb).getPosition())){
                    sound.setBuffer(sons.at(1));
                    sound.play();
					explosion _explosion(liste_player.at(nb).getPosition());
					_explosion.donner_texture(texture_explosion);
					liste_explosions.push_back(_explosion);
                    liste_player.erase(liste_player.begin()+nb);
                    toucherJ=true;

                    break;
                }
            }
            if(!toucherJ){
                liste_player.at(nb).diriger_canon(globalPosition);
                liste_player.at(nb).affichage(f.getWin());
            }
        }

        //

        bool toucher=false;

        for(int nbd=0;nbd<liste_bot.size();nbd++){

            if(liste_bot.at(nbd).tirer()){
                if(liste_player.size()>0){
                munition mun_creer;
                mun_creer.donner_texture(texture_munition);
                mun_creer.donner_pos_des_h(liste_bot.at(nbd).getPosition(),liste_player.at(0).getPosition());
                liste_munition.push_back(mun_creer);
                }
            }

            for(int ab=0;ab<liste_munition.size();ab++){
                if(liste_munition.at(ab).check_col(liste_bot.at(nbd).getPosition())){
                    sound.setBuffer(sons.at(1));
                    sound.play();
					explosion _explosion(liste_bot.at(nbd).getPosition());
					_explosion.donner_texture(texture_explosion);
					liste_explosions.push_back(_explosion);
                    liste_bot.erase(liste_bot.begin()+nbd);
                    toucher=true;
                    break;
                }
            }

            if(!toucher){
                if(liste_player.size()>0){
					liste_bot.at(nbd).tournerLeViseur(liste_player.at(0).getPosition());
                }
                liste_bot.at(nbd).affichage(f.getWin());
            }
        }

		for (int a = 0; a < liste_explosions.size(); a++) {
			if(liste_explosions.at(a).animation()==false)
				liste_explosions.at(a).affichage(f.getWin());
			else
				liste_explosions.erase(liste_explosions.begin() + a);
		}

        sf.affichage(f.getWin());

        f.getWin().display();

    }

}

jeu::~jeu()
{
    std::cout << "desc jeu";
}
