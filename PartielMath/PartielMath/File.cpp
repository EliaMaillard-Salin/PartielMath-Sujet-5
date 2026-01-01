#include "File.h"
#include <fstream>
#include <sstream>
#include <iostream>

File::File(std::string _path) :
	m_pFile(new std::fstream()),
	m_path(_path),
	m_cursor(0),
	m_isOpen(false)
{
	Open();
}

//std::vector<std::vector<char>> File::GenerateArray(std::string input, unsigned int rowLength, unsigned int colLength)
//{
//	std::vector<std::vector<char>> toReturn = std::vector<std::vector<char>>();
//	int size = input.size();
//
//	if (size < (rowLength * colLength))
//	{
//		std::cout << "Failed to generate array : input is too short !\n";
//		return std::vector<std::vector<char>>();
//	}
//
//	for (int i = 0; i < rowLength; i++)
//	{
//		std::vector<char> currentRow = std::vector<char>();
//		for (int j = 0; j < colLength; j++)
//		{
//			currentRow.push_back(input[i * rowLength + j]);
//		}
//		toReturn.push_back(currentRow);
//	}
//
//	return toReturn;
//}

std::vector<Vertex> File::LoadFileImage()
{
	std::vector<Vertex> result;

	int x = 0;
	int y = 0;
	int z = 0;
	std::string line;

	// # = commentary
	// l = newLayer
	while (std::getline(*m_pFile, line))  
	{
		if (line.empty() || line[0] == '#')
		{
			continue;
		}
		if (line[0] == 'l')
		{ 
			z++;
			y = 0;
			continue;
		}

		x = 0;
		for (int i = 0; i < line.size(); ++i)
		{
			Vertex v;
			v.x = x;
			v.y = y;
			v.z = z;
			v.value = line[i];
			if (line[i] != ' ') result.push_back(v);
			x++;
		}
		y++;
	}

	return result;
}

//std::vector<std::vector<char>> File::GenerateArray(File* pFile, std::string path)
//{
//	if (pFile->IsOpen() == false and pFile->Open(path) == false)
//	{
//		std::cout << "Failed to generate array : file failed its opening !\n";
//		return std::vector<std::vector<char>>();
//	}
//
//	std::vector<std::vector<char>> toReturn = GenerateArray(pFile->Read());
//
//	if (toReturn == std::vector<std::vector<char>>())
//	{
//		std::cout << "Failed to generate array for file " << pFile->m_path << " | file is too short !\n";
//	}
//
//	return toReturn;
//}

bool File::Open()
{
	if (m_path == "")
		return false;
	m_pFile->open(m_path, std::fstream::in);

	if (m_pFile->is_open() == false)
	{
		std::cout << "Failed to open following file : " << m_path << "\n";

		return false;
	}

	// std::cout << "File " << fileName << " succesfully opened !" << std::endl;

	return true;
}

void File::Close()
{
	m_pFile->close();
}

std::string File::Read()
{
	std::string toReturn;

	(*m_pFile) >> toReturn;

	return toReturn;
}

/// <summary>
/// Saves the current file's content into a destination file, which represents the save
/// </summary>
/// <param name="path">the path to the save</param>
/// <param name="dst">[out] A handle to the save</param>
/// <returns>Returns true if the save was a success</returns>
//bool File::Save(std::string path, File** dst)
//{
//	std::cout << "Saving file...\n";
//
//	if (Open(path) == false and m_isOpen == false)
//	{
//		std::cout << "Failed to save following file : " << m_path << " | File was not open\n";
//		return false;
//	}
//
//	std::fstream save(path, std::ios::out);
//
//	save << Read();
//
//	File* out = new File(path);
//	out->m_pFile = &save;
//
//	dst = &out;
//
//	std::cout << "Succesfully saved file " << m_path << "\n";
//
//	return true;
//}

int File::Size()
{
	if (!m_isOpen)
		return 0;

	m_pFile->seekg(std::ios::end);

	return (int)m_pFile->tellg();
}

bool File::IsOpen()
{
	return m_isOpen;
}
