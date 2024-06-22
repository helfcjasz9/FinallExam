#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr){}
};

class List {
	Node* head;
public:
	List(): head(nullptr){}

	void add(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = newNode;
		}
	}

	void del(int data) {
		Node* curr = head;
		Node* prev = nullptr;

		while (curr != nullptr && curr->data != data) {
			prev = curr;
			curr = curr->next;
		}

		if (prev == nullptr) {
			head = curr->next;
		}
		else {
			prev->next = curr->next;
		}

	}

	bool search(int data){
		Node* curr = head;
		while (curr != nullptr) {
			if (curr->data == data) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}


	void display() const {
		Node* curr = head;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}



};



void main() {

	List list;

	list.add(12);
	list.add(4);
	list.add(9);
	list.add(2);

	list.display();

	if (list.search(4)) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}

	list.del(4);
	list.display();


}