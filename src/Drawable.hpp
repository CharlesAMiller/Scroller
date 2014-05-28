/*
 * Drawable.hpp
 *
 *  Created on: May 27, 2014
 *      Author: Charles Miller
 */

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class Drawable
{

public:

	Drawable(bool drawOutOfView = false);

	virtual ~Drawable();

	virtual void draw(sf::RenderWindow& app);

	bool shouldDraw(sf::RectangleShape& v, sf::RectangleShape d);

protected:

	//TODO is this where this should exist? And should it be protected?
	sf::RectangleShape shape;

	bool drawOutOfView;
};



#endif /* DRAWABLE_HPP_ */
