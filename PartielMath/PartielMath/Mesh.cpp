#include "Mesh.h"

#include <iostream>
#include <cmath>

Mesh::Mesh(std::vector<Vertex> vertices) : m_vertices(vertices)
{}

void Mesh::Debug()
{
    std::cout << "Vertices : \n";

    for (int i = 0; i < m_vertices.size(); i++)
    {
        std::cout << "Coords : { X: " << std::round(m_vertices[i].x) << ";Y: " << std::round(m_vertices[i].y) << ";Z: " << std::round(m_vertices[i].z) << " }";
        std::cout << "\t Normals : { NX : " << m_vertices[i].n.x << "; NY : " << m_vertices[i].n.y << "; NZ : " << m_vertices[i].n.z << " }" << std::endl;
        std::cout << "\t Value : " << m_vertices[i].value << std::endl;
    }
}

void Mesh::Rotate(float angle, Axis axis)
{
    for (int i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].Rotate(angle, axis);
    }
}

void Mesh::Move(float x, float y, float z)
{
    for (int i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].x += x;
        m_vertices[i].y += y;
        m_vertices[i].z += z;
    }
}

void Mesh::GenerateLogo()
{
    
}
