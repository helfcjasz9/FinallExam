#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception> 
#include <string>
using namespace std;

class fileAvailability : public exception {
private:
	string message;
public: fileAvailability(const string& m) : message(m) {}
	  virtual const char* what() const noexcept override {
		  return message.c_str();
	  }
};


class incorrectNumber : public exception {
	string message;
public:
	incorrectNumber(const string& m) :message(m) {}
	virtual const char* what()const noexcept override {
		return message.c_str();
	}
};


void saveToFile() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    try {
        if (num < 0) {
            throw incorrectNumber("Number is less than 0");
        }

        ofstream ofile("num.txt", ios::trunc);
        if (!ofile.is_open()) {
            throw fileAvailability("Unable to open the file");
        }

        ofile << num;
        ofile.close();
    }
    catch (const fileAvailability& error) {
        cerr << error.what() << endl;
    }
    catch (const incorrectNumber& error) {
        cerr << error.what() << endl;
    }
}



void readFromFile() {

    try {

        ifstream ifile("num.txt");

        if (!ifile.is_open()) {
            throw fileAvailability("Unable to open the file");
        }
        
        string line;

        while (getline(ifile, line)) {
            cout << line << endl;
        }

        ifile.close();
    }
    catch (const fileAvailability& e) {
        cerr << e.what() << endl;
    }

}



void main() {

    saveToFile();
    readFromFile();

}