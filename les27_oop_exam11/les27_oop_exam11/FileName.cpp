#include <iostream>
#include <stdexcept>


using namespace std;

// dynamic_cast доцільно використовувати для того, щоб перевірити можливість перетворення вказівника


class Base {
public:
	Base() = default;

	virtual void func() {
		cout << "base function" << endl;
	}
};


class Derived : public Base {
public:
	Derived() = default;

	void func() override {
		cout << "derived func" << endl;	
	}
};

void changePtr(Base* ptr) {
	Derived* derivedPtr = dynamic_cast<Derived*>(ptr);
	if (derivedPtr) {
		derivedPtr->func();
	}
	else {
		throw bad_cast();
	}
}
void main() {

	try {
		Base b;
		Derived d;
		changePtr(&d);

		changePtr(&b);

	}
	catch (const bad_cast& e) {
		cerr << "Error: " << e.what() << endl;
	}
}