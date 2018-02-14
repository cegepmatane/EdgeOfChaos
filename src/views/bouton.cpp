# include <iostream>
# include <string>
# include <SFML/Graphics.hpp>

# if defined (linux)
	# include "../../systemes/interfaceDebian.h"
# elif (_WIN64)
	# include "../../systemes/interfaceWindows.h"
# endif
# include "../../inclusion/bouton.h"

Bouton::Bouton(int hauteur, int longueur, std::string texte, const std::string& police) : RectangleShape(sf::Vector2f(hauteur - sf::VideoMode::getDesktopMode().width / 426.0 * 2, longueur - sf::VideoMode::getDesktopMode().width / 426.0 * 2))
{
	this->setFillColor(sf::Color::White);
	initBordure(sf::Color::Black);	
	initContenu(texte, police);
}

void Bouton::initBordure(const sf::Color& couleur)
{
	this->bordure = sf::VideoMode::getDesktopMode().width / 426.0;
	this->setOutlineThickness(this->bordure);
	this->setOutlineColor(couleur);
}

void Bouton::initContenu(std::string& texte, const std::string& policeBoutons)
{
	if(!(this->police.loadFromFile(Configuration::cheminPolices + policeBoutons))){
		std::cerr << "Impossible de charger la police du bouton. \n ( " << Configuration::cheminPolices + policeBoutons << " )" << std::endl;
	}
	this->contenu.setFont(police);
	this->contenu.setString(texte);
	this->contenu.setCharacterSize(this->getSize().y - this->getSize().y / 6);
	this->contenu.setFillColor(sf::Color::Black);
}

void Bouton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw((RectangleShape)(*this));	// Caster, sinon, affichage récursif de tous les composant de l'instance de la classe.
	target.draw(this->contenu);
}

void Bouton::setBtnPosition(float x, float y)
{
	x += this->bordure;
	y += this->bordure;
	this->setPosition(x, y);
	this->contenu.setPosition(x, y - 12);
}

const sf::Vector2f Bouton::getPosition(){
	return sf::Vector2f(((RectangleShape)(*this)).getPosition().x - this->bordure, ((RectangleShape)(*this)).getPosition().y - this->bordure);
}

const sf::Vector2f Bouton::getSize(){
	return sf::Vector2f(((RectangleShape)(*this)).getSize().x + this->bordure * 2,((RectangleShape)(*this)).getSize().y + this->bordure * 2);
}
