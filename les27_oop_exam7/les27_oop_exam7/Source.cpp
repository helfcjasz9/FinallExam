#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
	string owner;
	string model;
	vector<Vehicle*> autoPark;
public:
	Vehicle(const string& o, const string& m): owner(o), model(m){}

	virtual ~Vehicle() {
		for (auto v : autoPark) {
			delete v;
		}
		autoPark.clear();
	}

	string getOwner()const { return owner; }
	string getModel()const { return model; }

	virtual void showInfo() {
		cout << "Model: " << model << " | Owner: " << owner << endl;
	}

};



class Car : public Vehicle {
	string carNum;
public:
	Car(const string& o, const string& m, const string& n): Vehicle(o,m), carNum(n){}

	virtual void showInfo() override {
		cout << "Car model: " << getModel() << " | Car owner: " << getOwner() << " | Car number: " << carNum << endl;
	}

};




class Truck : public Vehicle {
	string carNum;
	double allowedWeight;
public:
	Truck(const string& o, const string& m, const string& n, int w): Vehicle(o,m), carNum(n), allowedWeight(w){}

	virtual void showInfo() override {
		cout << "Truck model: " << getModel() << " | Truck owner: " << getOwner() << " | Car number: " << carNum << " | Allowed weitgh for transportation: " << allowedWeight << endl;
	}

};






void main() {
	vector<Vehicle*> vehicles = { new Car("Yura V", "Q", "AA4224AA"), new Truck("Yura", "W", "BC2343IC", 100) };
	
	for (const auto& v : vehicles) {
		v->showInfo();
		cout << endl;
	}


	for (const auto& v : vehicles) {
		delete v;
	}

	

}