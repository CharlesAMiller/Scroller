/*
 * Terrain.hpp
 *
 *  Created on: May 27, 2014
 *      Author: Charles Miller
 */

#ifndef TERRAIN_HPP_
#define TERRAIN_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>


enum terrainType
{
	grass,
	ice,
	lava
};

class Terrain
{
public:

	Terrain();

	terrainType getType();

	virtual ~Terrain();

};



#endif /* TERRAIN_HPP_ */
