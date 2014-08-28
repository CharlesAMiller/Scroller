/*
 * Crate.hpp
 *
 *  Created on: Jul 27, 2014
 *      Author: Charles Miller
 */

#ifndef CRATE_HPP_
#define CRATE_HPP_

#include "../Object.hpp"

class Crate : Object
{

public:

	Crate(b2World& w, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(70, 70));

	virtual void update();

	virtual void draw(sf::RenderWindow& app);

	virtual sf::RectangleShape getShape();

	virtual unsigned int getType();

	~Crate();

private:

	static sf::Texture crateTexture;

};



#endif /* CRATE_HPP_ */
