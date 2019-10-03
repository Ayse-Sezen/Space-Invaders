#pragma once
#include <iostream>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Rock : public AssetManager {
public:
	Rock(int xCoord, int yCoord);
	~Rock() {};

	virtual void draw(sf::RenderWindow* gameWindow);

	sf::Sprite rockSprite;

	bool deadFlag = false;

};