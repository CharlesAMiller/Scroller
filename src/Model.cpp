/*
 * Model.cpp
 *
 *  Created on: Jun 17, 2014
 *      Author: Charles Miller
 */

#include "Model.hpp"

Model::Model(sf::RectangleShape& s, sf::Vector2u i)
{
}

Model::Model(std::vector<std::string> p)
{
	for(unsigned int i = 0; i < p.size(); i++)
	{
		sf::Texture tx; tx.loadFromFile(p[i]);
		t.push_back(tx);
	}
}

Model::~Model(){};
