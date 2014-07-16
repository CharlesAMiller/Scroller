/*
 * Game.hpp
 *
 *  Created on: Jul 8, 2014
 *      Author: Charles Miller
 */

#ifndef GAME_HPP_
#define GAME_HPP_

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

#include "sub/file.h"

#include "XboxController.h"

class Game
{
public:

	Game();

	~Game();

	void run();

private:

	void update();
	void getInput();
	void draw();

	//void init();

private:

	sf::ContextSettings cs;
	sf::RenderWindow app;

	sf::RectangleShape backgroundShape;
	sf::Texture backgroundTexture;

	b2World world;

	sf::Event event;

	sf::View v;

	Box2DDebugDrawer drawer;

	Map m;

	std::vector<Object*> objects;
	std::vector<Terrain*> environment;

	Player p;

	bool moveWith;
	float step;

};



#endif /* GAME_HPP_ */
