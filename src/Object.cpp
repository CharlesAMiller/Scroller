/*
 * Object.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Charles Miller
 */

#include "Object.hpp"

int Object::n = 0;
sf::Texture Object::t;

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

	//if(!isLoaded)
	//{
		std::cout << "Loaded";
		t.loadFromFile(pa);
		isLoaded = false;
	//}

	shape.setPosition(pos);

	shape.setTexture(&t);
	shape.setSize(sf::Vector2f(t.getSize()));

	shape.setOrigin(t.getSize().x/2, t.getSize().y/2);

	bodyDef.type = b2_dynamicBody;

	if(pos.x == 0)
		bodyDef.position.Set(300.0f/30, -300.0f/30-n*5/30);
	else
		bodyDef.position.Set(pos.x/30, pos.y/30);

	dynamicBody.SetAsBox((t.getSize().x/2)/30, (t.getSize().y/2)/30);

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
