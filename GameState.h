#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <list>

#include "GameObjects.h"
#include "State.h"

class GameState : public State {
public:
	GameState(GameDataPtr gameData);
	~GameState() {};

	void Init() {};
	void HandleInput() {};
	void Update(float dt) {};
	void Draw(float dt);

private:
	GameObjects* gameObjects;
	GameDataPtr data;
	int clock = 0;
	int clock2 = 0;

};