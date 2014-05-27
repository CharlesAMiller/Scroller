/*
 * parse.hpp
 *
 *  Created on: May 24, 2014
 *      Author: Charles Miller
 */

#ifndef PARSE_HPP_
#define PARSE_HPP_

#include <iostream>
#include <map>
#include "file.h"

union value
{
	int i;
	float f;
	//std::string s;
};

float asFloat(std::string key);

unsigned int asUint(std::string key);

std::string asString(std::string key);

std::map<std::string, value> parse(File& f);

#endif /* PARSE_HPP_ */
