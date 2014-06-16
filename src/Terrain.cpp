/*
 * Terrain.cpp
 *
 *  Created on: May 30, 2014
 *      Author: Charles Miller
 */

#include "Terrain.hpp"


Terrain::Terrain(b2World& w, sf::Vector2f s, sf::Vector2f p)
{
	m_body.bodyDef.position = getB2Coords(p);

	m_body.body = w.CreateBody(&m_body.bodyDef);

	m_body.dynamicBody.SetAsBox(toB2(s.x/2), toB2(s.y/2));

	m_body.body->CreateFixture(&m_body.dynamicBody, 0.0f);
}

Terrain::Terrain(b2World& w, sf::Vector2f s, sf::Vector2f p, float32 f)
{
	m_body.bodyDef.position = getB2Coords(p);

	m_body.body = w.CreateBody(&m_body.bodyDef);

	m_body.dynamicBody.SetAsBox(toB2(s.x/2), toB2(s.y/2));

	m_body.fixtureDef.friction = f;

	m_body.body->CreateFixture(&m_body.dynamicBody, 0.0f);
}

Terrain::~Terrain(){}

terrainType Terrain::getType()
{
	return m_type;
}

void Terrain::update(){}

void Terrain::draw(sf::RenderWindow& app)
{
	app.draw(m_body.shape);
}

