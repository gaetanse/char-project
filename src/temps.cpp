#include "../include/temps.h"

int temps::donner(){



    if(this->reussi)
        return 1;

}

float temps::recup_temps(){
    return cloack.getElapsedTime().asSeconds();
}

int temps::Wait_Temps(float sec){

    if(this->i==0){
        this->temps_attente=sec;
        this->i++;
    }

    sf::Time temp = this->cloack.getElapsedTime();
    this->temps_actuel = temp.asSeconds();

            if(this->temps_actuel>this->temps_attente){

                this->reussi=true;
                reset();
                return 1;
                ///détruire temps;

            }
            else{
               // cout << "temps : " << this->temps_actuel << endl;
            }

}

void temps::reset(){

this->reussi=false;
this->temps_actuel=0;
this->cloack.restart();
this->i=0;

}

temps::temps()
{

}

temps::~temps()
{

}
