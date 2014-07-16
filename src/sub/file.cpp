//file.cpp

#include "file.h"
#include <fstream>

File::File()
{
	found = 0;
}

File::File(const File& copy)
{
	m_fileName = copy.m_fileName;
	m_fileVector = copy.m_fileVector;
	
	found = 0;
}

File::File(std::string fileName, bool readOnOpen)
{
	m_fileName = fileName;
	if(readOnOpen)
		read();
	
}

File::~File()
{
	m_fileVector.clear();

}

void File::read()
{
	m_fileVector.clear();

	std::fstream f((m_fileName).c_str());
	std::string line;

	while(!f.eof())
	{
		std::getline(f, line);
		m_fileVector.push_back(new std::string(line));

	}

}

void File::write()
{
	std::ofstream f((m_fileName).c_str());
	for(int i = 0; i < m_fileVector.size(); i++)
	{
		if(i != 0)
			f << "\n" << *m_fileVector[i];
		else
			f << *m_fileVector[i];

	}

}

std::vector<std::string*>& File::getFile()
{
	return m_fileVector;

}

void File::setFile(std::vector<std::string*> fileVector)
{
	m_fileVector = fileVector;

}

std::string File::getLine(unsigned int lineNum)
{
	if(lineNum <= m_fileVector.size())
		return *m_fileVector[lineNum];

	return "";
	
}

void File::setLine(std::string line, unsigned int lineNum)
{
	if(lineNum <= m_fileVector.size())
		m_fileVector[lineNum] = new std::string(line);
	
}

//adds line to the end of the file
void File::append(std::string line)
{
	m_fileVector.push_back(new std::string(line));

}

void File::deleteLine(unsigned int lineNum)
{
	if(lineNum <= m_fileVector.size())
	{
		std::vector<std::string*>::iterator it = m_fileVector.begin();
		for(int i = 0; i < lineNum; i++, it++);
		m_fileVector.erase(it);

	}

	
}

void File::setFileName(std::string fileName)
{
	m_fileName = fileName;
}

void File::deleteFirstLine()
{
	m_fileVector.erase(m_fileVector.begin());

}

void File::deleteLastLine()
{
	m_fileVector.erase(m_fileVector.end());
	
}

unsigned int File::getLength()
{
	return m_fileVector.size();

}

size_t File::getItem(unsigned int line, std::string key)
{
	if(lineContains(line, key))
	{
		return found;
	}

	return 0;
}

size_t File::getItem(std::string line, std::string key)
{
	if(lineContains(line, key))
	{
		return true;
	}

	return false;
}

bool File::lineContains(unsigned int line, std::string s)
{

	found = m_fileVector[line]->find(s);

	if(found != std::string::npos)
	{
		return true;
	}

	return false;
}

bool File::lineContains(std::string line, std::string s)
{
	found = line.find(s);

	if(found != std::string::npos)
	{
		return true;
	}

	return false;
}

std::string File::removeSpaces(std::string s)
{
	while(lineContains(s, " "))
	{
		s.erase(getItem(s, " "));
	}

	return s;
}
