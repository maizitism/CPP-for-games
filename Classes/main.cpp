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

	int getHitpoints() const { // since class is not modified and were only returning data, we can mark this as const
		return hitPoints;
	}


private: // lets give the class some data
	int hitPoints = 0; // we can also initialise them in the constructor

};
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

int main() {
	// now, lets create an instance of the class
	Entity entity{50};
	// lets print the hitpoints of that entity
	printHitpoints(entity);
	// we can abuse this function to lead to bugs
	//printHitpoints(10); // an another entity is being created here for whatever reason
	// whats happening here is called an implicit conversion from an integer
	// this happens when the function called is not marked as explicit

	// the implementation above will no longer work if the explicit keyword is added


	//Entity entity2 = 100; // valid because we have a parameterised constructor which takes an int
	// this doesnt work anymore because we have an explicit keyword infront of our constructor

	return 0;
}