#include "stdafx.h"
#include "AutomateInputController.h"
#include "GameConfig.h"

game::AutomateInputController::AutomateInputController(DisplayMap& map)
    : m_inputSleepTimer(0)
    , m_map(map)
{
}

//Emit player input
int game::AutomateInputController::inputKey()
{
    //TODO

    return 0;
}
