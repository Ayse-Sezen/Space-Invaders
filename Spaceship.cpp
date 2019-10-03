#include "Spaceship.h"

Spaceship::Spaceship(int xCoord, int yCoord) {
	this->LoadTexture("Spaceship", SPACESHIP);
	spaceshipSprite.setTexture(this->GetTexture("Spaceship"));
	spaceshipSprite.setScale(0.5, 0.5);
	spaceshipSprite.setPosition(xCoord, yCoord);
}

void Spaceship::draw(sf::RenderWindow* gameWindow) {
	gameWindow->draw(spaceshipSprite);
}

void Spaceship::move() {
	int x = 1;
	int y = 0;
	spaceshipSprite.move(x, y);
}

void Spaceship::die() {
	this->LoadTexture("destroyedInvader", DESTROYED_INVADER);
	spaceshipSprite.setTexture(this->GetTexture("destroyedInvader"));
}

void Spaceship::resetSprite() {
	this->LoadTexture("Spaceship", SPACESHIP);
	spaceshipSprite.setTexture(this->GetTexture("Spaceship"));
}