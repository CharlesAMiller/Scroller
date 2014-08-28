/*
 * Ice.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: Charles Miller
 */

#include "Ice.hpp"

sf::Texture Ice::iceTexture;

Ice::Ice(std::string pa, b2World& w, sf::Vector2f s, sf::Vector2f p, bool repeatTexture):
	Terrain(w, s, p, 0.01)
{
	static bool isLoaded = false;

	if(!isLoaded)
	{
		isLoaded = true;
		iceTexture.loadFromFile(pa);
	}

	iceTexture.setRepeated(repeatTexture);
	//This part is important visually.
	iceTexture.setSmooth(true);

	m_body.shape.setTexture(&iceTexture);
	m_body.shape.setSize(s);
	m_body.shape.setPosition(p);
	m_body.shape.setOrigin(m_body.shape.getSize().x/2, m_body.shape.getSize().y/2);

}

terrainType Ice::getType()
{
	return ice;
}

void Ice::update()
{

}
void Ice::draw(sf::RenderWindow& app)
{
	app.draw(m_body.shape);
}

Ice::~Ice(){}




