#include <iostream>
#include <cstdint>

enum {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int day = Monday; // unscoped enum. a c thing, more then cpp.

enum class Color : uint32_t {
	Black = 0x000000,
	Red = 0xFF0000,
	Green = 0x00FF00,
	Blue = 0x0000FF,
	White = Red | Green | Blue,
	LightGray, //gets value of White+1
};

Color red = Color::Red;
uint32_t green = static_cast<uint32_t>(Color::Green);

enum class GameState {
	MainMenu,
	Game,
	GameOver,
	HighScores
};

void doMainMenu();
void drawEndScreen();

int main() {

	GameState gameState = GameState::MainMenu;

	switch (gameState) {
		case GameState::MainMenu:
			doMainMenu;
			break;
		case GameState::GameOver:
			drawEndScreen;
			break;
		// etc, etc...
	}


	return 0;
}