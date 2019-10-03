#include "GameObjects.h"

GameObjects::GameObjects(GameDataPtr gameData) : data(gameData) {
	// Allocates/Stores game objects
	setUpInvaders();
	setUpPlayer();
	setUpSpaceship();
	setUpRocks();
	setUpScore();
}

/************************ Set Up Functions *************************/

void GameObjects::setUpInvaders() {
	
	for (int i = 0; i != 12; i++) {
		this->invaderGrid.push_back(*(new std::list<Invader*>));
	}

	std::list<std::list<Invader*>>::iterator it;
	

	xCoord = 128;

	for (it = this->invaderGrid.begin(); it != this->invaderGrid.end(); it++) {
		yCoord = 100;
		(*it).push_back(new Invader(InvaderA, xCoord, yCoord));
		
		yCoord += 80;
		(*it).push_back(new Invader(InvaderB, xCoord, yCoord));

		yCoord += 80;
		(*it).push_back(new Invader(InvaderB, xCoord, yCoord));

		yCoord += 80;
		(*it).push_back(new Invader(InvaderC, xCoord, yCoord));

		yCoord += 80;
		(*it).push_back(new Invader(InvaderC, xCoord, yCoord));

		xCoord += 64;
	}

}

void GameObjects::setUpPlayer() {
	this->player = new Player(1024 / 2, 1024 - 100);
}

void GameObjects::setUpSpaceship() {
	this->spaceShip = new Spaceship(0, 20);
}

void GameObjects::setUpRocks() {
	xCoord = 180;
	yCoord = 800;

	for (int i = 0; i < 4; i++) {
		this->rocks.push_back(new Rock(xCoord, yCoord));
		xCoord += 192;
	}
}

void GameObjects::setUpScore() {
	
	if (!font.loadFromFile("slkscr.ttf")) {
		std::cout << "Could not load font file slkscr.ttf" << std::endl;
	}


	pointsText.setFont(font);
	pointsText.setCharacterSize(30);
	pointsText.setFillColor(sf::Color::White);
	pointsText.setPosition(0, 0);

	pointsString.clear();
	pointsString = "Score: " + std::to_string(score) + " pts";
	pointsText.setString(pointsString);

}

/*********************** Draw Functions ************************/

void GameObjects::drawInvaders(){
	std::list<std::list<Invader*>>::iterator it;
	std::list<Invader*>::iterator invader;

	for (it = invaderGrid.begin(); it != invaderGrid.end(); it++) {
		// check if invader column isn't empty
		if (!(*it).empty()) {
			for (invader = (*it).begin(); invader != (*it).end(); invader++) {
				// make sure individual invader isn't dead
				if (!(*invader)->deadFlag) {
					this->data->window.draw((*invader)->invaderSprite);
				}
			}
		}
	}
}

void GameObjects::drawRocks() {
	std::list<Rock*>::iterator it;
	for (it = this->rocks.begin(); it != this->rocks.end(); it++) {
		this->data->window.draw((*it)->rockSprite);
	}
}

void GameObjects::drawPlayer() {
	this->data->window.draw(this->player->playerSprite);
}

void GameObjects::drawSpaceship() {
	if (!this->spaceShip->deadFlag) {
		this->data->window.draw(this->spaceShip->spaceshipSprite);
	}
}

void GameObjects::drawScore() {
	this->data->window.draw(this->pointsText);
}

/********************** Move Functions *********************/

void GameObjects::invaderDirectionControls() {
	if (direction == moveLeft && !moveDownFlag) {
		moveInvaders();

		/* Fix the below doneMoving mechanism to look more professional */
		if (setFlag) {
			moveDownFlag = true;
		}
	}
	else if (direction == moveRight && !moveDownFlag) {
		moveInvaders();
		if (setFlag) {
			moveDownFlag = true;
		}
	}
	else if (moveDownFlag) {
		moveInvaders();

		moveDownFlag = false;
		setFlag = false;

		if (direction == moveLeft) {
			direction = moveRight;
		}
		else if (direction == moveRight) {
			direction = moveLeft;
		}
	}

	if (!shootInvaderBeamFlag) {
		shootInvaderBeam();
	}
}

void GameObjects::moveInvaders() {
	std::list<std::list<Invader*>>::iterator it;
	std::list<Invader*>::iterator invader;

	for (it = invaderGrid.begin(); it != invaderGrid.end(); it++) {
		// check if invader column isn't empty
		if (!(*it).empty()) {
			for (invader = (*it).begin(); invader != (*it).end(); invader++) {
				// make sure individual invader isn't dead
				if (!(*invader)->deadFlag) {
					if (direction == moveLeft && !moveDownFlag) {
						// move the invader
						(*invader)->moveLeft();

						// check if invader is out of bounds
						if ((*invader)->reachedLeftCol) {
							setFlag = true;
						}
					}
					else if (direction == moveRight && !moveDownFlag) {
						(*invader)->moveRight();
						
						if ((*invader)->reachedRightCol) {
							setFlag = true;
						}
					}
					else if (moveDownFlag) {
						(*invader)->moveDown();
					}

					// draw the invader 

					this->data->window.draw((*invader)->invaderSprite);

					// check if invader was hit by a player beam
					invaderDies(invader);

					// check if invader reached the rocks
					didInvaderReachRocks(invader);
				}
			}
		}
	}
}

void GameObjects::movePlayer() {
	if (!this->player->deadFlag) {
		if (this->data->input.IsLeftPressed()) {
			// move player left
			this->player->moveLeft();
			this->data->window.draw(this->player->playerSprite);
		}
		else if (this->data->input.IsRightPressed()) {
			// move player right
			this->player->moveRight();
			this->data->window.draw(this->player->playerSprite);
		}
		else if (this->data->input.IsSpacePressed()) {
			// shoot the player beam
			shootPlayerBeam();
		}
	}

	// check if the player dies
	playerDies();
}

void GameObjects::moveSpaceship() {
	if (!this->spaceShip->deadFlag) {
		this->spaceShip->move();
		this->data->window.draw(this->spaceShip->spaceshipSprite);
	}

	// check if spaceship dies
	spaceshipDies();
}

// ******************************* Shoot Beam Functions *******************************

void GameObjects::shootInvaderBeam() {
	int randomColumn = (rand() % 11);

	std::list<std::list<Invader*>>::iterator it;
	it = this->invaderGrid.begin();

	// increment grid iterator until you reach desired column
	for (int i = 0; i < randomColumn; i++) {
		it++;
	}

	std::list<Invader*>::reverse_iterator rit;
	rit = (*it).rbegin();

	// find the last live invader in column
	while ((*rit)->deadFlag && (rit != (*it).rend())) {
		++rit;
	}

	// shoot beam from that invader
	if (!(*it).empty()) {
		invBeam = new Beam((*rit)->invaderSprite.getPosition(), invaderBeamType);
		shootInvaderBeamFlag = true;
	}
}

void GameObjects::shootPlayerBeam() {
	playerBeam = new Beam(player->playerSprite.getPosition(), playerBeamType);
	shootPlayerBeamFlag = true;
}

void GameObjects::shoot(Beam* beam, bool flag, BeamType type) { 
	if (flag) {
		if (type == playerBeamType) {
			beam->playerBeamMove();
			this->data->window.draw(beam->playerBeamSprite);
		}
		if (type == invaderBeamType) {
			beam->invaderBeamMove();
			this->data->window.draw(beam->invaderBeamSprite);
			if (beam->isInvaderBeamOffScreen()) {
				shootInvaderBeamFlag = false;
			}
		}
	}
}

/***************************** Die functions ***************************/

void GameObjects::invaderDies(std::list<Invader*>::iterator it) {
	sf::FloatRect invaderBounds = (*it)->invaderSprite.getGlobalBounds();
	sf::FloatRect rockBounds;
	if (shootPlayerBeamFlag) {
		if (invaderBounds.intersects(this->playerBeam->playerBeamSprite.getGlobalBounds())) {
			// Stop drawing player beam
			shootPlayerBeamFlag = false;

			// Draw destroyedInvader.png
			(*it)->die();
			this->data->window.draw((*it)->invaderSprite);

			// Stop drawing invader
			(*it)->deadFlag = true;

			// Add to the score
			score += (*it)->returnScore();

			pointsString.clear();
			pointsString = "Score: " + std::to_string(score) + " pts";
			pointsText.setString(pointsString);
		}
		else {
			std::list<Rock*>::iterator it;
			for (it = this->rocks.begin(); it != this->rocks.end(); it++) {
				rockBounds = (*it)->rockSprite.getGlobalBounds();

				if (rockBounds.intersects(this->playerBeam->playerBeamSprite.getGlobalBounds())) {
					shootPlayerBeamFlag = false;
				}
			}
		}
	}
}

void GameObjects::playerDies() {
	sf::FloatRect playerBounds = this->player->playerSprite.getGlobalBounds();
	sf::FloatRect rockBounds;

	if (shootInvaderBeamFlag) {
		if (playerBounds.intersects(this->invBeam->invaderBeamSprite.getGlobalBounds())) {
			// stop drawing invader beam
			shootInvaderBeamFlag = false;

			// draw destroyedPlayer.png
			this->player->die();
			this->data->window.draw(this->player->playerSprite);

			// stop drawing player
			this->player->deadFlag = true;
			resetFlag = true;
		}
		else {
			std::list<Rock*>::iterator it;
			for (it = this->rocks.begin(); it != this->rocks.end(); it++) {
				rockBounds = (*it)->rockSprite.getGlobalBounds();

				if (rockBounds.intersects(this->invBeam->invaderBeamSprite.getGlobalBounds())) {
					shootInvaderBeamFlag = false;
				}
			}
		}
	}
}

void GameObjects::spaceshipDies() {
	sf::FloatRect spaceshipBounds = this->spaceShip->spaceshipSprite.getGlobalBounds();

	if (shootPlayerBeamFlag) {
		if (spaceshipBounds.intersects(this->playerBeam->playerBeamSprite.getGlobalBounds())) {
			shootPlayerBeamFlag = false;
			this->spaceShip->deadFlag = true;
			this->spaceShip->die();
			this->data->window.draw(this->spaceShip->spaceshipSprite);	
		}
	}
}

/****************************** Reset Function *****************************************/

void GameObjects::reset() {
	if (resetFlag) {
		std::list<std::list<Invader*>>::iterator it;
		std::list<Invader*>::iterator invader;
		xCoord = 128;
		int ctr = 1;

		// Reset the invader Grid
		for (it = this->invaderGrid.begin(); it != this->invaderGrid.end(); it++) {
			yCoord = 100;
			for (invader = (*it).begin(); invader != (*it).end(); invader++) {
				if (ctr == 1) {
					(*invader)->resetSprite(InvaderA);
				}
				else if (ctr == 2 || ctr == 3) {
					(*invader)->resetSprite(InvaderB);
				}
				else if (ctr == 4 || ctr == 5) {
					(*invader)->resetSprite(InvaderC);
				}
				(*invader)->deadFlag = false;
				(*invader)->invaderSprite.setPosition(xCoord, yCoord);
				this->data->window.draw((*invader)->invaderSprite);
				yCoord += 80;
				ctr++;
			}
			ctr = 1;
			xCoord += 64;
		}

		// Reset Player
		this->player->resetSprite();
		this->player->deadFlag = false;
		this->player->playerSprite.setPosition(1024 / 2, 1024 - 100);
		this->data->window.draw(this->player->playerSprite);

		// Reset Spaceship
		this->spaceShip->resetSprite();
		this->spaceShip->deadFlag = false;
		this->spaceShip->spaceshipSprite.setPosition(0, 20);
		this->data->window.draw(this->spaceShip->spaceshipSprite);

		// reset Score
		score = 0;
		pointsString.clear();
		pointsString = "Score: " + std::to_string(score) + " pts";
		pointsText.setString(pointsString);

		resetFlag = false;
	}
}

void GameObjects::didInvaderReachRocks(std::list<Invader*>::iterator it) {
	sf::FloatRect invaderBounds = (*it)->invaderSprite.getGlobalBounds();
	sf::FloatRect rockBounds;

	std::list<Rock*>::iterator rockIt;
	for (rockIt = this->rocks.begin(); rockIt != this->rocks.end(); rockIt++) {
		rockBounds = (*rockIt)->rockSprite.getGlobalBounds();

		if (rockBounds.intersects((*it)->invaderSprite.getGlobalBounds())) {
			resetFlag = true;
		}
	}
}