#include <iostream>

using namespace std;

class Shape {
public:
	Shape() = default;

	virtual void area() const = 0;
};


class Triangle : public Shape {
public:
	Triangle() = default;

	void area() const override {
		double h, a;

		cout << "Enter length of basis: ";
		cin >> a;
		cout << "Enter length of height: ";
		cin >> h;

		double res = ((a * h) / 2) * 1.0;

		cout << "Area of triangle: " << res << endl;

	}

};



class Square : public Shape {
public:
	Square() = default;
	void area() const override {
		double s;

		cout << "Enter side of square: ";
		cin >> s;

		double res = (s * s) * 1.0;

		cout << "Area of square: " << res << endl;
	}
};



class Circle : public Shape {
public:
	Circle() = default;
	void area() const override {
		double r;

		cout << "Enter radius: ";
		cin >> r;

		double res = (3.14 * (r * r)) * 1.0;

		cout << "Area of circle: " << res << endl;
	}
};



void opers() {
	cout << "1 - triangle" << endl;
	cout << "2 - square" << endl;
	cout << "3 - circle" << endl;
	cout << "4 - exit" << endl;
	cout << "Operation >> ";
}



void main() {
	int op;

	Triangle t;
	Square s;
	Circle c;

	do {
		opers();
		cin >> op;

		switch (op) {
		case 1:
			t.area();
			break;
		case 2:
			s.area();
			break;
		case 3:
			c.area();
			break;
		case 4:
			break;
		default:
			cout << "Invalid operation!" << endl;
			opers();
			cin >> op;
		}


	} while (op != 4);










}