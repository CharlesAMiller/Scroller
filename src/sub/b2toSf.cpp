/*
 * b2toSf.cpp
 *
 *  Created on: Apr 20, 2014
 *      Author: Charles Miller
 */

#include "b2toSf.hpp"

float getAngleRadians(float degrees)
{
	return (degrees/180)*PI;
}

float getAngleDegrees(float radians)
{
	return (radians*180)/PI;
}

float toB2(float x){ return x/pixelsPerMeter; }

float toSf(float x){ return x*pixelsPerMeter; }

b2Vec2 getB2Coords(sf::Vector2f position)
{
	b2Vec2 toReturn;
	toReturn.x = position.x/pixelsPerMeter;
	toReturn.y = position.y/pixelsPerMeter;

	return toReturn;
}

sf::Vector2f getSfCoords(b2Vec2 position)
{
	sf::Vector2f toReturn;
	toReturn.x = position.x*pixelsPerMeter;
	toReturn.y = position.y*pixelsPerMeter;

	return toReturn;
}



