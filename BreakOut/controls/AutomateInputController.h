#pragma once
#include "IInputController.h"
#include "DisplayMap.h"

namespace game
{
	class AutomateInputController : public IInputController
	{
	public:
		AutomateInputController(DisplayMap& map);
		virtual int inputKey() override;
	private:
		int m_inputSleepTimer;
		DisplayMap& m_map;
	};
}


