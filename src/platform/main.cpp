#include <iostream>	
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>

int main()
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // no log output by raylib in a production build
#endif
	// Lets the window be resizable
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	// Initialise the window
	InitWindow(800, 450, "My Game Window");

	SetExitKey(KEY_NULL); // Disable Esc from closing the window
	SetTargetFPS(240); // Sets the max FPS

	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO(); // allows us to change settings with ImGui
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Turns on docking
	io.FontGlobalScale = 1.5; // Sets the font size
	

	if (!InitGame()) // Sets up the game
	{
		return 0;
	}
	while (!WindowShouldClose()) // Sets up the window
	{
		BeginDrawing(); // All stuff needed drawing at runtime must go between BeginDrawing and EndDrawing
		ClearBackground(BLACK);
		
		rlImGuiBegin(); // All imgui code goes between begin and end imgui rl

		// Docking
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);

		// Simple window to change player speed
		ImGui::Begin("Player Window");
		ImGui::SliderFloat("Speed", &gameData.speed, 100, 300);
		ImGui::End();
		

		if (!UpdateGame())
		{
			CloseWindow();
		}

		rlImGuiEnd();

		EndDrawing();
	}
	
	rlImGuiShutdown();
	CloseWindow();

	CloseGame(); // Ending the game, useful for saving

	return 0;
}