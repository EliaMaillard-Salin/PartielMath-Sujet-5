#ifndef LIGHT_H
#define LIGHT_H

#include "Mesh.h"
#include <cmath>
#include <iostream>

class Settings;

class Light
{
public:
    Light(Settings const& settings);
    Vertex const& GetNormalizedLight() const { return m_lightVertex; }
    void Debug() const
    {
        std::cout << "LightVertex : { X: " << std::round(m_lightVertex.x) << ";Y: " << std::round(m_lightVertex.y) << ";Z: " << std::round(m_lightVertex.z) << " }";
    }

private:
    Vertex m_lightVertex;
};

#endif // LIGHT_H