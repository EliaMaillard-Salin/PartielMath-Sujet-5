#include "Structs.h"
#include <iostream>
#include <cmath>

constexpr float PI = 3.141592654f;


void Vertex::Rotate(float angle, Axis axis)
{
    Vertex previous = *this;
    switch (axis)
    {
    case Axis::X:
    {
        y = previous.y * std::cos(angle) - previous.z * std::sin(angle);
        z = previous.y * std::sin(angle) + previous.z * std::cos(angle);
    }
    break;
    case Axis::Y:
    {
        x = previous.x * std::cos(angle) + previous.z * std::sin(angle);
        z = -previous.x * std::sin(angle) + previous.z * std::cos(angle);
    }
    break;
    case Axis::Z:
    {
        x = previous.x * std::cos(angle) - previous.y * std::sin(angle);
        y = previous.x * std::sin(angle) + previous.y * std::cos(angle);
    }
    break;
    default:
        break;
    }
}