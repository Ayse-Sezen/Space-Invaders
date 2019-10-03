#pragma once

class State {
public:
	// Initializes state
	virtual void Init() = 0;

	// Handles input on that state
	virtual void HandleInput() = 0;

	// Updates variables (based on input)
	virtual void Update(float dt) = 0;

	// Draw to the screen
	virtual void Draw(float dt) = 0;

	virtual void Pause() {};
	virtual void Resume() {};

private:

};