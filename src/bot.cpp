#include "../include/bot.h"

#define PI 3.14159265

bot::bot()
{
    srand (time(NULL));
    sprite.setScale(2,2);
    sprite.setOrigin(sf::Vector2f(15,15));
    sprit_cannon.setScale(2,2);
    sprit_cannon.setPosition(32,32);
    sprit_cannon.setOrigin(sf::Vector2f(15,20));
}
sf::Vector2f bot::getPosition(){
    return sprite.getPosition();
}
void bot::tournerLeViseur(sf::Vector2f LeVector){
            float result = atan2 ( LeVector.y-sprit_cannon.getPosition().y , LeVector.x-sprit_cannon.getPosition().x ) * 180 / PI + 90;
            sprit_cannon.setRotation(result);
}
void bot::affichage(sf::RenderWindow &window){

window.draw(sprite);
sprit_cannon.setPosition(sprite.getPosition().x-1,sprite.getPosition().y);
window.draw(sprit_cannon);

}

void bot::diriger_canon(sf::Vector2i position){
    float result = atan2 ( position.y-sprit_cannon.getPosition().y , position.x-sprit_cannon.getPosition().x ) * 180 / PI + 90;
    sprit_cannon.setRotation(result);
}

bot::~bot()
{
    //dtor
}
