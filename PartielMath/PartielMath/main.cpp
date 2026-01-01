#include <iostream>
#include <windows.h>
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "File.h"


int main(int argc, char** argv)
{
    File file("Miaou.txt");
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(file.LoadFileImage());
    //mesh.Debug();
    mesh.Move(-30, -10, 0);
    screen.Display(mesh);
    while (true)
    {
        screen.Display(mesh);
        mesh.Rotate(0.08f, Axis::Y);
    }  

    return 0;
}