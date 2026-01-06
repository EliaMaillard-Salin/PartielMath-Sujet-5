#include "Settings.h"
#include <string>

Settings::Settings(int argc, char** argv)
    : m_screenWidth(100)
    , m_screenHeight(50)
    , m_screenBackground(' ')
    , m_screenMeshProjection('X')
    , m_screenPosition(3.33f)
    , m_meshResolution(32)
    , m_meshPosition(5.f)
    , m_meshRotationXPerFrame(0.02f)
    , m_meshRotationYPerFrame(0.04f)
    , m_meshRotationZPerFrame(0.0f)
    , m_frameDuration(100000)
    , m_light({ 5.0f,-5.0f,2.0f })
    , m_path("test.txt")
{
    _ParseArguments(argc, argv);
}

void Settings::_ParseArguments(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "-w" && i + 1 < argc)
        {
            m_screenWidth = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            m_screenHeight = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-b" && i + 1 < argc)
        {
            m_screenBackground = argv[i + 1][0];
            i++;
        }
        else if (arg == "-p" && i + 1 < argc)
        {
            m_screenMeshProjection = argv[i + 1][0];
            i++;
        }
        else if (arg == "-s" && i + 1 < argc)
        {
            m_screenPosition = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-r" && i + 1 < argc)
        {
            m_meshResolution = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-m" && i + 1 < argc)
        {
            m_meshPosition = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-x" && i + 1 < argc)
        {
            m_meshRotationXPerFrame = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-y" && i + 1 < argc)
        {
            m_meshRotationYPerFrame = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-z" && i + 1 < argc)
        {
            m_meshRotationZPerFrame = std::atof(argv[i + 1]);
            i++;
        }
        else if (arg == "-f" && i + 1 < argc)
        {
            m_frameDuration = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-lx" && i + 1 < argc)
        {
            m_light.lx = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-ly" && i + 1 < argc)
        {
            m_light.ly = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-lz" && i + 1 < argc)
        {
            m_light.lz = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-fp" && i + 1 < argc)
        {
            m_path = argv[i + 1];
            i++;
        }
    }
}