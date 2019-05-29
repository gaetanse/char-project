#ifndef DEF_TEMPS
#define DEF_TEMPS

#include "librairies.h"

using namespace std;
class temps
{

public:

    //constructeur
    temps();
    //destructeur
    ~temps();
    ///~ia();
    //méthodes
    int Wait_Temps(float sec);
    void reset();
    int donner();
    float recup_temps();

private:

//VAR
float temps_attente;
float temps_actuel;
sf::Clock cloack;
int i;
bool reussi;

};


#endif

