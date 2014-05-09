/*
 * Object.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Charles Miller
 */

#include "Object.hpp"

int Object::n = 0;
sf::Texture Object::t;

Object::Object(sf::Vector2f s, sf::Color c, b2World& w, bool m, sf::Vector2f p)
{

	//n++;

	shape.setSize(s);
	shape.setOrigin(s.x/2, s.y/2);

	shape.setFillColor(c);

	bodyDef.type = b2_dynamicBody;

	if(p.x == 0)
		bodyDef.position.Set(getSfCoords(b2Vec2(400+15*n, 300)).x, getSfCoords(b2Vec2(400, 300)).y);
	else
		bodyDef.position.Set(p.x, p.y);

	//If this isn't set to '/' operand there's a likelihood that the object will be large and clip into other hitboxes. Making it impossible to move.
	dynamicBody.SetAsBox(toSf(shape.getSize().x), toSf(shape.getSize().y));

	fixtureDef.shape = &dynamicBody;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body = w.CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
}

Object::Object(std::string pa, b2World& w, sf::Vector2f pos)
{

	static bool isLoaded = false;

	if(!isLoaded)
	{
		std::cout << "Loaded";
		t.loadFromFile(pa);
		isLoaded = false;
	}

	shape.setPosition(pos);

	shape.setTexture(&t);
	shape.setSize(sf::Vector2f(t.getSize()));

	shape.setOrigin(t.getSize().x/2, t.getSize().y/2);

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(getSfCoords(b2Vec2(400+15*6, 300)).x, getSfCoords(b2Vec2(400, 300)).y);

	dynamicBody.SetAsBox(toB2(shape.getSize().x), toB2(shape.getSize().y) );

	fixtureDef.shape = &dynamicBody;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body = w.CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
}

void Object::update()
{
	shape.setPosition(toSf(body->GetPosition().x), toSf(body->GetPosition().y));
	shape.setRotation(body->GetAngle());
}

void Object::draw(sf::RenderWindow& app)
{
	app.draw(shape);
}

Object::~Object(){}

