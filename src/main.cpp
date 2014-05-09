/*
 * main.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Charles Miller
 */

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "Object.hpp"

#include "Player.hpp"

sf::RectangleShape ground;

void createGround(b2World* w);

int main()
{
	sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Scroller");
	sf::Event event;

	b2Vec2 gravity (0.0f, 9.8f);
	b2World world(gravity);

	sf::View v(sf::Vector2f(400, 300), sf::Vector2f(800, 600));

	app.setView(v);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("bg_castle.png");
	backgroundTexture.setRepeated(true);

	sf::RectangleShape backgroundShape;
	backgroundShape.setTexture(&backgroundTexture);
	backgroundShape.setSize(sf::Vector2f(1000, 800));
	backgroundShape.setPosition(sf::Vector2f(0, 0));

	std::vector<Object*> objects;

	createGround(&world);

	const int boxes = 5;
	for(unsigned int i = 0; i < boxes; i++)
	{
		Object* o = new Object(sf::Vector2f(10,10), sf::Color::Green, world, true, sf::Vector2f(getSfCoords(b2Vec2(400+15*i, 300)).x, getSfCoords(b2Vec2(400, 300)).y));
		objects.push_back(o);
	}

	Player p (sf::Vector2f(15,15), sf::Color::Magenta, world);

	sf::Clock timer;

	while(app.isOpen())
	{
		app.pollEvent(event);

		app.setView(v);

		if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			app.close();
		}

		/*if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer.getElapsedTime().asSeconds() > .2)
		{
			Object* o = new Object(sf::Vector2f(10, 10), sf::Color::Red, world, true, sf::Vector2f(toB2(sf::Mouse::getPosition().x), toB2(sf::Mouse::getPosition(app).y)));
			objects.push_back(o);
			timer.restart();
		}*/

		world.Step(1/180.0f, 8, 3);

		world.DrawDebugData();

		p.update();

		for(unsigned int i = 0; i < objects.size(); i++)
		{
			objects.at(i)->update();
		}

		app.clear(sf::Color::White);

		app.draw(backgroundShape);

		for(unsigned int i = 0; i < objects.size(); i++)
		{
			objects.at(i)->draw(app);
		}

		p.draw(app);

		app.draw(ground);
		app.display();
	}

}

void createGround(b2World* w)
{
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape shape;

	bodyDef.position.Set(toB2(100), toB2(400));
	body = w->CreateBody(&bodyDef);

	shape.SetAsBox(toB2(400), toB2(5));

	body->CreateFixture(&shape, 0.0f);

	ground.setSize(sf::Vector2f(400,40));
	ground.setFillColor(sf::Color::Cyan);
	ground.setPosition(toSf(body->GetPosition().x), toSf(body->GetPosition().y));
}

