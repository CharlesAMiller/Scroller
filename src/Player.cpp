/*
 * Player.cpp
 *
 *  Created on: May 6, 2014
 *      Author: Charles Miller
 */

#include "Player.hpp"

Player::Player(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p):
	Object(s, c, w, true, p)
{
}

Player::Player(std::string pa, b2World& w):
	Object("player.png", w)
{
}

void Player::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		body->ApplyForce(b2Vec2(0, -50), body->GetWorldCenter(), true);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		body->ApplyForce(b2Vec2(-50, 0), body->GetWorldCenter(), true);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		body->ApplyForce(b2Vec2(50, 0), body->GetWorldCenter(), true);
	}

	shape.setPosition(toSf(body->GetPosition().x), toSf(body->GetPosition().y));
}

void Player::draw(sf::RenderWindow& app)
{
	app.draw(shape);
}

Player::~Player(){}
