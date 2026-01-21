#pragma once

class Entity{
public:
	explicit Entity(int hitPoint = 100);
	virtual ~Entity();
	Entity(const Entity& e);

	int getHitpoints() const { return hitPoints; }

	virtual void draw() const;
	virtual void update(float deltaTime) = 0;

private:
	int hitPoints = 0;
};