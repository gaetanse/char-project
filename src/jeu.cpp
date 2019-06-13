#include "../include/jeu.h"
#include "../include/menu.h"
#include "../include/joueur.h"

#define mode false /// TRUE = mode loris / FALSE = mode Gaetan
#define blocks 10 /// nb de block existant dans le dossier blocks

void jeu::start() {

	if (numeroDePartie - 1 == 5) {
		exit(0);
	}

	listes_son.clear();
	liste_bot.clear();
	liste_player.clear();
	liste_munition.clear();
	liste_explosions.clear();

	Map.charger(numeroDePartie-1);

	////FAIRE SPAWN LES IA
	for (int y = 0; y < 17; y++) {
		for (int x = 0; x < 30; x++) {
			int nb = Map.get_block_2(y, x);
			if (nb == 7) {
				bot bot_num(1);
				bot_num.setSpawn(y, x);
				bot_num.donner_texture(texture_char);
				bot_num.donner_texture_2(texture_dessus);
				liste_bot.push_back(bot_num);
			}
			else if (nb == 8) {
				bot bot_num(1);
				bot_num.setSpawn(y, x);
				bot_num.donner_texture(texture_char);
				bot_num.donner_texture_2(texture_dessus);
				liste_bot.push_back(bot_num);
			}
			else if (nb == 3) {
				joueur j_creer;
				j_creer.setSpawn(y, x);
				j_creer.donner_texture(texture_char);///ASSEMBLEZ EN UNE CHOSE
				j_creer.donner_texture_2(texture_dessus);
				//j_creer.donnerTaille_fenetre(f);///CHANGER ET DONNEZ JUSTE LES BONNES VALEURS
				liste_player.push_back(j_creer);
			}
		}
	}

	numeroDePartie++;
	finDePartie = false;
}

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
    //sound.setVolume(volume_son);
    /// setvolume volume_audio
    listes_son.push_back("audio/expl10.wav");
    listes_son.push_back("audio/expl15.wav");

    for(int a=0;a<listes_son.size();a++){
        sf::SoundBuffer besoin;
        sonsBuffers.push_back(besoin);
        if (!sonsBuffers.at(a).loadFromFile(listes_son.at(a)))
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
    /// /// /// /// /// /// /// /// ///

    texture_munition.loadFromFile("design/munition.png");
    liste_munition.reserve(joueurs);

	texture_explosion.loadFromFile("design/tilesheet/16_sunburn_spritesheet.png");
	//liste_explosions.reserve(255);

    /// // POUR LES JOUEURS CREER // ///
    texture_char.loadFromFile("design/char.png");
    texture_dessus.loadFromFile("design/dessus.png");
    liste_player.reserve(joueurs);
    /// /// /// /// /// /// /// /// ///

    sf.donne(1,0,1);
    f.getWin().setMouseCursorVisible(false);

    sf.creerSprite("design/viseur.png",sf::Vector2f(0,0),sf::Vector2f(1,1));
    sf.creerTexte("Vie : 5 | Niveau : 1 | Difficulté : Normal | Map aléatoire : Non",sf::Vector2f(f.getLargeur()/3.5,f.getHauteur()/20),25,sf::Color::Black);

	//if (mapMod == 0) {
		start();
	//}

	/*for (int b = 0; b < liste_player.size(); b++) {
		for (int a = 0; a < liste_bot.size(); a++) {*/
		//&&bot_num_2.getX() == liste_bot.at(a).getX() && bot_num_2.getX() == liste_bot.at(a).getX() && bot_num_2.getX() == liste_player.at(b).getX() && bot_num_2.getX() == liste_player.at(b).getX()

				/*	}
				}*/
	/*for (int b = 0; b < liste_player.size(); b++) {
		for (int a = 0; a < liste_bot.size(); a++) {*/
		//&&bot_num.getX() == liste_bot.at(a).getX() && bot_num.getX() == liste_bot.at(a).getX() && bot_num.getX() == liste_player.at(b).getX() && bot_num.getX() == liste_player.at(b).getX()

				/*	}
				}*/

	///TESTER LES BOTS
		///TESTER LES JOUEURS
			///TESTER SI C UNE BONNE CASE
	/*for (int b = 0; b < liste_player.size(); b++) {
		for (int a = 0; a < liste_bot.size(); a++) {*/
		//j_creer.getX() == liste_bot.at(a).getX() && j_creer.getX() == liste_bot.at(a).getX() && j_creer.getX() == liste_player.at(b).getX() && j_creer.getX() == liste_player.at(b).getX() && 

			/*	}
			}*/
	/*

        if(liste_player.size()==0){
            joueur j_creer;
			while (j_creer.testMapDeCase(Map.get_block(sf::Vector2f(j_creer.getPosition()))) != 1) {
						j_creer.spawn();
			}
            j_creer.donner_texture(texture_char);///ASSEMBLEZ EN UNE CHOSE
            j_creer.donner_texture_2(texture_dessus);
            j_creer.donnerTaille_fenetre(f);///CHANGER ET DONNEZ JUSTE LES BONNES VALEURS
            liste_player.push_back(j_creer);
        }

        if(finDePartie){
            bot bot_num(0);
			while (bot_num.testMapDeCase(Map.get_block(sf::Vector2f(bot_num.getPosition()))) != 1) {
				bot_num.spawn();
				}
            bot_num.donner_texture(texture_char);
            bot_num.donner_texture_2(texture_dessus);
            liste_bot.push_back(bot_num);
			bot bot_num_2(1);
			while (bot_num_2.testMapDeCase(Map.get_block(sf::Vector2f(bot_num_2.getPosition()))) != 1) {
				bot_num_2.spawn();
				}
			bot_num_2.donner_texture(texture_char);
			bot_num_2.donner_texture_2(texture_dessus);
			liste_bot.push_back(bot_num_2);
            finDePartie=false;
        }

	*/

    while(!fin){

        sf::Time frameTime = frameClock.restart();
        float temps_recup=frameTime.asSeconds();


		if (liste_bot.size() == 0) {
			///partie +1
			//charger map
			//refaire les chargements perso et ia
			//numeroDePartie++;
			finDePartie = true;
			start();
		}


		if (liste_player.size() == 0) {
			fin = true;
			menu objet_menu;
			objet_menu.boucle(f);

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

				   int nb_1 = Map.get_block(sf::Vector2f(liste_player.at(nb).getPosition().x + num_x + num_2x, liste_player.at(nb).getPosition().y + num_y + num_2y));
				   int nb_2 = Map.get_block(sf::Vector2f(liste_player.at(nb).getPosition().x + num_x + num_3x, liste_player.at(nb).getPosition().y + num_y + num_3y));
				   /*

				   std::cout << nb_1 << " /// " << nb_2 << std::endl;

				   std::vector<int>list;
				   list.push_back(1);
				   list.push_back(3);
				   list.push_back(7);

				   for (int a = 0; a < list.size(); a++) {
					   if (nb_1 == a && nb_2 == a) {
						   if (mode) {
							   liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
						   }
						   else {
							   liste_player.at(nb).deplacement_complexe(f.getEvent().key.code, temps_recup);
						   }
					   }
				   }*/
				   
				   if ((nb_1 == 1 && nb_2 == 1)|| (nb_1 == 3 && nb_2 == 3) || (nb_1 == 7 && nb_2 == 7)) {
					   if (mode) {
						   liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
					   }
					   else {
						   liste_player.at(nb).deplacement_complexe(f.getEvent().key.code, temps_recup);
					   }
				   }
				   /*
                if(Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x+num_x+num_2x,liste_player.at(0).getPosition().y+num_y+num_2y))==1&&
                    Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x+num_x+num_3x,liste_player.at(0).getPosition().y+num_y+num_3y))==1){
                    if(joueurs==1){

						std::cout << "HUM";

                        if(mode){
							liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
						}
                        else{
							liste_player.at(nb).deplacement_complexe(f.getEvent().key.code, temps_recup);
						}
                    }
                }

				if (Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x + num_x + num_2x, liste_player.at(0).getPosition().y + num_y + num_2y)) == 7 &&
					Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x + num_x + num_3x, liste_player.at(0).getPosition().y + num_y + num_3y)) == 7) {
					if (joueurs == 1) {

						std::cout << "HUM";

						if (mode) {
							liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
						}
						else {
							liste_player.at(nb).deplacement_complexe(f.getEvent().key.code, temps_recup);
						}
					}
				}

				if (Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x + num_x + num_2x, liste_player.at(0).getPosition().y + num_y + num_2y)) == 3 &&
					Map.get_block(sf::Vector2f(liste_player.at(0).getPosition().x + num_x + num_3x, liste_player.at(0).getPosition().y + num_y + num_3y)) == 3) {
					if (joueurs == 1) {

						std::cout << "HUM";

						if (mode) {
							liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
						}
						else {
							liste_player.at(nb).deplacement_complexe(f.getEvent().key.code, temps_recup);
						}
					}
				}

				*/
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

			int nb = Map.get_block(sf::Vector2f(liste_munition.at(nbe).getPosition()));

			if (nb == 2) {
				if (liste_munition.at(nbe).getVie() > 0) {
					liste_munition.at(nbe).changer_sens();
				}
				else {
					liste_munition.erase(liste_munition.begin() + nbe);
					touchM = true;
				}

			}
			
			
			/*
           if(Map.get_block(sf::Vector2f(liste_munition.at(nbe).getPosition()))!=1){
             
            }*/

            if(!touchM){
                liste_munition.at(nbe).bouger(temps_recup);
                liste_munition.at(nbe).affichage(f.getWin());
            }

        }

        bool toucherJ=false;

        for(int nb=0;nb<liste_player.size();nb++){
            for(int a=0;a<liste_munition.size();a++){
                if(liste_munition.at(a).check_col(liste_player.at(nb).getPosition())){
					sf::Sound son;
					sons.push_back(son);
					sons.at(sons.size() - 1).setVolume(volume_son);
					sons.at(sons.size() - 1).setBuffer(sonsBuffers.at(1));
					sons.at(sons.size() - 1).play();
					explosion _explosion;
					_explosion.transfere(liste_player.at(nb).getPosition());
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
				/*if (liste_munition.at(ab).check_col(liste_bot.at(nbd).getPosition())) {
					sf::Sound son;
					sons.push_back(son);
					sons.at(sons.size() - 1).setVolume(volume_son);
					sons.at(sons.size() - 1).setBuffer(sonsBuffers.at(1));
					sons.at(sons.size() - 1).play();
					explosion _explosion;
					_explosion.transfere(liste_bot.at(nbd).getPosition());
					_explosion.donner_texture(texture_explosion);
					liste_explosions.push_back(_explosion);
					liste_bot.erase(liste_bot.begin() + nbd);
					toucher = true;
					break;
				}*/
                if(liste_munition.at(ab).check_col(liste_bot.at(nbd).getPosition())){
					sf::Sound son;
					sons.push_back(son);
					sons.at(sons.size() - 1).setVolume(volume_son);
					sons.at(sons.size() - 1).setBuffer(sonsBuffers.at(1));
					sons.at(sons.size() - 1).play();
					explosion _explosion;
					_explosion.transfere(liste_bot.at(nbd).getPosition());
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
		
		for (int a = 0; a < liste_explosions.size(); a++)
			//if(_audio.attendre(a))
			//	_audio.supprime(a)

		for (int a = 0; a < liste_explosions.size(); a++) {
			if (liste_explosions.at(a).animation() == false) {
				liste_explosions.at(a).affichage(f.getWin());
			}
			else{
				liste_explosions.erase(liste_explosions.begin() + a);
				sons.erase(sons.begin() + a);
			}
		}

        sf.affichage(f.getWin());

        f.getWin().display();

    }

}

jeu::~jeu()
{
    std::cout << "desc jeu";
}
