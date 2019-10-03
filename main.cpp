#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Game.h"

int main()
{
	Game game(1024, 1024, "Space Invaders");

	return EXIT_SUCCESS;
}