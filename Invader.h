#pragma once
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Invader : public AssetManager {
public:
	Invader() {};
	Invader(InvaderType invaderType, int xCoord, int yCoord);
	~Invader() {};

	void moveLeft();
	void moveRight();
	void moveDown();

	bool reachedRightColumn();
	bool reachedLeftColumn();

	void draw(sf::RenderWindow* gameWindow);
	void die();
	void resetSprite(InvaderType invaderType);

	bool deadFlag = false;
	bool shootFlag = false;
	bool reachedLeftCol = false;
	bool reachedRightCol = false;

	int returnScore();


	sf::Sprite invaderSprite;
	InvaderType type;
};