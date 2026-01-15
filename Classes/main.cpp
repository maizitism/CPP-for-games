#include <iostream>

//class is just a collection of data and methods
// methods give the class its beheavior
// data gives the class its properties, to hold some state for each instance of a class

class Entity {
	// first, define a constructor
	// will be envoked when the function is initialised
public: // make our constructor public, so an instance may be created.
	//Entity(); // this is the default constructor
	explicit Entity(int hitPoint = 100); // this is a paramaterised constructor
	// if a default value is given within the constructor, then the compiler will
	// generate both a default constructor and a parameterised one

	// when the explicit keyword is used, it will prevent the class from being initialised
	// with only an integer

	~Entity(); // destructor

	Entity(const Entity& e); // copy constructor

	int getHitpoints() const { // since class is not modified and were only returning data, we can mark this as const
		return hitPoints;
	}

	virtual void draw() const; // virtual - if we have a pointer to entity but the pointed to 
	// object is not an entity, invoke THAT objects draw function instead of
	// the draw function of the pointer. const - immutable

	virtual void update(float deltaTime) = 0; // to specify that this function as MUST be updated in the base class
	// we can mark this as pure virtual


private: // lets give the class some data
	int hitPoints = 0; // we can also initialise them in the constructor

};

class Player : public Entity { // new class, player inherits from Entity publically
	// public keyword means here all public member variables and functions of the base
	// class are public in the derived class

	// protected - all public member functions will be protected
	// private - everything that was public, becomes private to the player class

public:
	explicit Player(int hitPoints); // compiler could also automatically create one for us, not necesarry in particular
	~Player();
	// lets say i want to overwrite how the draw function works in the player class
	void draw() const override; // override is optional
	void update(float deltaTime) override; 

private:
	int score = 0;

};

Player::Player(int hitPoints) : Entity(hitPoints) {
	std::cout << "Player::Player(" << hitPoints << ")" << std::endl;
	// here, hitpoints refers to the argument being passed to the function

};
// cheeky destructor
Player::~Player() {
	std::cout << "Player::~Player()" << std::endl;
}

void Player::update(float deltaTime) {
	score += 10;
	std::cout << "Player::update(" << deltaTime << ")" << std::endl;
}
// now, lets define a function for the class
// usually, the function will return something, but the constructor doesnt return anything
Entity::Entity(int hitPoint)
: hitPoints(hitPoint){
	std::cout << "Entity::Entity(" << this->hitPoints << ")" << std::endl;
}

// lets define a function which will print these hitpoints
void printHitpoints(const Entity& e) {
	// we can only call const functions on the alias of this entity
	std::cout << "hitPoints: " << e.getHitpoints() << std::endl;
}

// lets define the destructor
Entity::~Entity() {
	// allows us to do cleanup if our class allocates dynamic memory
	std::cout << "Entity::~Entity()" << hitPoints << std::endl;	
}

// lets define the copy constructor
Entity::Entity(const Entity& e) : hitPoints (e.hitPoints){
	// do some other initialisation...
	std::cout << "Entity::Entity(const Entity& e)" << std::endl;
}
void Entity::draw() const {
	std::cout << "Entity::draw()" << std::endl; 
}
void Player::draw() const {
	std::cout << "Player::draw()" << std::endl;
}

int main() {
	//{
	//	// now, lets create an instance of the class
	//	Entity entity{ 50 };
	//	// lets print the hitpoints of that entity
	//	printHitpoints(entity);
	//	// we can abuse this function to lead to bugs
	//	//printHitpoints(10); // an another entity is being created here for whatever reason
	//	// whats happening here is called an implicit conversion from an integer
	//	// this happens when the function called is not marked as explicit

	//	// the implementation above will no longer work if the explicit keyword is added

	//	Entity entity2{ entity }; // copy of entity
	//	
	//}

	{
		Player player{ 100 };
		player.draw(); // draw the player
		// were not really doing polymorphism here, were kinda cheating
		Entity* e = &player;
		e->draw(); // this calls Entity's draw function, not the Player's
		// now that the function is virtual and being overriden, it will call
		// Player's draw function instead of Entity's
		e->update(0.1f);
	}
	return 0;
}