#ifndef DEF_TEMPS
#define DEF_TEMPS

#include "librairies.h"

using namespace std;
class temps
{

public:

    temps();
    ~temps();
    bool Wait_Temps(float sec);
    void reset();
    int donner();
    float recup_temps();

private:

//VAR
float temps_attente=0;
float temps_actuel=0;
sf::Clock cloack;
int i=0;
bool reussi=false;

};


#endif

