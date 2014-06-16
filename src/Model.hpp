/*
 * Model.hpp
 *
 *  Created on: Jun 16, 2014
 *      Author: Charles Miller
 */

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <SFML/Graphics.hpp>

//TODO: I should inherent from the drawable class?
class Model
{
public:

	//	Sprite, Texture incrimentation
	Model(sf::RectangleShape& s, sf::Vector2u i = sf::Vector2u(70, 0));

private:

	std::vector<sf::Texture> t;
};



#endif /* MODEL_HPP_ */
