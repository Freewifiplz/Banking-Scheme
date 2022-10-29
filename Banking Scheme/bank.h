//bank.h
#ifndef BANK_H
#define BANK_H

class bank{
    long long int accountNumber;
    double balance;
    char * owner;

public:
    // Constructors
    bank();
    bank(long long int, double);
    bank(long long int, double, const char*);
    void withdraw(double);
    void deposit(double);
    // Accessor member funtions
    long long int getAccountNumber() const { return accountNumber;}
    double getBalance() const { return balance;}
    char * getOwner() const { return owner;}
    // Mutator member functions
    void setAccountNumber(long long int new_num) {
        accountNumber = new_num;
    }
    void setBalance(double new_bal) {
        balance = new_bal;
    }
    void setOwner(const char *new_owner) {
        //First check to see if the original char is empty
		//If so, delete the values inside of it
		if (owner != nullptr) {
			delete[] owner;
		}
		int i = 0;
		//Dynamically allocate a new owner char
		//Set it equal to the size of the second char
		//function until the NULL character is found
		while (new_owner[i++] != '\0') {
			owner = new char[i + 1];
			i++;
		}
		int l = 0;
		//Set each value of the new char to the old char
		while (new_owner[l] != '\0') {
			owner[l] = new_owner[l];
			l++;
		}
		//Add a NULL character in the end
		owner[l] = '\0';
    }

    ~bank() { // Destructor
        if (owner != nullptr)
			delete[] owner;
    };

    friend void accountInfo(bank*); // friend function called in main.cpp

};

#endif