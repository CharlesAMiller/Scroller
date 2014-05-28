/*
 * Drawable.cpp
 *
 *  Created on: May 27, 2014
 *      Author: Charles Miller
 */

#include "Drawable.hpp"

Drawable::Drawable(bool drawOutOfView)
{
	this->drawOutOfView = drawOutOfView;
}

Drawable::~Drawable(){}

void Drawable::draw(sf::RenderWindow& app)
{
	//if(shouldDraw())
}

bool Drawable::shouldDraw(sf::RectangleShape& v, sf::RectangleShape d)
{
	if(v.getGlobalBounds().intersects(d.getGlobalBounds()))
	{
		return true;
	}

	return false;
}
