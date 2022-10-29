//bank.cpp

#include "bank.h"
#include <cstring>
#include <iostream>

using namespace std;

bank::bank(){
    accountNumber = 9999;
    balance = 0;
    owner = nullptr;
}

bank::bank(long long int a, double b){
    accountNumber = a;
    balance = b;
    owner = nullptr;
}

bank::bank(long long int a, double b, const char * s) {
    accountNumber = a;
    balance = b;
    owner = nullptr;
    setOwner(s);
}

void bank::withdraw(double w) {
	//If the balance is less than the amount requested for withdrawl
	//Display error message
	if (balance < w)
		cout << "Insufficient balance!" << endl;
	//Else display the new balance after withdrawl
	else {
		balance -= w;
		cout << "New balance is: $" << balance << endl;
	}
}

void bank::deposit(double d) {
	balance += d;
	//Display new balance after deposit
	cout << "New balance is: $" << balance << endl;
}

void accountInfo(bank *b) {
	cout << "Account #" << b->accountNumber << endl;
	cout << "Account Balance: $" << b->balance << endl;
	//Check to see if the object has an instance of owner name
	if (b->owner == nullptr)
		cout << "Unlisted owner!" << endl;
	else
		cout << "Account Owner: " << b->getOwner() << endl;
}