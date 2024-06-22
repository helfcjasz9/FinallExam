#include <iostream>
#include <queue>

using namespace std;

template <typename T>

class Queue {
	queue<T> elements;
public:
	
	void add(const T& elem) {
		elements.push(elem);
	}

	void del() {
		elements.pop();
	}

	T fisrt() {
		return elements.front();
	}

	bool isEmpty() {
		return elements.empty();
	}

	void print() {
		queue<T> temp = elements;

		while (!temp.empty()) {
			cout << temp.front() << " ";
			temp.pop();
		}
		cout << endl;
		
	}

};


void main() {

	Queue <int> nums;

	nums.add(9);
	nums.add(6);
	nums.add(19);
	nums.add(15);

	nums.print();

	cout << "First num: " << nums.fisrt() << endl;
	nums.del();
	nums.print();

	if (!nums.isEmpty()) {
		cout << "Not empty!" << endl;
	}

}