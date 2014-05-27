/*
 * file.cpp
 *
 *  Created on: May 23, 2014
 *      Author: Charles Miller
 */

#include "file.h"

File::File(std::string p, bool createIfNotFound)
{
	m_filename = p;

	std::fstream f(m_filename.c_str());

	if(!f && createIfNotFound)
	{
		std::ofstream o(p.c_str());
		o << "";

		std::cout << "File Not Found. File Has been generated";
		return;
	}

	else
	{
		while(!f.eof())
		{
			std::getline(std::cin, m_line);
			m_file.push_back(m_line);
		}
	}
}

std::string File::getLine(unsigned int l)
{
	return m_file[l];
}

void File::write()
{
	m_file.clear();

	//std::ofstream f(m_filename.c_str());
	//f << m_file;
}


void File::write(std::vector<std::string> w)
{
	m_file.clear();

	std::ofstream f(m_filename.c_str());
	//f << w;
}

void File::append(std::string w)
{
	m_file.push_back(w);
}

void File::replaceLine(std::string r, unsigned int l)
{
	m_file[l] = r;
}

unsigned int File::getNumberOfLines()
{
	return m_file.size() - 1;
}
