#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

using namespace std;

class Address
{
private:
	//data members 
	static int system_type;
	string email;
	string city;
	string street_name;
	string phone;

	// Utility Functions
	//for validation
	bool isValidEmail(string email);
	bool isValidCity(string city);
	bool isValidPhone(string phone);
public:
	//Constructors
	Address();
	Address(string email, string city, string streetName, string phone);
	Address(const Address& x);
	~Address();

	//setters
	void setEmail(string email);
	void setCity(string city);
	void setStreet(string street_name);
	void setPhone(string phone);
	static void setSystemType(const int systemType);

	//getters
	string getEmail() const;
	string getCity() const;
	string getStreet() const;
	string getPhone() const;

	//for print address information
	void printAddressInfo() const;


};
#endif