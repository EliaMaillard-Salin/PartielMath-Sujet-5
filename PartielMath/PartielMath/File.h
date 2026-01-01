#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include "Structs.h"


class File
{
	std::string m_path;

	std::fstream* m_pFile;
	unsigned int m_cursor;
	bool m_isOpen;

	bool Open();
	void Close();

public:
	// Static method to return a 50x50 array with characters to print
	//static std::vector<std::vector<char>> GenerateArray(File* pFile, std::string path);
	//static std::vector<std::vector<char>> GenerateArray(std::string input, unsigned int rowLength = 50, unsigned int colLength = 50);

	std::vector<Vertex> LoadFileImage();

	//File(std::string path = "");
	File(std::string path);

	std::string Read();


  	//bool Save(std::string path, File** dst); // c'est quoi l'utilite de save dans le contexte du projet ?
	//void SetPath(std::string path) { m_path = path; }; // t'es rebou mon reuf 

	int Size();
	bool IsOpen();
};

#endif // FILE_H