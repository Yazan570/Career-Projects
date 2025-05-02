#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Address.h"

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
	//data memebers
	string name;		//name of the customer
	long ID;		//ID of the customer 
	static int id_counter;		//static int so we can increase the ID everytime we get a customer
	Address address; //customer address
	static int system_type; // for clear screen

	bool active; // For activity purposes.
public:
	Customer(); //default constructer
	Customer(string name, Address passed_address); //parameterized constructer
	//set values
	void setName(string name);
	void setPhoneNumber(string phone);
	void setAddress(const Address& adress);
	static void setSystemType(const int system_type);
	//get values
	string getName() const;
	string getPhoneNumber() const;
	Address getAddress() const;
	int getID() const;

	// Activity functions.
	bool isActive() const;
	void activate();
	void deactivate();

	void printInfo() const;		//print customer information
};
#endif
