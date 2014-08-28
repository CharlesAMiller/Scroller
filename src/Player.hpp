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

#include "AnimatedSprite.h"

#include "XboxController.h"

class Player : Object
{

public:

	Player(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p = sf::Vector2f(0,1000));

	Player(std::string pa, b2World& w, sf::Vector2f pos = sf::Vector2f(0,10000));

	virtual void update(sf::Event e);

	virtual void draw(sf::RenderWindow& app);

	virtual sf::Vector2f getPosition();

	virtual unsigned int getType();

	virtual ~Player();

	sf::Clock timer;

	sf::Clock jumptimer;

	sf::Clock animTimer;

	XboxController xbox;


private:

	Animation m_anim, walkingAnim;

	bool right, left;

	static sf::Texture playerTexture;

	static sf::Texture playerSpriteSheet;

	AnimatedSprite m_sprite;

};



#endif /* PLAYER_HPP_ */
