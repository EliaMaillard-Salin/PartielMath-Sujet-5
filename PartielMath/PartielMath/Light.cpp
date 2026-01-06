#include <cmath>

#include "Light.h"
#include "Settings.h"

Light::Light(Settings const& _settings)
{
    // No need to position light because we only need light direction
    m_lightVertex.x = 0.f;
    m_lightVertex.y = 0.f;
    m_lightVertex.z = 0.f;

    float nx = _settings.GetLightXDir();
    float ny = _settings.GetLightYDir();
    float nz = _settings.GetLightZDir();
    float directionNorm = std::sqrt(nx * nx + ny * ny + nz * nz);

    if (directionNorm != 0.f)
    {
        m_lightVertex.n.x = nx / directionNorm;
        m_lightVertex.n.y = ny / directionNorm;
        m_lightVertex.n.z = nz / directionNorm;
    }
}