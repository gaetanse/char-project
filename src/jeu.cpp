#include "../include/jeu.h"
#include "../include/menu.h"
#include "../include/joueur.h"

#define mode false /// TRUE = mode loris / FALSE = mode Gaetan
#define blocks 10 /// nb de block existant dans le dossier blocks
#define partie_max 10 /// nb de maps max

void jeu::start() {

	bool ok = false;

	if (mapMod == 1) {

		if (numeroDePartie - 1 == partie_max) {
			fin = true;
			//menu objet_menu;
			//objet_menu.boucle(f);
		}

		liste_bot.clear();
		liste_player.clear();
		liste_munition.clear();
		liste_explosions.clear();

		_audio.clear();

		Map.charger(numeroDePartie - 1);

		for (int y = 0; y < 17; y++) {
			for (int x = 0; x < 30; x++) {
				int nb = Map.get_block_2(y, x);
				if (nb == 5) {
					bot bot_num(0, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 6) {
					bot bot_num(1, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 7) {
					bot bot_num(2, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					bot_num.donner_texture_3(texture_bouclier);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 8) {
					bot bot_num(3, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					bot_num.donner_texture_3(texture_bouclier);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 9) {
					bot bot_num(4, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					bot_num.donner_texture_3(texture_bouclier);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 3) {

					for (int ag = 0; ag < joueurs; ag++) {
						joueur j_creer(ag);
						j_creer.setSpawn(y, x);
						j_creer.donner_texture(texture_char);///ASSEMBLEZ EN UNE CHOSE
						j_creer.donner_texture_2(texture_dessus);
						j_creer.donner_texture_3(texture_bouclier);
						j_creer.donner_texture_4(texture_viseur);
						liste_player.push_back(j_creer);
					}

					Map.set_block(y, x, 1);
				}
			}
		}

	}
	else if (mapMod == 2) {

		liste_bot.clear();
		liste_player.clear();
		liste_munition.clear();
		liste_explosions.clear();

		_audio.clear();

		Map.generationA();

		for (int y = 0; y < 17; y++) {
			for (int x = 0; x < 30; x++) {
				int nb = Map.get_block_2(y, x);
				if (nb == 5) {
					bot bot_num(0, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 6) {
					bot bot_num(1, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 7) {
					bot bot_num(2, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					bot_num.donner_texture_3(texture_bouclier);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 8) {
					bot bot_num(3, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					bot_num.donner_texture_3(texture_bouclier);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 9) {
					bot bot_num(4, diff);
					bot_num.setSpawn(y, x);
					bot_num.donner_texture(texture_char);
					bot_num.donner_texture_2(texture_dessus);
					bot_num.donner_texture_3(texture_bouclier);
					liste_bot.push_back(bot_num);
					Map.set_block(y, x, 1);
				}
				else if (nb == 3) {

					for (int an = 0; an < joueurs; an++) {
						joueur j_creer(an);
						j_creer.setSpawn(y, x);
						j_creer.donner_texture(texture_char);///ASSEMBLEZ EN UNE CHOSE
						j_creer.donner_texture_2(texture_dessus);
						j_creer.donner_texture_3(texture_bouclier);
						j_creer.donner_texture_4(texture_viseur);
						liste_player.push_back(j_creer);
					}

					Map.set_block(y, x, 1);
				}
			}
		}
		/*
		liste_player.shrink_to_fit();

		if (liste_player.size() == 0) 
			ok = true;

		while (ok)
			start();*/

	}

	if(estMort==false)
		numeroDePartie++;

		finDePartie = false;

}

jeu::jeu(int difficulte,int mapMode,int nbjoueurs,float son,float musique)
{
        diff=difficulte;
        mapMod=mapMode;
        joueurs=nbjoueurs;
		if (joueurs > 4)
			joueurs = 4;
        volume_son=son;
}

void jeu::boucle(fenetre &f){

	srand(time(NULL));

	_audio.ajouter_Buffer("audio/expl10.wav", "audio/expl15.wav");

    /// // POUR LA MAP // ///
    view1.reset(sf::FloatRect(0, 0, 960, 540));
    texture_map.create(320,3200);
    int y=0, x=0;
    ///blocks dessiner
    for(int au=0;au<blocks;au++){
        if (test_map.loadFromFile("design/blocks/"+std::to_string(au)+".png")){
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
    //liste_munition.reserve(joueurs);

	texture_explosion.loadFromFile("design/tilesheet/16_sunburn_spritesheet.png");

    /// // POUR LES JOUEURS CREER // ///
	texture_bouclier.loadFromFile("design/bouclier.png");
    texture_char.loadFromFile("design/char.png");
    texture_dessus.loadFromFile("design/dessus.png");
	texture_viseur.loadFromFile("design/viseur.png");
    liste_player.reserve(joueurs);
    /// /// /// /// /// /// /// /// ///
    sf.donne(3,0,2+joueurs+ joueurs);
    f.getWin().setMouseCursorVisible(false);

   // sf.creerSprite("design/viseur.png",sf::Vector2f(0,0),sf::Vector2f(1,1));
	sf.creerSprite("design/coeur.png", sf::Vector2f(120, 70), sf::Vector2f(1, 1));
	sf.creerSprite("design/shield.png", sf::Vector2f(220, 70), sf::Vector2f(1, 1));
	sf.creerSprite("design/tilesheet/16_sunburn_spritesheet.png", sf::Vector2f(200, 5), sf::Vector2f(0.8, 0.8), sf::IntRect(0,0,80,80));

	sf.creerTexte("Niveau : 1 | Difficulté : Normal | Map aléatoire : Non", sf::Vector2f(900, 70), 25, sf::Color::Black);
	sf.creerTexte(" 5 ", sf::Vector2f(160, 70), 25, sf::Color::Black);

	for (int ay = 0; ay < joueurs; ay++) {
		sf.creerTexte(" 100", sf::Vector2f(270 + (ay * 100), 70), 25, sf::Color::Black);
	}

	for (int b = 0; b < joueurs; b++) {
		sf.creerTexte(" 0", sf::Vector2f(270 + (b * 100), 24), 25, sf::Color::Black);
	}

	vie = 10;
	start();

    while(!fin){

		std::cout << "diff:" << diff << "joueurs:" << joueurs << "mapMod:" << mapMod << "vie:" << vie << "numero:" << numeroDePartie-1 << std::endl;

		//liste_bot.shrink_to_fit();

		if (liste_bot.size() == 0) {
			finDePartie = true;
			estMort = false;
			start();
		}

		if (liste_player.size() == 0) {
			if (vie == 1) {
				numeroDePartie = 1;
				//vie = 5;
				start();
			}
			else {

				estMort = true;

				//vie--;
				if (mapMod == 1) {
					estMort = false;
					numeroDePartie--;
				}
				start();
			}
		}

		
		



		temps_recup = frameClock.restart().asSeconds();

		 while (f.getWin().pollEvent(f.getEvent())) {

            if(f.getEvent().type == sf::Event::Closed){
                fin=true;
            }

			if (f.getEvent().type == sf::Event::MouseMoved) {

			}

            if (f.getEvent().type == sf::Event::KeyPressed){

                if (f.getEvent().key.code == sf::Keyboard::Escape){
					_audio.clear();
                    fin=true;
                    menu objet_menu;
                    objet_menu.boucle(f);
                }

            }

        }

		 for (int nb = 0; nb < liste_player.size(); nb++) {

			 liste_player.at(nb).bouclier();

			 if (f.getEvent().type == sf::Event::JoystickMoved)
				 liste_player.at(nb).moveViseurJ();

			 if (liste_player.at(nb).tirer()) {
				 munition mun_creer(99);
				 mun_creer.donner_texture(texture_munition);
				 mun_creer.donner_pos_des(liste_player.at(nb).getPosition(), liste_player.at(nb).getPosViseur());
				 liste_munition.push_back(mun_creer);
			 }

			 if (f.getEvent().type == sf::Event::JoystickMoved) {

				 liste_player.at(nb).deplace_testJ();

				 int nb_1 = Map.get_block(sf::Vector2f(liste_player.at(nb).getPosition().x + liste_player.at(nb).getNum(0) + liste_player.at(nb).getNum(2), liste_player.at(nb).getPosition().y + liste_player.at(nb).getNum(1) + liste_player.at(nb).getNum(3)));
				 int nb_2 = Map.get_block(sf::Vector2f(liste_player.at(nb).getPosition().x + liste_player.at(nb).getNum(0) + liste_player.at(nb).getNum(4), liste_player.at(nb).getPosition().y + liste_player.at(nb).getNum(1) + liste_player.at(nb).getNum(5)));

				 if ((nb_1 == 1 && nb_2 == 1) || (nb_1 == 3 && nb_2 == 3) || (nb_1 == 7 && nb_2 == 7)) {
					 if (mode) {
						 //liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
					 }
					 else {
						 liste_player.at(nb).deplacement_complexeJ(temps_recup);
					 }
				 }
			 }

		 }

		 for (nb = 0; nb < liste_player.size(); nb++) {
			 liste_player.at(nb).bouclier();

			 if (liste_player.at(nb).explosion()) {
				 _audio.creer_son(1);
				 explosion _explosion1(1);
				 _explosion1.transfere(sf::Vector2f(liste_player.at(nb).getPosition().x - 20, liste_player.at(nb).getPosition().y - 20));
				 _explosion1.donner_texture(texture_explosion);
				 liste_explosions.push_back(_explosion1);
				 Map.checkContour(liste_player.at(nb).getPosition());
			 }

			 if (f.getEvent().type == sf::Event::MouseMoved)
				 liste_player.at(nb).moveViseur(sf::Vector2f(sf::Mouse::getPosition()));

			 if (liste_player.at(nb).tirer()) {
				 munition mun_creer(99);
				 mun_creer.donner_texture(texture_munition);
				 mun_creer.donner_pos_des(liste_player.at(nb).getPosition(), liste_player.at(nb).getPosViseur());
				 liste_munition.push_back(mun_creer);
			 }

			 if (f.getEvent().type == sf::Event::KeyPressed)
			 {
				 testqdqzd = true;
			 }
			 else if (f.getEvent().type == sf::Event::KeyReleased) {
				 testqdqzd = false;
			 }

			 if (testqdqzd) {
				 liste_player.at(nb).deplace_test();

				 int nb_1 = Map.get_block(sf::Vector2f(liste_player.at(nb).getPosition().x + liste_player.at(nb).getNum(0) + liste_player.at(nb).getNum(2), liste_player.at(nb).getPosition().y + liste_player.at(nb).getNum(1) + liste_player.at(nb).getNum(3)));
				 int nb_2 = Map.get_block(sf::Vector2f(liste_player.at(nb).getPosition().x + liste_player.at(nb).getNum(0) + liste_player.at(nb).getNum(4), liste_player.at(nb).getPosition().y + liste_player.at(nb).getNum(1) + liste_player.at(nb).getNum(5)));

				 if ((nb_1 == 1 && nb_2 == 1) || (nb_1 == 3 && nb_2 == 3) || (nb_1 == 7 && nb_2 == 7)) {
					 if (mode) {
						 liste_player.at(nb).deplacement_normal(f.getEvent().key.code, temps_recup);
					 }
					 else {
						 liste_player.at(nb).deplacement_complexe(temps_recup);
					 }
				 }

				}

		 }

		 f.getWin().clear(sf::Color(245, 238, 238));
		 ///dessiner ici
		 f.getWin().setView(view1);
		 Map.afficher(f);
		 f.getWin().setView(f.getWin().getDefaultView());

		 bool toucherJ = false;

		 for (int nb = 0; nb < liste_player.size(); nb++) {

			 for (int ae = 0; ae < liste_munition.size(); ae++) {

				 if (Map.get_num(liste_munition.at(ae).getPosition()) == Map.get_num(liste_player.at(nb).getPosition()) && liste_munition.at(ae).getInvul() == false && liste_player.at(nb).get_bouclierb() == false && liste_munition.at(ae).get_est_e() == true) {
					 _audio.creer_son(1);
					 explosion _explosion(0);
					 _explosion.transfere(liste_player.at(nb).getPosition());
					 _explosion.donner_texture(texture_explosion);
					 liste_explosions.push_back(_explosion);
					 liste_player.erase(liste_player.begin() + nb);
					 liste_player.shrink_to_fit();
					 toucherJ = true;
					 break;
				 }

				 if (Map.get_num(liste_munition.at(ae).getPosition()) == Map.get_num(liste_player.at(nb).getPosition_bouclier()) && liste_player.at(nb).get_bouclierb() == true) {
					 _audio.creer_son(0);
					 if (liste_munition.at(ae).changer_sens() == false) {
						 liste_munition.erase(liste_munition.begin() + ae);
					 }
					 break;
				 }
			 }
			 if (!toucherJ) {
				 liste_player.at(nb).diriger_canon(globalPosition);
				 liste_player.at(nb).affichage(f.getWin());
			 }
		 }

		
        bool touchM=false;

        for(int nbe=0;nbe<liste_munition.size();nbe++){

			int nb = Map.get_block(sf::Vector2f(liste_munition.at(nbe).getPosition()));

			if (nb == 2|| nb == 4) {
				if (liste_munition.at(nbe).getVie() > 0) {
					liste_munition.at(nbe).changer_sens();
				}
				else {
					liste_munition.erase(liste_munition.begin() + nbe);
					touchM = true;
				}

			}

            if(!touchM){
                liste_munition.at(nbe).bouger(temps_recup);
                liste_munition.at(nbe).affichage(f.getWin());
            }

        }

		for (int a = 0; a < liste_explosions.size(); a++) {
			if (liste_explosions.at(a).animation() == false) {
				liste_explosions.at(a).affichage(f.getWin());
			}
			else {
					liste_explosions.erase(liste_explosions.begin() + a);
					///sons.erase(sons.begin() + a);
			}
		}

       

        bool toucher=false;

        for(int nbd=0;nbd<liste_bot.size();nbd++){

			if(liste_bot.at(nbd).get_a_bouclier()){

			if(liste_bot.at(nbd).get_bouclierb()==false)
				liste_bot.at(nbd).timer();

				liste_bot.at(nbd).timer2();

			}

				if (liste_bot.at(nbd).get_numero() != 0) {
					if (liste_bot.at(nbd).tirer()) {
						if (liste_player.size() > 0) {
							munition mun_creer(liste_bot.at(nbd).get_numero());
							mun_creer.donner_texture(texture_munition);
							mun_creer.donner_pos_des_h(liste_bot.at(nbd).getPosition(), liste_player.at(0).getPosition());
							liste_munition.push_back(mun_creer);
						}
					}
				}

            for(int ab=0;ab<liste_munition.size();ab++){

				if (Map.get_num(liste_munition.at(ab).getPosition()) == Map.get_num(liste_bot.at(nbd).getPosition()) && liste_munition.at(ab).getInvul() == false && liste_munition.at(ab).get_est_e()==false) {

					if (liste_bot.at(nbd).get_bouclierb() == false) {
						_audio.creer_son(1);
						explosion _explosion(0);
						_explosion.transfere(liste_bot.at(nbd).getPosition());
						_explosion.donner_texture(texture_explosion);
						liste_explosions.push_back(_explosion);
						liste_bot.erase(liste_bot.begin() + nbd);
						liste_bot.shrink_to_fit();
						toucher = true;
						break;
					}
					
				}

				if (Map.get_num(liste_munition.at(ab).getPosition()) == Map.get_num(liste_bot.at(nbd).getPosition_bouclier()) && liste_bot.at(nbd).get_bouclierb() == true) {
					_audio.creer_son(0);
					if (liste_munition.at(ab).changer_sens() == false) {
						liste_munition.erase(liste_munition.begin() + ab);
					}
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

		if (liste_player.size() > 0) {
			
			std::string besoin2 = std::to_string(vie);
			sf.modifText(1, besoin2);

			for (int a = 0; a < joueurs; a++) {
				if (a < liste_player.size()) {
					std::string besoin1 = std::to_string(liste_player.at(a).getBval());
					sf.modifText(a + 2, besoin1);
				}
				else {
					sf.modifText(a + 2, "MORT");
				}
			}

			for (int b = 0; b < joueurs; b++) {
				if (b < liste_player.size()) {
					std::string besoin1;
					if (liste_player.at(b).get_t_e() >= 5) {
						besoin1 = "Actif";
					}
					else {
						besoin1 = std::to_string((int)liste_player.at(b).get_t_e());
					}
					sf.modifText(b + 2 + joueurs, besoin1);
				}
				else {
					sf.modifText(b + 2 + joueurs, "0");
				}
			}

			std::string besoin = "Niveau : ";
			besoin += std::to_string(numeroDePartie-1);
			besoin += " | Mode : ";
			if(diff==1)
				besoin += "Facile";
			else if (diff == 2)
				besoin += "Moyen";
			else if (diff == 3)
				besoin += "Difficile";
			besoin += " | Type de carte : ";
			if(mapMod==1)
				besoin += "Basique";
			else if(mapMod==2)
				besoin += "Aléatoire";

				sf.modifText(0, besoin);

		}
		

        sf.affichage(f.getWin());

        f.getWin().display();

    }

}

jeu::~jeu()
{
    std::cout << "desc jeu";
}
