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
	m_anim()
{
	timer.restart();

	//Player specific
	bodyDef.fixedRotation = true;

	animTimer.restart();

	left = false;
	right = false;

}

Player::Player(std::string pa, b2World& w, sf::Vector2f pos):
	Object(w, pos)
{
	timer.restart();

	m_type = player;

	//Player specific
	bodyDef.fixedRotation = true;

	playerSpriteSheet.loadFromFile("res/p1_spritesheet.png");

	walkingAnim.setSpriteSheet(playerSpriteSheet);

	walkingAnim.addFrame(sf::IntRect(288, 0, 72, 97));
	walkingAnim.addFrame(sf::IntRect(145, 0, 72, 97));
	walkingAnim.addFrame(sf::IntRect(217, 0, 72, 97));

	m_sprite.setAnimation(walkingAnim);

	m_sprite.setOrigin(sf::Vector2f(72/2, 97/2));

	left = false;
	right = false;

	animTimer.restart();


	body->SetUserData(this);
}

void Player::update(sf::Event e)
{

	float vMod;

	bool toJump = false;

	bool runAnim;

	sf::Joystick::update();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		|| xbox.buttonA())
	{
		if(jumptimer.getElapsedTime().asSeconds() > .2)
		{

			if(body->GetLinearVelocity().y < 0.05 && body->GetLinearVelocity().y > -.05)
			{
				body->ApplyForceToCenter(b2Vec2(0, 1000), true);
				//body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, body->GetLinearVelocity().y + 12));
				jumptimer.restart();
			}

		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		|| xbox.leftStickX() >= 0.45)
	{
		runAnim = true;

		if(timer.getElapsedTime().asSeconds() > 0.2)
		{
			right = true;
			//body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x + 2, body->GetLinearVelocity().y));
			b2Vec2 newVelocity = b2Vec2(0.35 * 30 + (1 - 0.35) * body->GetLinearVelocity().x, body->GetLinearVelocity().y);

			timer.restart();

			body->SetLinearVelocity(newVelocity);
		}

	}

	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		|| xbox.leftStickX() <= -0.45)
	{
		runAnim = true;

		if(timer.getElapsedTime().asSeconds() > 0.2)
		{
			left = true;

			b2Vec2 newVelocity = b2Vec2(0.35 * -30 + (1 - 0.35) * body->GetLinearVelocity().x, body->GetLinearVelocity().y);

			body->SetLinearVelocity(newVelocity);
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dynamicBody.SetAsBox((shape.getSize().x/2)/30, ((shape.getSize().y/2)/30) - objectTexture.getSize().y*.2);
		fixtureDef.shape = &dynamicBody;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Player Velocity: " << body->GetLinearVelocity().x << "\n";
	}

	if(e.type == sf::Event::KeyReleased)
	{
		if(e.key.code == sf::Keyboard::Left || e.key.code == sf::Keyboard::Right)
		{
			if(e.key.code == sf::Keyboard::Right)
			{
				right = false;
				runAnim = false;
			}
			else if(e.key.code == sf::Keyboard::Left)
			{
				left = false;
				runAnim = false;
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

	}

	m_sprite.update(sf::seconds(1.4));

	if(runAnim && animTimer.getElapsedTime().asSeconds() > .44)
	{
		m_sprite.play();
		animTimer.restart();
	}
	else
	{
		m_sprite.stop();
	}

	if(toJump)
	{

		vMod = 1;

		//TODO Make a variable for maxHeight;
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, 8 * vMod));

		jumptimer.restart();
		toJump = false;
	}

	m_sprite.setPosition(getSfCoords(body->GetPosition()));

}

void Player::draw(sf::RenderWindow& app)
{
	app.draw(m_sprite);
}

sf::Vector2f Player::getPosition()
{
	return m_sprite.getPosition();
}

unsigned int Player::getType()
{
	return m_type;
}

Player::~Player(){}
