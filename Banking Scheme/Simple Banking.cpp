/*
This program implements a simplified functionality of a banking scheme.
*/
#include <iostream>
#include "bank.h"
#include "bank.cpp"
#include <iomanip>

#define SIZE 4
using namespace std;

void displayAccountInfo(bank *obj) {
      //Display the data from the Bank object using accessors
    cout << endl << "Account " << "# " << obj->getAccountNumber() << endl;
    cout << "Account Balance: $" << obj->getBalance() << endl;
    //Check to see if the object has an instance of owner name
    if (obj->getOwner() == nullptr)
        cout << "Unlisted owner!" << endl;
    else
        cout << "Account Owner: " << obj->getOwner() << endl;
    cout << endl;
}

int main() {

    bank* account1 = nullptr;
    account1 = new bank(); // call bank empty constructor
    account1->withdraw(500);

    displayAccountInfo(account1); // call display function
    delete account1;

    account1 = new bank(1111, 1000, "John Smith");
    
    account1->withdraw(600);
    account1->withdraw(300);
    account1->deposit(400);

    displayAccountInfo(account1);
    accountInfo(account1);
    delete account1;

    bank portfolio[SIZE] = { {1000,600.0}, {1001, 900.0, "Homer Simpson"} };

    cout << endl;
    cout << left << setw(1) << " | "
         << setw(12) << "Acc Number" << " | "
         << setw(10) << "Balance" << " | "
         << setw(30) << "Owner" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << setw(1) << " | "
             << setw(12) << portfolio[i].getAccountNumber() << " | "
             << setw(10) << portfolio[i].getBalance() << " | ";
             if (portfolio[i].getOwner() != nullptr)
             cout << setw(30) << portfolio[i].getOwner() << endl;
             else cout << setw(30) << "n/a" << endl;
    }
        
    return 0;
}