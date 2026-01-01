#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Structs.h"
#include "File.h"

class Mesh
{
	float posX = 0;
	float posY = 0;
	float posZ = 0;

public:
	std::vector<Vertex> m_vertices;

	Mesh(std::vector<Vertex> vertices);

	std::vector<Vertex> const& GetVertices() const { return m_vertices; }
	void Rotate(float angle, Axis axis);
	void Move(float x, float y, float z);
	void SetPosition(float x, float y, float z) { posX = x; posY = y; posZ = z; }
	void GenerateLogo();

	float GetPosX() { return posX; }
	float GetPosY() { return posY; }
	float GetPosZ() { return posZ; }

	void Debug();
};

#endif // MESH_H