#include "Entity.hpp"
#include <iostream>

Entity::Entity(int hitPoint)
	: hitPoints(hitPoint) {
	std::cout << "Entity::Entity(" << hitPoints << ")\n";
}

Entity::~Entity() {
	std::cout << "Entity::~Entity()" << hitPoints << "\n";
}

Entity::Entity(const Entity& e)
	: hitPoints(e.hitPoints) {
	std::cout << "Entity::Entity(const Entity&)\n";
}

void Entity::draw() const {
	std::cout << "Entity::draw()\n";
}
