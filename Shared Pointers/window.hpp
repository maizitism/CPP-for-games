#pragma once
#include <memory>

class WindowImpl;
class Window {
	// platform independent window type
	// we dont know if were running on linux, windows or apple
public:
	Window(); // causes error because compiler hasnt seen the class its trying
	// to delete
	~Window();

	void showWindow();

private:
	std::unique_ptr<WindowImpl> pImpl;
	// unique pointers can point to classes which are not fully defined, Yet.
};