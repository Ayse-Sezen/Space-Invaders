#include "InputManager.h"

bool InputManager::IsSpacePressed() {
	// if player presses space to shoot player beam
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		return true;
	}
	return false;
}

bool InputManager::IsLeftPressed() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
		return true;
	}

	return false;
}

bool InputManager::IsRightPressed() {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		return true;
	}

	return false;
}