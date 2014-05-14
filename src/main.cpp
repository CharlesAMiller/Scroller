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

	const int boxes = 200;
	for(unsigned int i = 0; i < boxes; i++)
	{
		Object* o = new Object(sf::Vector2f(10,10), sf::Color::Green, world, true);
		objects.push_back(o);
	}

	//Player p ("box.png", world, sf::Vector2f(50,0));

	Player p(sf::Vector2f(15,15), sf::Color::Magenta, world);

	sf::Clock timer;

	float step = 1/360.0f;
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

		world.Step(step, 8, 3);

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
	b2FixtureDef fixtureDef;

	fixtureDef.density = 0.7;
	fixtureDef.friction = 0.9;
	bodyDef.position.Set(100.0f/30, 400.0f/30);
	body = w->CreateBody(&bodyDef);

	shape.SetAsBox(400.0f/30, 10.0/30);

	body->CreateFixture(&shape, 0.0f);


	ground.setSize(sf::Vector2f(400,40));
	ground.setFillColor(sf::Color::Cyan);
	ground.setPosition(body->GetPosition().x*30, body->GetPosition().y*30);
}

