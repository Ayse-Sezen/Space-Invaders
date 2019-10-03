#pragma once
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Beam : public AssetManager {
public:
	Beam() {};
	Beam(sf::Vector2f invaderPosition, BeamType type);
	~Beam() {};

	void playerBeamSetUp(sf::Vector2f beamPosition);
	void invaderBeamSetUp(sf::Vector2f beamPosition);
	
	//void move();
	void playerBeamMove();
	void invaderBeamMove();

	bool isInvaderBeamOffScreen();

	void draw(sf::RenderWindow* gameWindow);

	sf::Sprite playerBeamSprite;
	sf::Sprite invaderBeamSprite;

	bool shootInvaderBeamFlag = false;
	bool deadFlag = false;

private:

};