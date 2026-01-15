#include <iostream>

//class is just a collection of data and methods
// methods give the class its beheavior
// data gives the class its properties, to hold some state for each instance of a class

class Entity {
	// first, define a constructor
	// will be envoked when the function is initialised
public: // make our constructor public, so an instance may be created.
	//Entity(); // this is the default constructor
	Entity(int hitPoint = 100); // this is a paramaterised constructor
	// if a default value is given within the constructor, then the compiler will
	// generate both a default constructor and a parameterised one

private: // lets give the class some data
	int hitPoints = 0; // we can also initialise them in the constructor

};
// now, lets define a function for the class
// usually, the function will return something, but the constructor doesnt return anything
Entity::Entity(int hitPoint)
: hitPoints(hitPoint){
	std::cout << "Entity::Entity(" << this->hitPoints << ")" << std::endl;
}


int main() {
	// now, lets create an instance of the class
	Entity entity{50};
	return 0;
}