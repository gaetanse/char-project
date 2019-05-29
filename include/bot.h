#ifndef BOT_H
#define BOT_H

#include "librairies.h"
#include "la_map.h"
#include "pathfinding.h"
#include "temps.h"
#include <math.h>

class bot
{
    public:
        bot();
        ~bot();
        void affichage(sf::RenderWindow &window);
        void diriger_canon(sf::Vector2i);
        sf::Vector2f getPosition();
        void tournerLeViseur(sf::Vector2f LeVector);

        bool est_dans_la_liste(int nb){

            for(int a=0;a<liste_chemin.size();a++){
                if(liste_chemin.at(a)==nb)
                    return true;
            }

            return false;

        }



        bool tirer(){

        if(t_reload.Wait_Temps(3.0)==1)
            return true;
          //  if(max_munition<1)
            //    max_munition++;

       /* if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&max_munition>0){
                max_munition--;
                return true;
            }*/

            return false;

        }

        int testMapDeCase(int v){

        if(v==2)
            v=3;

        std::cout << v << std::endl;

        return v;

        }

        void spawn(){


            x = rand() % 30;
            y = rand() % 17;

            std::cout << x << " / " << y << std::endl;

            sprite.setPosition(sf::Vector2f(x*32,y*32));


        }

        int getX(){return x;}
        int getY(){return y;}


        sf::Vector2f orentation(){
            return sprit_cannon.getPosition();
        }

        void cherche_joueur(sf::Vector2f joueur,la_map Map){

        ///trouver un chemin vers le joueur
        ///tous les blocks vide
        int num=0;
        for(int y=0;y<17;y++){
            for(int x=0;x<30;x++){
                if(Map.get_block_2(y,x)==1){
                ///push_back les positions
                liste_chemin.push_back(num);
            }
                num++;
        }
        }

        ///pos du bot
        int case_de_depart=Map.get_num(getPosition());
        int case_de_fin=Map.get_num(joueur);

        path.debut(case_de_depart,case_de_fin,liste_chemin);

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


        void deplace(float temps_recup){



            for(int a=dejafait;a<path.pathOk().size();a++){
                 if(path.pathOk().at(a)==1){
                        sprite.move(-1*temps_recup*5,0);
                         if(t_anime.Wait_Temps(1)==1){
                            dejafait++;
                         }
                }
                else if(path.pathOk().at(a)==2){
                    if(t_anime.Wait_Temps(1)==1){
                        sprite.move(1*temps_recup*5,0);
                         if(t_anime.Wait_Temps(1)==1){
                            dejafait++;
                         }
                }
                }
                else if(path.pathOk().at(a)==3){
                        sprite.move(0,-1*temps_recup*5);
                         if(t_anime.Wait_Temps(1)==1){
                            dejafait++;
                         }
                }
                else if(path.pathOk().at(a)==4){
                        sprite.move(0,1*temps_recup*5);
                         if(t_anime.Wait_Temps(1)==1){
                            dejafait++;
                         }
                }
                //sprite.move();
            }




        ///parcourir le bon chemin


        }

        int check_col(sf::Vector2f test){

            if(test.x>getPosition().x&&test.x<getPosition().x+32){
                if(test.y>getPosition().y&&test.y<getPosition().y+32){
                    return 1;
                }
            }

        }

        void donner_texture(sf::Texture &texture){
    sprite.setTexture(texture);
}
void donner_texture_2(sf::Texture &texture){
    sprit_cannon.setTexture(texture);
}

    private:

    pathfinding path;
    temps t_reload;
    int max_munition=0;

    sf::Sprite sprite;
    sf::Sprite sprit_cannon;

    temps t_anime;
    int dejafait=0;

    int x=0;
    int y=0;

    std::vector<int>liste_chemin;
    std::vector<int>best_chemin;
    std::vector<int>test_chemin;
    std::vector<bool>bool_chemin;
    std::vector<int>nb_chemin;

};

#endif // BOT_H
