#include "stdafx.h"
#include "GameScene.h"
#include "GameConfig.h"
#include "DrawController.h"
#include "AutomateInputController.h"

game::GameScene::GameScene()
	: m_displayMap()
{
	//init controllers
	m_inputController = std::make_shared<InputController>();
	m_drawController = std::make_shared<DrawController>(config::GAME_MAX_WIN_H, config::GAME_MAX_WIN_W);
}

//Run thread for graphic and input
void game::GameScene::run()
{
	m_threads.push_back(std::thread(&GameScene::startDisplay, this));
	m_threads.push_back(std::thread(&GameScene::startInputController, this));

	SceneBase::run();
}

void game::GameScene::drawScene()
{
	m_lockGuard.lock();
	m_drawController->draw(m_displayMap.build());
	m_lockGuard.unlock();
}

void game::GameScene::startDisplay()
{
	while (!m_isGameOver)
	{
		drawScene();
		if (m_displayMap.checkGameOver())
		{
			this->gameOver();
			return;
		}
		m_displayMap.checkBorderCollision();
		m_displayMap.checkPlatformCollision();
		m_displayMap.checkWallCollision();

		m_displayMap.update();
		update();
	}
}

//read keyboard key and lock resources for diplay data modify
void game::GameScene::startInputController()
{
	while (!m_isGameOver)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(config::DEFAULT_GAME_KEYBOARD_READ_SPEED));
		auto newDirection = parseInputKey(m_inputController->inputKey());
		if (newDirection != MoveDirection::None)
		{
			m_lockGuard.lock();
			m_displayMap.updateDirection(newDirection);
			m_lockGuard.unlock();
		}
	}
}

void game::GameScene::gameOver()
{
	m_isGameOver = true;
	m_drawController->clear();
	m_drawController->draw(config::GAME_OVER_LABEL);
}

game::MoveDirection game::GameScene::parseInputKey(const int key)
{
	switch (key)
	{
	case config::INPUT_KEY_LEFT:
	case config::INPUT_KEY_LEFT_ALTERNATIVE:
		return MoveDirection::Left;
	case config::INPUT_KEY_RIGHT:
	case config::INPUT_KEY_RIGHT_ALTERNATIVE:
		return MoveDirection::Right;

	default:
		return MoveDirection::None;
	}
}
