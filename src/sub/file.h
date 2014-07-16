#ifndef FILE_H_
#define FILE_H_

#include <vector>
#include <string>

class File
{
public:
	File();
	File(const File& copy);
	//if readOnOpen is true the file will read when you declare it
	File(std::string fileName, bool readOnOpen = false);

	~File();

	void read();
	void write();

	std::string getFileName();
	void setFileName(std::string fileName);

	std::vector<std::string*>& getFile();
	void setFile(std::vector<std::string*> fileVector);

	bool lineContains(unsigned int line, std::string s);
	bool lineContains(std::string line, std::string s);

	size_t getItem(unsigned int line, std::string key);
	size_t getItem(std::string line, std::string key);

	//starts at 0
	std::string getLine(unsigned int lineNum);
	void setLine(std::string line, unsigned int lineNum);

	//adds line to the end of the file
	void append(std::string line);

	std::string removeSpaces(std::string s);

	void deleteLine(unsigned int lineNum);
	void deleteFirstLine();
	void deleteLastLine();

	unsigned int getLength();

private:
	std::vector<std::string*> m_fileVector;
	std::string m_fileName;

	size_t found;

};

#endif /* FILE_H_ */
