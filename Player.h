#pragma once
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Player : public AssetManager {
public:
	Player(int xCoord, int yCoord);
	~Player() {};

	virtual void draw(sf::RenderWindow* gameWindow);
	void moveLeft();
	void moveRight();
	void die();
	void resetSprite();

	sf::Sprite playerSprite;

	bool deadFlag = false;
	bool shootFlag = false;

};