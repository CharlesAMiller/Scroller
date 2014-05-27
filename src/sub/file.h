/*
 * file.h
 *
 *  Created on: May 23, 2014
 *      Author: Charles Miller
 */

#ifndef FILE_H_
#define FILE_H_

#include <fstream>
#include <iostream>
#include <vector>

class File
{

public:

	File(std::string p, bool createIfNotFound = true);

	std::string getLine(unsigned int l);

	unsigned int getNumberOfLines();

	void write();

	void write(std::vector<std::string> w);

	void append(std::string w);

	void replaceLine(std::string r, unsigned int l);

private:

	std::vector<std::string> m_file;

	std::string m_line;

	std::string m_filename;
};




#endif /* FILE_H_ */
