#pragma once
#include <cstdio>
#include <vector>

class Settings;
class Light;

enum class Axis
{
    X,
    Y,
    Z
};

struct Vertex
{
    void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\n", x, y, z); }
    float ComputeIllumination(const Light& _light) const;
    void Rotate(Axis _axis, float _angle);

    float x;
    float y;
    float z;

    struct // normal
    {
        float x;
        float y;
        float z;
    } n; 

    char lightning;
};

class Mesh
{
public:
    Mesh(Settings const& settings);
    Mesh(std::vector<Vertex> const& vertices, Settings const& settings);
    std::vector<Vertex> const& GetVertices() const { return m_vertices; }
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float side);
    void GenerateTorus(float _majorRadius, float _minorRadius);
    void GenerateGCLogo(float size);
    void Debug() const;

    void Move(float x, float y, float z);

    void Rotate(Axis _axis, float _angle);
    //void ComputeIllumination(const Light& _light);

private:
    void _GenerateSector(float radius, float angle);

private:
    std::vector<Vertex> m_vertices;
    int m_resolution;
};