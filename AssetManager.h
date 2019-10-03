#pragma once

// Using map to store all textures and fonts
// we load
#include <map>

#include <SFML/Graphics.hpp>

// Purpose of this class is to only have to load
// each texture once, which will be shared among the classes that
// use the textures (as opposed to loading the textures multiple times)

class AssetManager {
public:
	AssetManager() {};
	~AssetManager() {};

	// name is the name you're assigning to the texture for later use
	// the filename is the actual name of the file (the texture) you're loading
	void LoadTexture(std::string name, std::string fileName);

	// takes the name of the texture (that we assigned to it)
	// and returns a sf::Texture reference to it
	sf::Texture &GetTexture(std::string name);

	void LoadFont(std::string name, std::string fileName);
	sf::Font &GetFont(std::string name);

private:
	// maps names to loaded textures
	std::map<std::string, sf::Texture> textures;
	
	// maps names to loaded fonts
	std::map<std::string, sf::Font> fonts;
};