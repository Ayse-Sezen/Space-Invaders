#include "GameState.h"

GameState::GameState(GameDataPtr gameData) : data(gameData) {
	gameObjects = new GameObjects(gameData);
}

void GameState::Draw(float dt) {
	this->data->window.clear();

	this->gameObjects->drawScore();

	this->gameObjects->drawInvaders();
	if (clock == 10) {
		this->gameObjects->invaderDirectionControls();
		clock = 0;
	}
	else {
		clock++;
	}

	this->gameObjects->drawRocks();

	this->gameObjects->drawPlayer();
	this->gameObjects->movePlayer();

	this->gameObjects->shoot(this->gameObjects->playerBeam, this->gameObjects->shootPlayerBeamFlag, playerBeamType);
	this->gameObjects->shoot(this->gameObjects->invBeam, this->gameObjects->shootInvaderBeamFlag, invaderBeamType);

	if (clock2 == 1) {
		this->gameObjects->moveSpaceship();
		clock2 = 0;
	}
	else {
		clock2++;
	}
	this->gameObjects->drawSpaceship();

	this->gameObjects->reset();
	
	this->data->window.display();
	
}