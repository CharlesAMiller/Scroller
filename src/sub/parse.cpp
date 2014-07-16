/*
 * parse.cpp
 *
 *  Created on: May 24, 2014
 *      Author: Charles Miller
 */

#include "parse.hpp"

std::map<std::string, value> parse(File& f)
{
	std::map<std::string, value> toReturn;

	for(unsigned int i = 0; i < f.getLength(); i++)
	{
		if(f.lineContains(i, "="))
		{

		}
	}

	return toReturn;
}

std::pair<std::string, std::string> splitLine(std::string line, size_t split)
{
	std::pair<std::string, std::string> toReturn;

	return toReturn;
}

