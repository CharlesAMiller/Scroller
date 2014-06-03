/*
 * Base.hpp
 *
 *  Created on: May 27, 2014
 *      Author: Charles "Porthog" Miller
 */

//TODO: What is the purpose of this header exactly?

#ifndef BASE_HPP_
#define BASE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

struct Body
{
	sf::RectangleShape shape;

	b2Body* body;

	//TODO: Generic Shapes?
	b2PolygonShape dynamicBody;

	b2BodyDef bodyDef;

	b2FixtureDef fixtureDef;

};

#endif /* BASE_HPP_ */
