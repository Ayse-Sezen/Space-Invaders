#include "Game.h"
#include "GameState.h"

// This is the only function which will be called in main
Game::Game(int width, int height, std::string title) {
	// Set up window
	data->window.create(sf::VideoMode(width, height), title,
		sf::Style::Close | sf::Style::Titlebar);

	// Implement a state
	data->machine.AddState(StatePtr(new GameState(this->data)));

	// Run the game
	this->Run();
}

void Game::Run() {
	float newTime, frameTime, interpolation;

	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->data->window.isOpen()) {

		// checks for changes in state
		this->data->machine.ProcessStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			this->data->machine.GetActiveState()->HandleInput();
			this->data->machine.GetActiveState()->Update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->data->machine.GetActiveState()->Draw(interpolation);
	}
}
