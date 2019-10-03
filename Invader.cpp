#include "Invader.h"

Invader::Invader(InvaderType invaderType, int xCoord, int yCoord) {
	if (invaderType == InvaderA) {
		type = InvaderA;
		this->LoadTexture("Invader1", INVADER1);
		invaderSprite.setTexture(this->GetTexture("Invader1"));
	}
	else if (invaderType == InvaderB) {
		type = InvaderB;
		this->LoadTexture("Invader2", INVADER2);
		invaderSprite.setTexture(this->GetTexture("Invader2"));
	}
	else if (invaderType == InvaderC) {
		type = InvaderC;
		this->LoadTexture("Invader3", INVADER3);
		invaderSprite.setTexture(this->GetTexture("Invader3"));
	}

	invaderSprite.setScale(0.5, 0.5);
	invaderSprite.setPosition(xCoord, yCoord);

}

void Invader::die() {
	this->LoadTexture("destroyedInvader", DESTROYED_INVADER);
	invaderSprite.setTexture(this->GetTexture("destroyedInvader"));
}

void Invader::draw(sf::RenderWindow* gameWindow) {
	/*gameWindow->draw(invaderSprite);*/

}

void Invader::moveLeft() {
	int x = -1;
	int y = 0;
	invaderSprite.move(x, y);

	if (reachedLeftColumn()) {
		reachedLeftCol = true;
	}
}

void Invader::moveRight() {
	int x = 1;
	int y = 0;
	invaderSprite.move(x, y);

	if (reachedRightColumn()) {
		reachedRightCol = true;
	}
}

void Invader::moveDown() {
	
	int x = 0;
	int y = 40;
	invaderSprite.move(x, y);

	if (reachedLeftCol) {
		reachedLeftCol = false;
	}
	
	if (reachedRightCol) {
		reachedRightCol = false;
	}
}

bool Invader::reachedRightColumn() {
	sf::Vector2f position = invaderSprite.getPosition();

	if (position.x >= RIGHTCOLUMN) {
		return true;
	}

	return false;
}

bool Invader::reachedLeftColumn() {
	sf::Vector2f position = invaderSprite.getPosition();

	if (position.x <= LEFTCOLUMN) {
		return true;
	}

	return false;
}

void Invader::resetSprite(InvaderType invaderType) {
	if (invaderType == InvaderA) {
		this->LoadTexture("Invader1", INVADER1);
		invaderSprite.setTexture(this->GetTexture("Invader1"));
	}
	else if (invaderType == InvaderB) {
		this->LoadTexture("Invader2", INVADER2);
		invaderSprite.setTexture(this->GetTexture("Invader2"));
	}
	else if (invaderType == InvaderC) {
		this->LoadTexture("Invader3", INVADER3);
		invaderSprite.setTexture(this->GetTexture("Invader3"));
	}
}

int Invader::returnScore() {
	if (deadFlag) {
		if (type == InvaderC) {
			return 10;
		}
		else if (type == InvaderB) {
			return 20;
		}
		else if (type == InvaderA) {
			return 40;
		}
	}
}