/*
 * Object.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Charles Miller
 */

#include "Object.hpp"

int Object::n = 0;

sf::Texture Object::objectTexture;

Object::Object(sf::Vector2f s, sf::Color c, b2World& w, sf::Vector2f p)
{

	n++;

	shape.setSize(s);
	shape.setOrigin(s.x/2, s.y/2);

	shape.setFillColor(c);

	bodyDef.type = b2_dynamicBody;

	if(p.x == 0)
		bodyDef.position.Set(300.0f/30, -300.0f/30-n*5/30);
	else
		bodyDef.position.Set(p.x/30, p.y/30);

	dynamicBody.SetAsBox(10.0f/30, 10.0/30);

	fixtureDef.shape = &dynamicBody;
	fixtureDef.density = 0.3f;
	fixtureDef.friction = 0.5f;

	body = w.CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);

	hitbox.setSize(shape.getSize());
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setPosition(shape.getPosition());
	hitbox.setOutlineThickness(1);
}

Object::Object(std::string pa, b2World& w, sf::Vector2f pos)
{

	static bool isLoaded = false;

	if(!isLoaded)
	{
		isLoaded = true;
		objectTexture.loadFromFile(pa);
	}

	shape.setPosition(pos);

	shape.setSize(sf::Vector2f(objectTexture.getSize().x, objectTexture.getSize().y));
	shape.setTexture(&objectTexture);

	shape.setOrigin(objectTexture.getSize().x/2, objectTexture.getSize().y/2);

	bodyDef.type = b2_dynamicBody;

	if(pos.x == 0)
		bodyDef.position.Set(300.0f/30, -300.0f/30-n*5/30);
	else
		bodyDef.position.Set(pos.x/30, pos.y/30);

	dynamicBody.SetAsBox((objectTexture.getSize().x/2)/32, (objectTexture.getSize().y/2)/32);

	fixtureDef.shape = &dynamicBody;
	fixtureDef.density = 0.3f;
	fixtureDef.friction = 0.5f;

	body = w.CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);

	hitbox.setSize(shape.getSize());
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setPosition(shape.getPosition());
	hitbox.setOutlineThickness(1);
}

Object::Object(b2World& w, sf::Vector2f pos)
{
	bodyDef.type = b2_dynamicBody;

	fixtureDef.shape = &dynamicBody;
	fixtureDef.density = 0.3f;
	fixtureDef.friction = 0.5f;

	//TODO Find a way to get rid of this. We want it to be dynamic.
	dynamicBody.SetAsBox((72/2)/32, (97/2)/32);

	body = w.CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);

}

void Object::update()
{
	shape.setPosition(body->GetPosition().x*30, body->GetPosition().y*30);
	shape.setRotation(getAngleDegrees(body->GetAngle()));
}

void Object::draw(sf::RenderWindow& app)
{
	app.draw(shape);
	if(debug)
	{
		app.draw(hitbox);
	}
}

Object::~Object(){}

sf::RectangleShape Object::getShape()
{
	return shape;
}
