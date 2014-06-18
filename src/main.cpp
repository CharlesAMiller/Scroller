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

#include "Box2DDebugDrawer/Box2DDebugDrawer.h"

#include "sub/b2toSf.hpp"

#include "Object.hpp"
#include "Player.hpp"

#include "Terrain/Terrains.hpp"

#include "Map.hpp"

sf::RectangleShape ground;

sf::Texture t;

int main()
{

	t.loadFromFile("res/grass.png");

	sf::ContextSettings cs;
	cs.antialiasingLevel = 16;

	sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Scroller", sf::Style::Default, cs);

	app.setFramerateLimit(60);

	sf::Event event;

	b2Vec2 gravity (0.0f, -9.8f);
	b2World world(gravity);


	Box2DDebugDrawer drawer(&app);

	world.SetDebugDraw(&drawer);

	bool debug = false;

	sf::View v(sf::Vector2f(400, 300), sf::Vector2f(800, 600));

	app.setView(v);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("res/bg.png");
	backgroundTexture.setRepeated(true);

	sf::RectangleShape backgroundShape;
	backgroundShape.setTexture(&backgroundTexture);
	backgroundShape.setSize(sf::Vector2f(4000, 4000));
	backgroundShape.setOrigin(sf::Vector2f(2000, 2000));
	backgroundShape.setPosition(sf::Vector2f(0, 0));

	std::vector<Object*> objects;

	std::vector<Terrain*> environment;

	Map m("map.png");

	m.load();
	m.populate(world, environment);

	const int boxes = 10;
	for(unsigned int i = 0; i < boxes; i++)
	{
		Object* o = new Object("res/box.png", world);
		objects.push_back(o);
	}


	//Player p ("res/player.png", world, sf::Vector2f(50,0));

	Player p("res/player.png", world, sf::Vector2f(50,0));

	//Player p(sf::Vector2f(10,10), sf::Color::Magenta, world);

	float step = 1/60.0f;
	while(app.isOpen())
	{
		app.pollEvent(event);

		app.setView(v);

		if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			app.close();
		}

		world.Step(step, 8, 3);

		for(unsigned int i = 0; i < objects.size(); i++)
		{
			objects.at(i)->update();
		}

		app.clear(sf::Color::White);

		p.update(event);

		app.draw(backgroundShape);

		for(unsigned int i = 0; i < environment.size(); i++)
		{
			environment.at(i)->draw(app);
		}
		for(unsigned int i = 0; i < objects.size(); i++)
		{
			objects.at(i)->draw(app);
		}

		bool moveWith = true;

		if(moveWith)
		{
			v.setCenter(p.getShape().getPosition());
		}

		p.draw(app);

		app.draw(ground);

		if(debug)
		world.DrawDebugData();

		app.display();

		sf::sleep(sf::milliseconds(5));
	}

}
