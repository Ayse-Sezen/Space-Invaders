#include "Rock.h"

Rock::Rock(int xCoord, int yCoord) {
	this->LoadTexture("Rock", ROCK);
	rockSprite.setTexture(this->GetTexture("Rock"));
	rockSprite.setScale(0.5, 0.5);
	rockSprite.setPosition(xCoord, yCoord);
}

void Rock::draw(sf::RenderWindow* gameWindow) {
	gameWindow->draw(rockSprite);
}