#include <iostream>
#include <windows.h>
#include <signal.h>
#include <chrono>
#include <thread>
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "File.h"



//int main(int argc, char** argv)
//{
//    File file("Miaou.txt");
//    Settings settings(argc, argv);
//    Screen screen(settings);
//    Mesh mesh(file.LoadFileImage());
//    //mesh.Debug();
//    mesh.Move(-30, -10, 0);
//    screen.Display(mesh);
//    while (true)
//    {
//        screen.Display(mesh);
//        mesh.Rotate(0.08f, Axis::Y);
//    }  
//    //-r 128 -m 10 -s 30
//    return 0;
//}

int main(int argc, char** argv)
{
    File file("test.txt");
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(file.LoadFileImage());
    //mesh.Debug();
    mesh.Move(-30, -10, 0);
    screen.Display(mesh);
    while (true)
    {
        //mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::X);
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::Y);
        //mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::Z);

        screen.Display(mesh);

        std::this_thread::sleep_for(std::chrono::microseconds(settings.GetFrameDuration() / 5));
    }
    return 0;
}