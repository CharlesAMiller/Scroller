/*
 * Object.hpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Charles Miller
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

#include <Box2D/Box2D.h>
#include "sub/b2toSf.hpp"

class Object
{

public:

	//size, color
	Object(sf::Vector2f s, sf::Color c, b2World& w, bool m, sf::Vector2f pos = sf::Vector2f(0, 0));

	//path
	Object(std::string pa, b2World&, sf::Vector2f pos = sf::Vector2f(0,0));

	sf::RectangleShape getShape();

	//Player
	virtual void update();

	virtual void draw(sf::RenderWindow& app);

	virtual ~Object();

	sf::RectangleShape shape, hitbox;

	static int n;

	static sf::Texture t;

	const bool debug = true;

	b2Body* body;

private:

	b2BodyDef bodyDef;

	b2PolygonShape dynamicBody;

	b2FixtureDef fixtureDef;
};

#endif /* OBJECT_HPP_ */
