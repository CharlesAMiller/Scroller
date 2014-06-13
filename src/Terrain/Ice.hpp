/*
 * Ice.hpp
 *
 *  Created on: Jun 3, 2014
 *      Author: Charles Miller
 */

#ifndef ICE_HPP_
#define ICE_HPP_

#include "../Terrain.hpp"

class Ice : public Terrain
{
public:

	Ice(std::string pa, b2World& w, sf::Vector2f s, sf::Vector2f p, bool repeatTexture = true);

	~Ice();

	terrainType getType();

	void update();

	void draw(sf::RenderWindow& app);

	static sf::Texture iceTexture;
};


#endif /* ICE_HPP_ */
