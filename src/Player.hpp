/*
 * Player.hpp
 *
 *  Created on: May 6, 2014
 *      Author: Charles Miller
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "Object.hpp"

class Player : Object
{

public:

	Player(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p = sf::Vector2f(0,0));

	Player(std::string pa, b2World& w, sf::Vector2f pos = sf::Vector2f(0,0));

	virtual void update(sf::Event e);

	virtual void draw(sf::RenderWindow& app);

	virtual sf::RectangleShape getShape();

	virtual ~Player();

	sf::Clock timer;

};



#endif /* PLAYER_HPP_ */
