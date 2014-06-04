/*
 * Player.cpp
 *
 *  Created on: May 6, 2014
 *      Author: Charles Miller
 */

#include "Player.hpp"

sf::Texture Player::playerTexture;

Player::Player(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p):
	Object(s, c, w, p)
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;

}

Player::Player(std::string pa, b2World& w, sf::Vector2f pos):
	Object(w, pos)
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;

	playerTexture.loadFromFile("res/player.png");

	shape.setTexture(&playerTexture);
	shape.setSize(sf::Vector2f(playerTexture.getSize()));

	shape.setOrigin(sf::Vector2f(playerTexture.getSize().x/2, playerTexture.getSize().y/2));

	//dynamicBody.SetAsBox(toB2(playerTexture.getSize().x), toB2(playerTexture.getSize().y));
}

void Player::update(sf::Event e)
{

	float vMod, temp = 0;
	bool toJump = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && jumptimer.getElapsedTime().asSeconds() > .2)
	{
		timer.restart();
		jumptimer.restart();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(body->GetLinearVelocity().x > -12)
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x - 2, body->GetLinearVelocity().y));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(body->GetLinearVelocity().x < 12)
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x + 2, body->GetLinearVelocity().y));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dynamicBody.SetAsBox((shape.getSize().x/2)/30, ((shape.getSize().y/2)/30) - objectTexture.getSize().y*.2);
	}

	if(e.type == sf::Event::KeyReleased)
	{
		if(e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)
		{
			body->SetLinearVelocity(b2Vec2(0, body->GetLinearVelocity().y));
		}

		if(e.key.code == sf::Keyboard::Up)
		{
			temp = timer.getElapsedTime().asSeconds();
			toJump = true;
		}

	}


	if(toJump)
	{
		if(temp < .35)
		{
			vMod = .33;
		}
		else if(temp > .35 && temp < .8)
		{
			vMod = .75;
		}
		else if(temp > .8)
		{
			vMod = 1;
		}

		//TODO Make a variable for maxHeight;
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, 8 * vMod));

		toJump = false;
	}

	shape.setPosition(getSfCoords(body->GetPosition()));
	//shape.setRotation(getAngleDegrees(body->GetAngle()));

	//hitbox.setPosition(toSf(body->GetPosition().x), toSf(body->GetPosition().y));
}

void Player::draw(sf::RenderWindow& app)
{
	app.draw(shape);

	if(debug)
		app.draw(hitbox);
}

Player::~Player(){}

sf::RectangleShape Player::getShape()
{
	return shape;
}
