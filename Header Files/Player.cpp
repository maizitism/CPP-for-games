#include "Player.hpp"

#include <iostream>

Player::Player(int hitPoints)
	: Entity(hitPoints) {
	std::cout << "Player::Player(" << hitPoints << ")\n";
}

Player::~Player() {
	std::cout << "Player::~Player()\n";
}

void Player::update(float deltaTime) {
	score += 10;
	std::cout << "Player::update(" << deltaTime << ")\n";
}

void Player::draw() const {
	std::cout << "Player::draw()\n";
}