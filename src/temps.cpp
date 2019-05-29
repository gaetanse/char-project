#include "../include/temps.h"

int temps::donner(){



    if(this->reussi)
        return 1;

}

float temps::recup_temps(){
    return cloack.getElapsedTime().asSeconds();
}

bool temps::Wait_Temps(float sec){

    if(this->i==0){
        this->temps_attente=sec;
        this->i++;
    }

    sf::Time temp = this->cloack.getElapsedTime();
    this->temps_actuel = temp.asSeconds();

            if(this->temps_actuel>this->temps_attente){
                this->reussi=true;
                reset();
                return true;
            }
            else{
				return false;
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
