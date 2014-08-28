/*
 * Crate.cpp
 *
 *  Created on: Aug 3, 2014
 *      Author: Charles Miller
 */

#include "Crate.hpp"

sf::Texture Crate::crateTexture;

Crate::Crate(b2World& w, sf::Vector2f pos, sf::Vector2f size):
	Object(w, pos)
{

}

void Crate::update(){}

void Crate::draw(sf::RenderWindow& app){}

sf::RectangleShape Crate::getShape()
{
	return shape;
}

unsigned int Crate::getType()
{
	return 0;
}

Crate::~Crate(){}

