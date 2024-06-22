#include <iostream>
#include <ctime>
using namespace std;


// метод this використовується щоб відрізняти змінні класу від інших змінних і параметрів



class Matrix {
	int rows;
	int cols;
	int** data;
public:

	Matrix(int r, int c) : rows(r), cols(c) {
		data = new int* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				data[i][j] = 1;
			}
		}
	}

	Matrix(const Matrix& other): rows(other.rows), cols(other.cols){
		this->data = new int* [rows];
		for (int i = 0; i < rows; ++i) {
			this->data[i] = new int[cols];
			for (int j = 0; j < cols; ++j) {
				this->data[i][j] = other.data[i][j]; 
			}
		}
	}

	void fill() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				this->data[i][j] = rand() % 10;
			}
		}
	}


	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << this->data[i][j] << " ";
			}
			cout << endl;
		}
	}


};


void main() {

	srand(time(0));

	Matrix m1(4, 4);
	m1.fill();
	m1.print();

	cout << endl;

	Matrix copy = m1;
	copy.print();


}