#include "window.hpp"

#include <iostream>
#include <memory>

class Widget {
public:
	//create constructor
	Widget(int data = 0) : data{ data } {
		std::cout << "Widget:Widget( " << data << " )" << std::endl;
	}
	//create destructor
	~Widget() {
		std::cout << "~Widget::Widget()" << std::endl;
	}

	void doSomething() {
		std::cout << "Do something." << std::endl;
	}
private:
	//create member variable
	int data = 0;
};


// lets suppose that our widget class needs a special deletor
struct WidgetDeleter { // everything in a struct is public by default
	void operator()(Widget* w) {
		std::cout << "WidgetDeleter::operator()" << std::endl;
		delete w; // the default deletor will do this automatically
	}
};


int main() {
	
	// we can omit the shared pointer type and use auto as the type
	// is already defined in the other side of the assignment
	// auto widget = std::shared_ptr<Widget>(new Widget(1));

	//with shared pointers, we no longer need to control when its deleted
	// we dont need to use the new keyword

	// a better method would be to use the make_shared function
	auto widget = std::make_shared<Widget>(1); // preferred method
	// since its a smart pointer, it gets automatically deleted when
	// it goes out of scope

	// we can allow multiple instances of this

	std::cout << "Use count: " << widget.use_count() << std::endl;
	auto widget2 = widget;
	std::cout << "Use count: " << widget.use_count() << std::endl;
	// widget isnt destroyed until both go out of scope

	{
		std::weak_ptr<Widget> wPtr;
		wPtr = widget; // this will not increment the use count.
		std::cout << "Use count: " << widget.use_count() << std::endl;

		// for the weak pointer not to go out of scope, we can lock it
		if (!wPtr.expired()) {
			auto widget_weak_locked = wPtr.lock();
			// this returns a shared pointer to the original widget
		}
	
	}
	
	auto customWidget = std::shared_ptr<Widget>(new Widget(1), WidgetDeleter());
	// we can give shared pointers custom deletors, but it has to be initialised
	// "manually"

	//auto uPtr = std::unique_ptr<Widget>(new Widget(2)); // again, new keyword
	auto uPtr = std::make_unique<Widget>(2);
	//so, since its now an unique pointer, you cant do the following

	//auto uPtr2 = uPtr; not allowed
	// if you really want to, you can move it into the new variable
	auto uPtr2 = std::move(uPtr); // uPtr becomes empty

	// this is used in the case of exceptions, where a normally allocated
	// widget would not get returned abck to the free memory store if
	// it has gone out of scope, but this will clean it up for us
	// using unique pointers is RAII safe. (bomb.)



	Window win; // magic of the mem allocation happens in the unique pointer of
	// the class
	win.showWindow();
	return 0;
}