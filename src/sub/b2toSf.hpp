/*
 * b2toSf.hpp
 *
 *  Created on: Apr 20, 2014
 *      Author: Charles Miller
 */

#ifndef B2TOSF_HPP_
#define B2TOSF_HPP_

#include <cmath>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>


const unsigned int pixelsPerMeter = 30;

const double PI = 3.1415926;

float getAngleRadians(float degrees);

float getAngleDegrees(float radians);

b2Vec2 getB2Coords(sf::Vector2f position);

sf::Vector2f getSfCoords(b2Vec2 position);

float toSf(float x);

float toB2(float x);


#endif /* B2TOSF_HPP_ */
