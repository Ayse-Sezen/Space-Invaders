#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <list>

#include "AssetStorage.h"
#include "Beam.h"
#include "Definitions.h"
#include "Game.h"
#include "Invader.h"
#include "Player.h"
#include "Rock.h"
#include "Spaceship.h"


class GameObjects {
public:
	GameObjects(GameDataPtr gameData);
	~GameObjects() {};

	void setUpInvaders();
	void setUpPlayer();
	void setUpSpaceship();
	void setUpRocks();
	void setUpScore();

	void drawInvaders();
	void drawSpaceship();
	void drawPlayer();
	void drawRocks();
	void drawScore();

	void invaderDirectionControls();
	void moveInvaders();
	void movePlayer();
	void moveSpaceship();

	void shootInvaderBeam();
	void shootPlayerBeam();
	void shoot(Beam* beam, bool flag, BeamType type);

	void invaderDies(std::list<Invader*>::iterator it);
	void playerDies();
	void spaceshipDies();

	void reset();
	void didInvaderReachRocks(std::list<Invader*>::iterator it);

	Beam* playerBeam;
	Beam* invBeam;

	bool shootInvaderBeamFlag = false;
	bool shootPlayerBeamFlag = false;
	bool resetFlag = false;

private:
	GameDataPtr data;

	int xCoord = 0;
	int yCoord = 0;
	std::list<std::list<Invader*>> invaderGrid;
	std::list<Rock*> rocks;
	Player* player;
	Spaceship* spaceShip;
	bool setFlag = false;

	InvaderDirection direction = moveLeft;
	bool moveDownFlag = false;

	sf::Font font;
	sf::Text text;
	sf::Text pointsText;

	int score = 0;
	std::string pointsString;

};
