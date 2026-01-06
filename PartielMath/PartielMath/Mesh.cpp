#include <cmath>
#include "Mesh.h"
#include "Settings.h"
#include "Light.h"

constexpr float PI = 3.14159265f;

//float ScalarProduct(Vertex _first, Vertex _second)
//{
//    return (_first.x * _second.x +
//            _first.y * _second.y +
//            _first.z * _second.z);
//}



Mesh::Mesh(Settings const& settings)
    : m_resolution(settings.GetMeshResolution())
{
}

Mesh::Mesh(std::vector<Vertex> const& vertices, Settings const& settings) : 
    m_vertices(vertices), m_resolution(settings.GetMeshResolution())
{
}

void Vertex::Rotate(Axis _axis, float _angle)
{
    Vertex temp = *this;
    switch (_axis)
    {
    case(Axis::X):
        y = temp.y * cos(_angle) - temp.z * sin(_angle);
        z = temp.y * sin(_angle) + temp.z * cos(_angle);

        // normale
        n.y = temp.n.y * cos(_angle) - temp.n.z * sin(_angle);
        n.z = temp.n.y * sin(_angle) + temp.n.z * cos(_angle);
        break;
    case(Axis::Y):
        x = temp.x * cos(_angle) + temp.z * sin(_angle);
        z = (-temp.x * sin(_angle)) + temp.z * cos(_angle);

        // normale
        n.x = temp.n.x * cos(_angle) + temp.n.z * sin(_angle);
        n.z = (-temp.n.x * sin(_angle)) + temp.n.z * cos(_angle);
        break;
    case(Axis::Z):
        x = temp.x * cos(_angle) - temp.y * sin(_angle);
        y = temp.x * sin(_angle) + temp.y * cos(_angle);

        // normale
        n.x = temp.n.x * cos(_angle) - temp.n.y * sin(_angle);
        n.y = temp.n.x * sin(_angle) + temp.n.y * cos(_angle);
        break;
    }
}

float Vertex::ComputeIllumination(const Light& _light) const
{
    return (
            n.x * _light.GetNormalizedLight().n.x + 
            n.y * _light.GetNormalizedLight().n.y + 
            n.z * _light.GetNormalizedLight().n.z
        );
}

void Mesh::GenerateCircle(float radius)
{
    _GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    _GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            Vertex& current = m_vertices[m_resolution * i + j];

            current.x = (1.f * i / (m_resolution - 1) - 0.5f) * width;
            current.y = (1.f * j / (m_resolution - 1) - 0.5f) * height;
            current.z = 0.f;

            // normale
            current.n.x = 0.0f;
            current.n.y = 0.0f;
            current.n.z = -1.0f;
        }
    }
}
void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}

void Mesh::GenerateTorus(float _majorRadius, float _minorRadius) // Major = distance avec l'axe | minor = rayon du cercle
{
    m_vertices.resize(m_resolution * m_resolution);
    float angleZ = 0;
    float angleY = 0;
    for (int i = 0; i < m_resolution; i++)
    {
        angleY = (2 * PI * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            Vertex& current = m_vertices[m_resolution * i + j];

            angleZ = (2 * PI * j) / (m_resolution - 1);
            current.x = _majorRadius + _minorRadius * cos(angleZ);
            current.y = _minorRadius * sin(angleZ);

            // normale
            current.n.x = std::cos(angleZ);
            current.n.y = std::sin(angleZ);
            current.n.z = 0.0f;
            
            current.Rotate(Axis::Z, angleY);
        }
    }
}

void Mesh::GenerateGCLogo(float size)
{



}

void Mesh::Debug() const
{
    for (Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
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

void Mesh::_GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            Vertex& current = m_vertices[m_resolution * i + j];
            float theta = (angle * j) / (m_resolution - 1);

            current.x = r * std::cos(theta);
            current.y = r * std::sin(theta);
            current.z = 0.0f;

            // normale
            current.n.x = std::cos(theta);
            current.n.y = std::sin(theta);
            current.n.z = 0.0f;
        }
    }
}

void Mesh::Rotate(Axis _axis, float _angle)
{
    for (Vertex& i : m_vertices)
    {
        i.Rotate(_axis, _angle);
    }
}

//void Mesh::ComputeIllumination(const Light& _light)
//{
//    for (Vertex& i : m_vertices)
//    {
//        i.ComputeIllumination(_light);
//    }
//}