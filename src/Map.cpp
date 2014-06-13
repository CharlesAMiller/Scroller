/*
 * Map.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: Charles Miller
 */

#include "Map.hpp"


Map::Map(std::string p)
{

	struct vectorComparator
	{
		bool operator()(sf::Color lhs, sf::Color rhs) const
		{
			return lhs.r < rhs.r;
		}
	};

	std::map<int, terrainType, VectorComparator> terrainMap;

	//pixelMap[sf::Color(1,1,1)] = 1;
	pixelMap.insert(std::pair<sf::Color, int>(sf::Color(1,1,1), 1));

	//pixelMap[2] = 1;
	//pixelMap[3] = 2;

	terrainMap[1] = grass;
	terrainMap[2] = ice;

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
			for(unsigned int k = 0; k < pixelMap.size(); k++)
			{
				m_map.push_back(pixelMap.at(m_image.getPixel(j, i)));
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
			std::cout << "hello";
			Grass* g = new Grass("res/grass.png", w , sf::Vector2f(70, 70), sf::Vector2f(x*70, y*70), true);
			t.push_back(g);
		}
	}
}

Map::~Map(){}
