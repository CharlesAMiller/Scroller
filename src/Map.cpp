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
	mapVals.push_back(sf::Color(255,255,255));
	//	Grass
	mapVals.push_back(sf::Color(34, 177, 76));
	// Ice
	mapVals.push_back(sf::Color(153, 217, 234));

	mapVals.push_back(sf::Color(185, 122, 87));

	/*	Players  */
	//mapVals.push_back(sf::Color(139, 207, 186));

	m_p = p;
}

void Map::load()
{
	sf::Image m_image;

	m_image.loadFromFile(m_p);

	mapSize = m_image.getSize();

	for(unsigned int i = mapSize.y; i > 0; i--)
	{
		for(unsigned int j = mapSize.x; j > 0; j--)
		{
			sf::Color pixel = m_image.getPixel(j, i);

			for(unsigned int l = 0; l < mapVals.size(); l++)
			{
				if(pixel == mapVals.at(l))
				{
					m_map.push_back(l);
				}

				//std::cout << "i " << i << "j " << j << "l " << l << "\n";
			}
		}
	}
}

void Map::populate(b2World& w, std::vector<Terrain*>& t, std::vector<Object*>& ot)
{

	unsigned int x, y, z = 0;

	std::cout << "size" << m_map.size() << "\n";

	for(unsigned int j = m_map.size()- 1; j > 0; j--)
	{
		x++;

		if(x == mapSize.x)
		{
			y++;
			x = 0;
		}

		std::vector<std::vector<unsigned int> > consecutiveTiles;

		int tempY = 0;

		if(j > 0)
		{

			//std::cout << "Val: " << j << "Last Val: " << m_map.at(j-1) << "\n";

			//Compare at the map value. DO NOT compare 'j' to anything. That's dumb.
			if(m_map.at(j) == m_map.at(j-1) && tempY == y)
			{
				std::cout << consecutiveTiles.size();
				//consecutiveTiles.at(consecutiveTiles.size()-1)->push_back()
			}
			else
			{
				std::vector<unsigned int> sub; sub.push_back(j);
				consecutiveTiles.push_back(sub);
			}
		}
		else
		{
			std::vector<unsigned int> sub; sub.push_back(j);
			consecutiveTiles.push_back(sub);
		}

		//std::cout << consecutiveTiles.size() << "\n";
		tempY = y;

		if(m_map[j] == 1)
		{
			Grass* g = new Grass("res/grass.png", w , sf::Vector2f(70, 70), sf::Vector2f(x*70, y*70), true);
			t.push_back(g);

			std::cout << "Grass\n";
		}

		else if(m_map[j] == 2)
		{
			Ice* i = new Ice("res/ice.png", w , sf::Vector2f(70, 70), sf::Vector2f(x*70, y*70), true);
			t.push_back(i);

			//std::cout << "Ice\n";
		}

		else if(m_map[j] == 3)
		{
			Object* o = new Object("res/box.png", w, b2Shape::e_polygon, sf::Vector2f(x*70, y*70));
			ot.push_back(o);
		}

	}

}

Map::~Map(){}
