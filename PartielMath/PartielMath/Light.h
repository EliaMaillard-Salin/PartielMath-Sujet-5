#pragma once
#include "Mesh.h"

class Settings;

class Light
{
public:
    Light(Settings const& settings);
    Vertex const& GetNormalizedLight() const { return m_lightVertex; }
    void Debug() const { m_lightVertex.Debug(); }

private:
    Vertex m_lightVertex;
};

