/*
 * Map.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: Charles Miller
 */

#include "Map.hpp"

Map::Map(std::string p)
{

	//std::map<int, sf::Color, VectorComparator> pixelMap;

	//pixelMap[sf::Color(1,1,1)] = 1;
	//pixelMap.insert(std::pair<sf::Color, int>(sf::Color(1,1,1), 1));

	//pixelMap[2] = 1;
	//pixelMap[3] = 2;

	//terrainMap[1] = grass;
	//terrainMap[2] = ice;

	//	Air & Default
	mapVals.push_back(sf::Color(0,0,0));
	//	Grass
	mapVals.push_back(sf::Color(34, 177, 76));
	// Ice
	mapVals.push_back(sf::Color(153, 217, 234));

	m_p = p;
}

void Map::load()
{
	sf::Image m_image;

	m_image.loadFromFile(m_p);

	mapSize = m_image.getSize();

	for(unsigned int i = 0; i < m_image.getSize().y; i++)
	{
		for(unsigned int j = 0; j < m_image.getSize().x; j++)
		{

			sf::Color pixel = m_image.getPixel(j, i);

			for(unsigned int l = 0; l < mapVals.size(); l++)
			{
				if(pixel == mapVals.at(l))
				{
					m_map.push_back(l);
				}
				else if(l > 1)
				{
					m_map.push_back(0);
				}

			}
		}
	}
}

void Map::populate(b2World& w, std::vector<Terrain*>& t)
{
	unsigned int x = 0 ,y = 0, temp = 0;

	for(unsigned int i = 0; i < m_map.size(); i++)
	{
		temp++;

		if(temp > mapSize.x)
		{
			y++;
			temp = 0;
		}

		x = temp;

		if(m_map[i] == 1)
		{
			Grass* g = new Grass("res/grass.png", w , sf::Vector2f(70, 70), sf::Vector2f(x*70, y*70), true);
			t.push_back(g);
		}

		if(m_map[i] == 2)
		{
			Ice* i = new Ice("res/ice.png", w , sf::Vector2f(70, 70), sf::Vector2f(x*70, y*70), true);
			t.push_back(i);
		}


	}
}

Map::~Map(){}
