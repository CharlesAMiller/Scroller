/*
 * Player.cpp
 *
 *  Created on: May 6, 2014
 *      Author: Charles Miller
 */

#include "Player.hpp"

sf::Texture Player::playerTexture;

sf::Texture Player::playerSpriteSheet;

Player::Player(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p):
	Object(s, c, w, p),
	m_anim(),
	xbox(0)
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;

	left = false;
	right = false;

}

Player::Player(std::string pa, b2World& w, sf::Vector2f pos):
	Object(w, pos),
	m_anim(),
	m_sprite(),
	xbox(0)
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;

	playerTexture.loadFromFile("res/player.png");

	shape.setTexture(&playerTexture);
	shape.setSize(sf::Vector2f(playerTexture.getSize()));

	shape.setOrigin(sf::Vector2f(playerTexture.getSize().x/2, playerTexture.getSize().y/2));


	playerSpriteSheet.loadFromFile("p1_spritesheet.png");

	//shape.setTexture(&playerSpriteSheet);

	walkingAnim.setSpriteSheet(playerSpriteSheet);
	walkingAnim.addFrame(sf::IntRect(sf::Vector2i(72*2, 97), sf::Vector2i(72, 97)));
	walkingAnim.addFrame(sf::IntRect(sf::Vector2i(72*3, 97), sf::Vector2i(72, 97)));

	curFrame = 0;

	m_anim = walkingAnim;

	m_sprite.setAnimation(m_anim);

	left = false;
	right = false;
}

void Player::update(sf::Event e)
{

	sf::Clock animTimer;

	float vMod;

	bool toJump = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && jumptimer.getElapsedTime().asSeconds() > .2)
	{

		if(body->GetLinearVelocity().y < 0.05 && body->GetLinearVelocity().y > -.05)
		{
			body->ApplyForceToCenter(b2Vec2(0, 1000), true);
			//body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, body->GetLinearVelocity().y + 12));
			jumptimer.restart();
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		|| xbox.leftStickX() > 0.35)
	{
		if(body->GetLinearVelocity().x < 12)
		{
			right = true;
			body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x + 2, body->GetLinearVelocity().y));

			//shape.setScale(sf::Vector2f(1,1));

			if(animTimer.getElapsedTime().asSeconds() > .02)
			{
				if(curFrame < walkingAnim.getSize())
				{
					curFrame++;
					//shape.setTextureRect(walkingAnim.getFrame(curFrame));
				}
				else
				{
					curFrame = 0;
				}
			}

		}

	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(body->GetLinearVelocity().x > -12)
		{
			//body->SetLinearVelocity(iv);
			left = true;
			body->ApplyForceToCenter(b2Vec2(-100, 0), true);
			//body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x - 2, body->GetLinearVelocity().y));
			//m_sprite.setScale(sf::Vector2f(-1, 1));

			if(animTimer.getElapsedTime().asSeconds() > .02)
			{
				if(curFrame < walkingAnim.getSize())
				{
					curFrame++;
					//shape.setTextureRect(walkingAnim.getFrame(curFrame));
				}
				else
				{
					curFrame = 0;
				}
			}
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dynamicBody.SetAsBox((shape.getSize().x/2)/30, ((shape.getSize().y/2)/30) - objectTexture.getSize().y*.2);
		fixtureDef.shape = &dynamicBody;
	}

	if(e.type == sf::Event::KeyReleased)
	{
		if(e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)
		{
			if(e.key.code == sf::Keyboard::Right)
			{
				right = false;
			}
			else if(e.key.code == sf::Keyboard::Left)
			{
				left = false;
			}

			if(right && !left)
			{
				body->ApplyForceToCenter(b2Vec2(20, 0), true);
			}
			else if(!right && left)
			{
				body->ApplyForceToCenter(b2Vec2(-20, 0), true);
			}
			else
			{
				body->SetLinearVelocity(b2Vec2(0, body->GetLinearVelocity().y));
			}
		}

		/*if(e.key.code == sf::Keyboard::Up)
		{
			temp = timer.getElapsedTime().asSeconds();
			toJump = true;
		}*/
	}

	if(toJump)
	{

		vMod = 1;

		//TODO Make a variable for maxHeight;
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, 8 * vMod));

		jumptimer.restart();
		toJump = false;
	}

	shape.setPosition(getSfCoords(body->GetPosition()));
	//shape.setRotation(getAngleDegrees(body->GetAngle()));

	//hitbox.setPosition(toSf(body->GetPosition().x), toSf(body->GetPosition().y));
}

void Player::draw(sf::RenderWindow& app)
{
	app.draw(shape);
}

Player::~Player(){}

sf::RectangleShape Player::getShape()
{
	return shape;
}
