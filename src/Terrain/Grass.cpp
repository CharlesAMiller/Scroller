/*
 * Grass.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: Charles Miller
 */

#include "Grass.hpp"

sf::Texture Grass::grassTexture;

Grass::Grass(std::string pa, b2World& w, sf::Vector2f s, sf::Vector2f p, bool repeatTexture):
	Terrain(w, s, p)
{
	static bool isLoaded = false;

	if(!isLoaded)
	{
		isLoaded = true;
		grassTexture.loadFromFile(pa);
	}

	grassTexture.setRepeated(repeatTexture);
	//This part is important visually.
	grassTexture.setSmooth(true);

	m_body.shape.setTexture(&grassTexture);
	m_body.shape.setSize(s);
	m_body.shape.setPosition(p);
	m_body.shape.setOrigin(m_body.shape.getSize().x/2, m_body.shape.getSize().y/2);

}

terrainType Grass::getType()
{
	return grass;
}

void Grass::update()
{

}
void Grass::draw(sf::RenderWindow& app)
{
	app.draw(m_body.shape);
}

Grass::~Grass(){}


