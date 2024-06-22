#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
	string accNum;
	string ownerName;
	double balance;
	vector<BankAccount> accounts;
public:
	BankAccount(): accNum(""), ownerName(""), balance(0) {}
	BankAccount(const string& aN, const string& oN): accNum(aN), ownerName(oN), balance(0.0){}

	void getBalance(vector<BankAccount> accounts) {
		string number;
		cout << "Enter account number: ";
		cin >> number;

		for (auto& a : accounts) {
			if (number == a.accNum) {
				cout << "Balance: " << a.balance << endl;
			}
		}
	}



	string getAccNum() { return accNum; }

	void putMoneyOn(vector<BankAccount>& accounts) {
		double amount;
		string number;
		cout << "Enter account number: ";
		cin >> number;
		cout << "Enter amount: ";
		cin >> amount;

		for (auto& a : accounts) {
			if (number == a.accNum) {
				a.balance += amount;
			}
			else {
				cout << "Invalid account number!" << endl;
			}
		}
	}


	void withdrowMoney(vector<BankAccount>& accounts) {
		double amount;
		string number;
		cout << "Enter account number: ";
		cin >> number;
		cout << "Enter amount: ";
		cin >> amount;

		for (auto& a : accounts) {
			if (number == a.accNum) {
				a.balance -= amount;
			}
			else {
				cout << "Invalid account number!" << endl;
			}
		}
	}


};

vector <BankAccount> addAccount(vector<BankAccount>& accounts) {
	string n, o;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter name and surname: ";
	cin.ignore();
	getline(cin, o);
	accounts.push_back(BankAccount(n, o));
	return accounts;
}


void operations() {
	cout << "1 - add acount" << endl;
	cout << "2 - put money on" << endl;
	cout << "3 - withdraw" << endl;
	cout << "4 - check balance" << endl;
	cout << "5 - exit" << endl;
	cout << "Operartion >> ";
}


void main() {
	vector<BankAccount> accounts;
	BankAccount acc;
	int op;

	do {
		operations();
		cin >> op;
		switch (op) {
		case 1:
			addAccount(accounts);
			break;
		case 2:
			acc.putMoneyOn(accounts);
			break;
		case 3:
			acc.withdrowMoney(accounts);
			break;
		case 4:
			acc.getBalance(accounts);
			break;
		case 5:
			break;
		default:
			cout << "Incorrect operation!" << endl;
			operations();
			cin >> op;
		}

	} while (op != 5);
	
}