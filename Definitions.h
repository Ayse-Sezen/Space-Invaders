#pragma once

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

#define INVADER1 "Invader1.png"
#define INVADER2 "Invader2.png"
#define INVADER3 "Invader3.png"

#define INVADER1_MOVE "Invader12.png"
#define INVADER2_MOVE "Invader22.png"
#define INVADER3_MOVE "Invader33.png"

#define RIGHTCOLUMN 900
#define LEFTCOLUMN 100

#define DESTROYED_INVADER "InvaderDie.png"

#define PLAYER "Player.png"
#define PLAYER_BEAM "pBeam.png"
#define DESTROYED_PLAYER "playerDie.png"

#define ROCK "Rock.png"

#define DESTROY_ROCK1 "RockDestroy1.png"
#define DESTROY_ROCK2 "RockDestroy2.png"
#define DESTROY_ROCK3 "RockDestroy3.png"
#define DESTROY_ROCK4 "RockDestroy4.png"
#define DESTROY_ROCK5 "RockDestroy5.png"
#define DESTROY_ROCK6 "RockDestroyed6.png"
#define DESTROY_ROCK7 "RockDestroyed7.png"
#define DESTROY_ROCK8 "RockDestroyed8.png"

#define SPACESHIP "Spaceship.png"

typedef enum InvaderType {
	InvaderA,
	InvaderB,
	InvaderC
} InvaderType;

typedef enum InvaderDirection {
	moveLeft,
	moveRight,
	moveDown
} InvaderDirection;

typedef enum BeamType {
	playerBeamType,
	invaderBeamType
} BeamType;

