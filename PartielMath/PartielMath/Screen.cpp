#include <iostream>
#include <cmath>
#include "Screen.h"
#include "Settings.h"
#include "Mesh.h"
#include "Light.h"

Screen::Screen(Settings const& settings)
    : m_width(settings.GetScreenWidth())
    , m_height(settings.GetScreenHeight())
    , m_zPosition(settings.GetScreenPosition())
    , m_background(settings.GetScreenBackground())
    , m_meshProjection(settings.GetScreenMeshProjection())
    , m_meshZPosition(settings.GetMeshPosition())
    , m_pixels(m_width* m_height, '.')
{
    std::cout << "\x1b[?25l";
    std::cout << "\x1b[2J";
}

void Screen::Display() const
{
    std::cout << "\33[?25l";
    std::cout << "\33[H";
    //system("cls");

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            std::cout << m_pixels[m_width * i + j];
        }
        std::cout << std::endl;
    }
}

void Screen::Display(Mesh const& mesh, Light const& _light)
{
    std::fill(m_pixels.begin(), m_pixels.end(), m_background);
    _ProjectMesh(mesh,_light);
    Display();
}

void Screen::_ProjectMesh(Mesh const& mesh, Light const& _light)
{
    for (Vertex vertex : mesh.GetVertices())
    {
        _ProjectInTopLeftScreenSpace(vertex);
        int u = std::round(vertex.x);
        int v = std::round(vertex.y);
        float ooz = 1.f / vertex.z;

        if (_IsVertexInScreen(u, v))
        {
            float L = vertex.ComputeIllumination(_light);
            
            if (L > 0.0f)
            {
                m_pixels[v * m_width + u] = 'G';
            }
            else
            {
                m_pixels[v * m_width + u] = 'C';
            }
            //m_pixels[v * m_width + u] = m_meshProjection;
        }
    }
}

void Screen::_ProjectInCenterScreenSpace(Vertex& vertex)
{
    vertex.z += m_meshZPosition;
    vertex.x = m_zPosition * vertex.x / vertex.z;
    vertex.y = m_zPosition * vertex.y / vertex.z;
}

void Screen::_ProjectInTopLeftScreenSpace(Vertex& vertex)
{
    vertex.z += m_meshZPosition;
    vertex.x += m_width / 2;
    vertex.y += m_height / 2;
}

bool Screen::_IsVertexInScreen(int u, int v)
{
    return u >= 0 && u < m_width && v >= 0 && v < m_height;
}