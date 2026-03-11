#pragma once

#include <iostream>

// struct to hold all of our game data just so we can keep varaibles organised
struct GameData
{
	float positionX = 0;
	float positionY = 0;
	float speed = 100;
};

extern GameData gameData;

bool InitGame();

bool UpdateGame();

void CloseGame();