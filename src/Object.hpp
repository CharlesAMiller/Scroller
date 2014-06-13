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
	Object(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f pos = sf::Vector2f(0, 0));

	//path
	Object(std::string pa, b2World& w, sf::Vector2f pos = sf::Vector2f(0,0));

	//Used to apply to an already existing texture
	Object(b2World& w, sf::Vector2f pos = sf::Vector2f(0,0));

	//Player
	virtual void update();

	virtual void draw(sf::RenderWindow& app);

	virtual sf::RectangleShape getShape();

	virtual ~Object();

	sf::RectangleShape shape, hitbox;

	static int n;

	static sf::Texture objectTexture;

	const bool debug = false;


	//TODO Move these back to private and sort all of that out.

	b2Body* body;

	b2PolygonShape dynamicBody;

	b2BodyDef bodyDef;

private:


	b2FixtureDef fixtureDef;

};

#endif /* OBJECT_HPP_ */
