#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"


struct GameData {
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;

};

typedef std::shared_ptr<GameData> GameDataPtr;

class Game {
public:
	Game(int width, int height, std::string title);

private:
	// dt is the framerate - how many times we update each second
	const float dt = 1.0f / 60.0f;
	sf::Clock clock;
	GameDataPtr data = std::make_shared<GameData>();
	void Run();

};