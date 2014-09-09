/*
 * Map.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: Charles Miller
 */

#include "Map.hpp"

Map::Map(std::string p)
{
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

	curType = 1;

}

void Map::load()
{
	sf::Image m_image;

	m_image.loadFromFile(m_p);

	mapSize = m_image.getSize();

	//Parsing from top down
	for(unsigned int i = mapSize.y; i > 0; i--)
	{
		//Parsing from right to left
		for(unsigned int j = mapSize.x; j > 0; j--)
		{
			sf::Color pixel = m_image.getPixel(j, i);

			for(unsigned int l = 0; l < mapVals.size(); l++)
			{
				if(pixel == mapVals.at(l))
				{
					m_map.push_back(l);
				}

			}
		}
	}
}

void Map::populate(b2World& w, std::vector<Terrain*>& t, std::vector<Object*>& ot)
{

	unsigned int x, y, z = 0;
	unsigned int tempY = 0;

	std::cout << "size" << m_map.size() << "\n";

	for(unsigned int j = m_map.size()- 1; j > 0; j--)
	{
		x++;

		if(x == mapSize.x)
		{
			y++;
			x = 0;
		}

		if(consecutiveTiles.size() > 0)
		{
			curType = m_map.at(j);

			if(curType == m_map.at(j+1) && tempY == y)
			{
				std::pair<sf::Vector2u, sf::Vector2f> part;
				part.first = sf::Vector2u(j, m_map.at(j));
				part.second = sf::Vector2f(x, y);

				consecutiveTiles.at(consecutiveTiles.size()-1).push_back(part);
			}
			else
			{
				std::pair<sf::Vector2u, sf::Vector2f> part;
				part.first = sf::Vector2u(j, m_map.at(j));
				part.second = sf::Vector2f(x, y);

				std::vector< std::pair <sf::Vector2u, sf::Vector2f> > temp;
				temp.push_back(part);

				consecutiveTiles.push_back(temp);
			}

		}
		else
		{
			std::pair<sf::Vector2u, sf::Vector2f> part;
			part.first = sf::Vector2u(j, m_map.at(j));
			part.second = sf::Vector2f(x, y);

			std::vector< std::pair <sf::Vector2u, sf::Vector2f> > temp;
			temp.push_back(part);

			consecutiveTiles.push_back(temp);
		}

		//std::cout << consecutiveTiles.size() << "\n";
		tempY = y;
	}



	for(unsigned int k = 0; k < consecutiveTiles.size()-1; k++)
	{
		std::vector<std::pair<sf::Vector2u, sf::Vector2f> > currentTiles;
		currentTiles = consecutiveTiles.at(k);
		std::cout << "Size of tileset " << currentTiles.size() << "\n";

		int currentTileType = currentTiles.at(0).first.y;

		if(currentTileType == 1)
		{
			std::cout << "Size test " << 70*currentTiles.size();
			Grass* g = new Grass("res/grass.png", w , sf::Vector2f(70*currentTiles.size(), 70), sf::Vector2f(currentTiles.at(0).second.x*70, currentTiles.at(0).second.y*70), true);
			t.push_back(g);

		}

		else if(currentTileType == 2)
		{
			Ice* i = new Ice("res/ice.png", w , sf::Vector2f(70*currentTiles.size(), 70), sf::Vector2f(currentTiles.at(0).second.x*70, currentTiles.at(0).second.y*70), true);
			t.push_back(i);

		}

		else if(currentTileType == 3)
		{
			Object* o = new Object("res/box.png", w, b2Shape::e_polygon, sf::Vector2f(x*70, y*70));
			ot.push_back(o);
		}
		else if(currentTileType == 0)
		{
			std::cout << "Air";
		}

		std::cout << "\n";

	}

}

Map::~Map(){}
