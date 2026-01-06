#include <iostream>
#include <signal.h>
#include <windows.h> // For console settings

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "Light.h"
#include "File.h"

void SetCursorVisible(bool visible)
{
    if (visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

void OnKill(int _signum)
{
    std::cout << "Liam ce gros bg :)\n";

    SetCursorVisible(true);
    exit(_signum);
}


int main(int argc, char** argv)
{
    signal(SIGINT, OnKill);

    Settings settings(argc, argv);
    Screen screen(settings);
    Light light(settings);
    File file("miaou.txt");
    
    screen.Clear();
    screen.SetCursorVisible(false);
    screen.Display();

    Mesh mesh(file.LoadFileImage(), settings);
    mesh.Move(-50, -14, 0);
    
    // TORE
    /*mesh.GenerateTorus(4.0f, 0.9);
    std::cout << "Torus Major 4, minor 0.9:" << std::endl;*/
    
    // CARRE
    //mesh.GenerateSquare(4.0f);
    screen.Display(mesh, light);

    while (true)
    {
        mesh.Rotate(Axis::Y, 0.08f);
        //mesh.Rotate(Axis::X, settings.GetMeshRotationXPerAngle());
        //mesh.Rotate(Axis::Z, settings.GetMeshRotationZPerAngle());

        screen.Display(mesh, light);
            Sleep(settings.GetFrameDuration() / 1000);
        screen.Clear();
    }

    return 0;
}

// 2.5 : 
// La projection obtenue est etiree verticalement car un charactere est plus grand que large