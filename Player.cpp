#include "Player.h"

Player::Player(int xCoord, int yCoord) {
	this->LoadTexture("Player", PLAYER);
	playerSprite.setTexture(this->GetTexture("Player"));
	playerSprite.setScale(0.5, 0.5);
	playerSprite.setPosition(xCoord, yCoord);
}

void Player::draw(sf::RenderWindow* gameWindow) {
	gameWindow->draw(playerSprite);
}

void Player::moveLeft() {
	playerSprite.move(-1, 0);
}

void Player::moveRight() {
	playerSprite.move(1, 0);
}

void Player::die() {
	this->LoadTexture("destroyedPlayer", DESTROYED_PLAYER);
	playerSprite.setTexture(this->GetTexture("destroyedPlayer"));
}

void Player::resetSprite() {
	this->LoadTexture("Player", PLAYER);
	playerSprite.setTexture(this->GetTexture("Player"));
	//playerSprite.setScale(0.5, 0.5);
}