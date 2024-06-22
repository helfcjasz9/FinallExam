#include <iostream>

using namespace std;

class Vector {
	double x, y, z;
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z){}
	Vector(Vector&& other) noexcept : x(0), y(0), z(0) {
		x = other.x;
		y = other.y;
		z = other.z;

		other.x = 0;
		other.y = 0;
		other.z = 0;
	}


	Vector operator+(const Vector& other) const {
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	Vector operator-(const Vector& other) const {
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	double operator*(const Vector& other) const {
		return double(x * other.x + y * other.y + z * other.z);
	}


	bool operator==(const Vector& other) const {
		return (x == other.x) && (y == other.y) && (z == other.z);
	}

	bool operator!=(const Vector& other) const {
		return (x != other.x) || (y != other.y) || (z != other.z);
	}

	


	friend ostream& operator << (ostream& os, const Vector& vec) {
		os << "(" << vec.x << ";" << vec.y << ";" << vec.z << ")" << endl;
		return os;
	}




};



void main() {

	Vector v1(2, 3, 4);
	Vector v2(2, 3, 4);

	cout << "Vector 1: " << v1;
	cout << "Vector 2: " << v2;


	cout << "Sum: " << v1 + v2;
	cout << "Sub: " << v1 - v2;
	cout << "Mul: " << v1 * v2 << endl;

	if (v1 == v2) {
		cout << "equal" << endl;
	}
	else {
		cout << "different" << endl;
	}

	if (v1 != v2) {
		cout << "different2" << endl;
	}
	else {
		cout << "equal2" << endl;
	}


}