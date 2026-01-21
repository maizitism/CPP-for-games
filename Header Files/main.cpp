#include <iostream>
#include "Player.hpp"

void printHitpoints(const Entity& e) {
	std::cout << "hitPoints: " << e.getHitpoints() << "\n";
}

int main() {
	{
		Player player{ 100 };
		player.draw();

		Entity* e = &player;
		e->draw();
		e->update(0.1f);
	}
	return 0;
}
