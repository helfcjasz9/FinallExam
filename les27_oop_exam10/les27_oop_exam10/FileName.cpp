#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace Utilities {

	bool isAvailableREAD(const string& filename) {
		ifstream ifile(filename);
		return ifile.is_open();
	}

	bool isAvailableSAVE(const string& filename) {
		ofstream ofile(filename);
		return ofile.is_open();
	}


	void saveToFile() {
		string line;
		cout << "Enter text: ";
		getline(cin, line);

		ofstream ofile("file.txt");

		if (isAvailableSAVE("file.txt")) {
			ofile << line;
			ofile.close();
		}
		else {
			cerr << "Unable to open file" << endl;
		}
	}

	void readFromFile() {
		ifstream ifile("file.txt");

		if (isAvailableREAD("file.txt")) {
			string line;
			while (getline(ifile, line)) {
				cout << line << endl;
			}
		}
		else {
			cerr << "Unable to open file" << endl;
		}
	}

	




}

void main() {


	Utilities::saveToFile();

	Utilities::readFromFile();

}