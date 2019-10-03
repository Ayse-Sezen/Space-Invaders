#pragma once

#include <SFML/Graphics.hpp>

class InputManager {
public:
	InputManager() { };
	~InputManager() {};

	bool IsSpacePressed();
	bool IsLeftPressed();
	bool IsRightPressed();
};