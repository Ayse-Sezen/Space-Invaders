#pragma once
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Spaceship : public AssetManager{
public:
	Spaceship(int xCoord, int yCoord);
	~Spaceship() {};

	void draw(sf::RenderWindow* gameWindow);
	void move();
	void die();
	void resetSprite();

	sf::Sprite spaceshipSprite;

	bool deadFlag = false;
	
};