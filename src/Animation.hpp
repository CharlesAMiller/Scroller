/*
 * Animation.hpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Charles Miller
 */

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <SFML/Graphics.hpp>

class Animation
{

public:

	Animation();

	Animation(std::vector<sf::Texture> frames);

	Animation(std::vector<std::string> path);

private:

	std::vector<sf::Texture> animation;

	unsigned int curFrame;

};



#endif /* ANIMATION_HPP_ */
