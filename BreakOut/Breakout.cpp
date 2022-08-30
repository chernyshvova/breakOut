#include "stdafx.h"
#include "MenuScene.h"

int main()
{
    //Start first scene
    game::MenuScene scene;
    try
    {
        scene.run();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }

}

