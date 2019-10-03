#pragma once
#include "AssetManager.h"
#include "Definitions.h"
#include <SFML/Graphics.hpp>

class AssetStorage : public AssetManager {
public:
	AssetStorage();
	~AssetStorage() {};


private:
	sf::Sprite Invader1;
	sf::Sprite Invader2;
	sf::Sprite Invader3;

	sf::Sprite invader1Move;
	sf::Sprite invader2Move;
	sf::Sprite invader3Move;

	sf::Sprite destroyedInvader;
	
	sf::Sprite Player;
	sf::Sprite playerBeam;
	sf::Sprite destroyedPlayer;

	sf::Sprite Rock;

	sf::Sprite destroyRock1;
	sf::Sprite destroyRock2;
	sf::Sprite destroyRock3;
	sf::Sprite destroyRock4;
	sf::Sprite destroyRock5;
	sf::Sprite destroyRock6;
	sf::Sprite destroyRock7;
	sf::Sprite destroyRock8;

	sf::Sprite Spaceship;
};