/*
 * Game.cpp
 *
 *  Created on: Jul 8, 2014
 *      Author: Charles Miller
 */

#include "Game.hpp"

Game::Game():
	//Set the antialiasing of the Context Settings
	cs(0, 0, 16, 2, 0),
	app(sf::VideoMode(800, 600, 32), "Scroller", sf::Style::Close, cs),

	world(b2Vec2(0.0f, -19.6f)),

	v(sf::Vector2f(400, 300), sf::Vector2f(800, 600)),

	p("res/player.png", world, sf::Vector2f(1,1000)),

	drawer(&app),

	m("map.png")

{

		app.setFramerateLimit(60);

		world.SetDebugDraw(&drawer);

		world.SetContactListener(&cl);

		app.setView(v);

		moveWith = true;

		step = 1/60.0f;

		backgroundTexture.loadFromFile("res/bg.png");
		backgroundTexture.setRepeated(true);

		backgroundShape.setTexture(&backgroundTexture);
		backgroundShape.setSize(sf::Vector2f(4000, 4000));
		backgroundShape.setOrigin(sf::Vector2f(2000, 2000));
		backgroundShape.setPosition(sf::Vector2f(0, 0));

		m.load();
		m.populate(world, environment, objects);

}

Game::~Game(){}

void Game::run()
{

	while(app.isOpen())
	{
		getInput();
		update();
		draw();
	}
}

void Game::update()
{
	app.setView(v);

	world.Step(step, 8, 3);

	for(unsigned int i = 0; i < objects.size(); i++)
	{
		objects.at(i)->update();
	}

	for(unsigned int i = 0; i < environment.size(); i++)
	{
		environment.at(i)->update();
	}

	if(moveWith){	v.setCenter(p.getPosition());	}

}

void Game::getInput()
{

	app.pollEvent(event);

	if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		app.close();
	}

	p.update(event);
}

void Game::draw()
{
	app.clear(sf::Color::White);

	app.draw(backgroundShape);

	for(unsigned int i = 0; i < objects.size(); i++)
	{
		objects.at(i)->draw(app);
	}

	for(unsigned int i = 0; i < environment.size(); i++)
	{
		environment.at(i)->draw(app);
	}

	p.draw(app);

	//world.DrawDebugData();

	app.display();

	sf::sleep(sf::milliseconds(5));
}

