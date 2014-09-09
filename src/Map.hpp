/*
 * Map.hpp
 *
 *  Created on: Jun 6, 2014
 *      Author: Charles Miller
 */

#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include "Terrain/Terrains.hpp"

#include "Object.hpp"

#include <map>

class Map
{
public:

	Map(std::string p = "map.png");

	~Map();

	void load();

	sf::Vector2f getPlayerSpawn();

	void populate(b2World& w, std::vector<Terrain*>& t, std::vector<Object*>& o);

private:

	std::vector<sf::Color> mapVals;

	//TODO: Fix this piece of shit.
	std::map<sf::Color, int> pixelMap;

	std::string m_p;

	sf::Vector2u mapSize;

	std::vector<int> m_map;

	unsigned int curType;

	std::vector<std::vector< std::pair<sf::Vector2u, sf::Vector2f> > > consecutiveTiles;


};




#endif /* MAP_HPP_ */
