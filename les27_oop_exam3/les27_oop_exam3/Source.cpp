#include <iostream>

using namespace std;

// константні функції не змінюють об'єкт 

class Date {
	int day;
	int month;
	int year;
public:
	explicit Date(int d, int m, int y): day(d), month(m), year(y){}

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }



};


void main() {

	Date d1(9, 6, 1999);
	cout << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << endl;


}