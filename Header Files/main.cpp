#include <iostream>

class Entity {
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

class Player : public Entity {
public:
	explicit Player(int hitPoints);
	~Player();

	void draw() const override;
	void update(float deltaTime) override;

private:
	int score = 0;
};

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

void Player::draw() const {
	std::cout << "Player::draw()\n";
}

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
