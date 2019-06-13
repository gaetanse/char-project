#include "../include/gestionSf.h"

///ne pas oublier de remettre les chemins normaux c'est a dire :: sans "bin/Debug/"

gestionSf::gestionSf()
{
    font.loadFromFile("font/base.ttf");
}

void gestionSf::donne(int sprite,int rectangle,int text)
{
    textures.reserve(sprite);
    sprites.reserve(sprite);
    rectangles.reserve(rectangle);
    texts.reserve(text);
}

void gestionSf::affichage(sf::RenderWindow &win)
{

    for(int b=0;b<rectangles.size();b++)
        win.draw(rectangles.at(b));
    for(int e=0;e<texts.size();e++)
        win.draw(texts.at(e));
    for(int a=0;a<sprites.size();a++)
        win.draw(sprites.at(a));

}

sf::Sprite gestionSf::getSprite(int num){
    return sprites.at(num);
}

void gestionSf::setPos_sprite(int num,sf::Vector2f pos){

sprites.at(num).setPosition(pos);

}

void gestionSf::creerSprite(std::string textureNom,sf::Vector2f position,sf::Vector2f taille)
{
    sf::Texture texture;
    texture.loadFromFile(textureNom);

    texture.setSmooth(qualite);

    textures.push_back(texture);
    sf::Sprite sprite;
    sprite.setTexture(textures.back());
    sprite.setPosition(position);
    sprite.setScale(taille);
    sprites.push_back(sprite);
}

long gestionSf::getTextSize(){return texts.size();}

void gestionSf::creerRectangle(sf::Vector2f position,sf::Vector2f taille,sf::Color couleur,float contour,sf::Color contourColor)
{
    sf::RectangleShape rect;
    rect.setPosition(position);
    rect.setSize(taille);
    rect.setFillColor(couleur);
    rect.setOutlineThickness(contour);
    if(contour!=0)
        rect.setOutlineColor(contourColor);
    rectangles.push_back(rect);
}

void gestionSf::modifRect(unsigned int num,sf::Vector2f taille,sf::Vector2f pos){
    rectangles.at(num).setSize(taille);
    rectangles.at(num).setPosition(pos);
}

void gestionSf::modifRectV2(int choix,sf::Color couleur){
    std::cout << "le choix est : " << choix << std::endl;
    for(int a=0;a<rectangles.size();a++)
        if(a!=choix)
            rectangles.at(a).setOutlineColor(sf::Color::White);

	if(choix>=0)
			rectangles.at(choix).setOutlineColor(couleur);
}

void gestionSf::creerTexte(std::string texte,sf::Vector2f position,unsigned int taille,sf::Color couleur)
{
    sf::Text text;
    text.setFont(font);
    text.setString(texte);
    text.setPosition(position);
    text.setCharacterSize(taille);
    text.setFillColor(couleur);
    texts.push_back(text);
}

void gestionSf::resetText(){
    texts.clear();
}

void gestionSf::resetRect(){
    rectangles.clear();
}

void gestionSf::modifText(unsigned int num,std::string texte){
    texts.at(num).setString(texte);
}

gestionSf::~gestionSf()
{
    std::cout << "desc gestionSF";
}
