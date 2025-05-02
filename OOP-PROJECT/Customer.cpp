#include "Customer.h"
#include "Address.h"
#include "interfacefunctions.h"

#include <iostream>
#include <string>

using namespace std;

int Customer::id_counter = 1;   //static int so we can increase the ID everytime we get a customer
int Customer::system_type = 1;

//Constructors 
Customer::Customer()
	: ID(id_counter++)
	, address(Address())
{
	this->name = "N/A";
	active = false;
}

Customer::Customer(string name, Address passed_address)
	: ID(id_counter++)
	, address(passed_address)
{
	setName(name);
	active = true;
}

//setters 
void Customer::setName(string name)
{
	this->name = name;
}


void Customer::setAddress(const Address& passed_address)
{
	address.setEmail(passed_address.getEmail());
	address.setCity(passed_address.getCity());
	address.setStreet(passed_address.getStreet());
	address.setPhone(passed_address.getPhone());
}

void Customer::setSystemType(const int system_type)
{
	Customer::system_type = system_type;
}

//getters 
string Customer::getName() const
{
	return name;
}

Address Customer::getAddress() const
{
	return address;
}

int Customer::getID() const
{
	return ID;
}

bool Customer::isActive() const
{
	return active;
}

void Customer::activate()
{
	this->active = true;
}

void Customer::deactivate()
{
	this->name = "N/A";
	this->address = Address();
	this->active = false;
}

//print 
void Customer::printInfo() const
{
	cout << "Customer name: " << name << endl;
	cout << "Customer ID: " << ID << endl;
	address.printAddressInfo();
}

