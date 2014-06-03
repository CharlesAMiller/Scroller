/*
 * Grass.hpp
 *
 *  Created on: Jun 2, 2014
 *      Author: Charles Miller
 */

#ifndef GRASS_HPP_
#define GRASS_HPP_

#include "../Terrain.hpp"

class Grass : public Terrain
{
public:

	Grass(std::string pa, b2World& w, sf::Vector2f s, sf::Vector2f p, bool repeatTexture = true);

	~Grass();

	terrainType getType();

	void update();

	void draw(sf::RenderWindow& app);

	static sf::Texture grassTexture;
};



#endif /* GRASS_HPP_ */
