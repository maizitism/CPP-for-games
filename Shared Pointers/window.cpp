#include "window.hpp"

#include <iostream>

class WindowImpl {
public:
	WindowImpl() = default;
	virtual ~WindowImpl() = default; // minimum required for abstract base class

	virtual void showWindow() = 0;
};

//macro to check we are running on windows
#if _WIN32
class WindowWin32 : public WindowImpl {
public:
	void showWindow() override {
		std::cout << "WindowWin32::showWindow()" << std::endl;
	}
};
using WindowType = WindowWin32;
#else
class WindowGeneric : public WindowImpl {
public:
	void showWindow() override {
		std::cout << "WindowGeneric::showWindow()" << std::endl;
	}
};
using WindowType = WindowGeneric;
#endif

Window::Window() {
	pImpl = std::make_unique<WindowType>();
}
// destructor must be created the same file where the implmenetation happens
Window::~Window() = default;

void Window::showWindow() {
	pImpl->showWindow();
}