#include "Beam.h"

/**************8 You need to check to see what type of beam was requested **************/
Beam::Beam(sf::Vector2f beamPosition, BeamType type) {
	if (type == playerBeamType) {
		playerBeamSetUp(beamPosition);
	}
	else if (type == invaderBeamType) {
		invaderBeamSetUp(beamPosition);
	}
}

void Beam::playerBeamSetUp(sf::Vector2f beamPosition) {
	this->LoadTexture("playerBeam", PLAYER_BEAM);
	playerBeamSprite.setTexture(this->GetTexture("playerBeam"));
	playerBeamSprite.scale(0.5, 0.5);
	playerBeamSprite.setPosition(beamPosition);
}

void Beam::invaderBeamSetUp(sf::Vector2f beamPosition) {
	this->LoadTexture("playerBeam", PLAYER_BEAM);
	invaderBeamSprite.setTexture(this->GetTexture("playerBeam"));
	invaderBeamSprite.scale(0.5, 0.5);
	invaderBeamSprite.setPosition(beamPosition);
}

void Beam::playerBeamMove() {
	playerBeamSprite.move(0, -1);
}

void Beam::invaderBeamMove() {
	invaderBeamSprite.move(0, 1);
}

void Beam::draw(sf::RenderWindow* gameWindow) {
	gameWindow->draw(playerBeamSprite);
}

bool Beam::isInvaderBeamOffScreen() {
	sf::Vector2f position = invaderBeamSprite.getPosition();

	if (position.y > 1024) {
		return true;
		//deadFlag = true;
	}
	else {
		return false;
	}
}