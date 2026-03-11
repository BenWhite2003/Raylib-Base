#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>

GameData gameData;

// Stuff to setup our game or do at the start (like the Start() method in Unity)
bool InitGame()
{
	return true;
}

bool UpdateGame()
{
	// Sets up delta time, use this for movement and physics related stuff
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }
	

	

	if (IsKeyDown(KEY_A)) { gameData.positionX -= 1 * gameData.speed * deltaTime; }
	if (IsKeyDown(KEY_D)) { gameData.positionX += 1 * gameData.speed * deltaTime; }
	if (IsKeyDown(KEY_W)) { gameData.positionY -= 1 * gameData.speed * deltaTime; }
	if (IsKeyDown(KEY_S)) { gameData.positionY += 1 * gameData.speed * deltaTime; }

	DrawRectangle(gameData.positionX, gameData.positionY, 50, 50, { 255, 0, 0, 255 });
	return true;
}

void CloseGame()
{
	gameData = {}; // This resets all game data
	std::cout << "\n\nCLOSED!!!!!!!!!\n\n";
}
