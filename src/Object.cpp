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
		bodyDef.position.Set(toB2(300), -toB2(300.0f/30-n*5));
	else
		bodyDef.position.Set(toB2(p.x), -toB2(p.y));

	dynamicBody.SetAsBox(toB2(10.0f), toB2(10.0f));

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

Object::Object(std::string pa, b2World& w, b2Shape::Type t, sf::Vector2f pos)
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


	//switch(t)
	//{
		//Circle
		//case 0:
			//fixtureDef.shape = new b2CircleShape;


	//}

	bodyDef.type = b2_dynamicBody;

	if(pos.x == 0)
		bodyDef.position.Set(toB2(300), -toB2(300));
	else
		bodyDef.position.Set(toB2(pos.x), -toB2(pos.y));

	dynamicBody.SetAsBox(toB2((objectTexture.getSize().x/2)-1), toB2((objectTexture.getSize().y/2)));

	fixtureDef.shape = &dynamicBody;
	fixtureDef.density = 0.85f;
	//fixtureDef.restitution = 0.01f;
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
	dynamicBody.SetAsBox(toB2(34/2), toB2(97/2));

	//bodyDef.position = b2Vec2(toB2(0), toB2(10000));

	bodyDef.fixedRotation = true;

	body = w.CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);

}

void Object::update()
{
	shape.setPosition(getSfCoords(body->GetPosition()));
	shape.setRotation(-getAngleDegrees(body->GetAngle()));
}

void Object::draw(sf::RenderWindow& app)
{
	app.draw(shape);
}

Object::~Object(){}

sf::RectangleShape Object::getShape()
{
	return shape;
}
