#include "AssetManager.h"

void AssetManager::LoadTexture(std::string name, std::string fileName) {
	sf::Texture tex;

	// if texture was successfully loaded...
	if (tex.loadFromFile(fileName)) {
		// store texture with associated name in map
		this->textures[name] = tex;
	}

}

sf::Texture &AssetManager::GetTexture(std::string name) {
	// returns the texture mapped to the given name
	return this->textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName) {
	sf::Font font;

	// if font was successfully loaded...
	if (font.loadFromFile(fileName)) {
		// store font with associated name in map
		this->fonts[name] = font;
	}

}

sf::Font &AssetManager::GetFont(std::string name) {
	// returns the font mapped to the given name
	return this->fonts.at(name);
}

