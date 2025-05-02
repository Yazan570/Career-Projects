#include "interfacefunctions.h"
#include "validationfunctions.h"
#include "Address.h"

#include <iostream>
#include <string>


using namespace std;
int Address::system_type = 1;

//Constructors
Address::Address()
{
	this->email = "N/A";
	this->city = "N/A";
	this->street_name = "N/A";
	this->phone = "N/A";
}
Address::Address(string email, string city, string streetName, string phone)
{
	setEmail(email);
	setCity(city);
	setStreet(streetName);
	setPhone(phone);
}

Address::Address(const Address& copy)
{
	this->email = copy.getEmail();
	this->city = copy.getCity();
	this->street_name = copy.getStreet();
	this->phone = copy.getPhone();
}

Address::~Address()
{

}


//setters
void Address::setEmail(string email)
{
	for (int i = 0; i < email.length(); i++)
	{
		if (isValidEmail(email))
		{
			break;;
		}

		i = -1;  //if its not valid
		clearScreen(system_type);
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Invalid entry, please try again." << endl;
		cout << "Please enter the email: ";
		cin >> email;
	}

	this->email = email;
}
void Address::setCity(string city)
{
	for (int i = 0; i < city.length(); i++)
	{
		if (isValidCity(city))
		{
			break;
		}

		i = -1;  //if its not valid 
		clearScreen(system_type);
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Invalid entry, please try again." << endl;
		cout << "Please enter the city: ";
		cin >> city;
	}

	this->city = city;
}

void Address::setStreet(string street_name)
{
	this->street_name = street_name;
}

void Address::setPhone(string phone)
{
	//for validtion if its not 10 digit 
	for (int i = 0; i < phone.length(); i++)
	{
		if (isValidPhone(phone))
		{
			break;
		}

		i = -1;  //if its not valid 
		clearScreen(system_type);
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Invalid entry, please try again." << endl;
		cout << "Please enter the phone: ";
		cin >> phone;
	}

	this->phone = phone;
}

void Address::setSystemType(const int system_type)
{
	Address::system_type = system_type;
}


//getters
string Address::getEmail() const
{
	return email;
}

string Address::getCity() const
{
	return city;
}

string Address::getStreet() const
{
	return street_name;
}

string Address::getPhone() const
{
	return phone;
}

//for print address informaion
void Address::printAddressInfo() const
{
	cout << "Email: " << email << endl;
	cout << "City: " << city << endl;
	cout << "Street name: " << street_name << endl;
	cout << "Phone: " << phone << endl;
}

bool Address::isValidEmail(string email)
{
	bool flag = false;

	if (email[0] == '@' || email[email.length() - 1] == '@')
	{
		return false;
	}

	if (email[0] == '.' || email[email.length() - 1] == '.')
	{
		return false;
	}

	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == '@')
		{
			flag = true;
		}

		if (email[i] == '!' || email[i] == '#' || email[i] == '$' || email[i] == '%' || email[i] == '^' ||
			email[i] == '&' || email[i] == '*' || email[i] == '(' || email[i] == ')' || email[i] == '=' ||
			email[i] == '+' || email[i] == '[' || email[i] == ']' || email[i] == '{' || email[i] == '}' ||
			email[i] == ';' || email[i] == ':' || email[i] == '"' || email[i] == '\'' || email[i] == '<' ||
			email[i] == '>' || email[i] == ',' || email[i] == '/' || email[i] == '?' || email[i] == '\\' ||
			email[i] == ' ')
		{
			return false;
		}
	}

	return flag;
}

bool Address::isValidCity(string city)
{
	for (int i = 0; i < city.length(); i++)
	{
		if (isNumber(city[i]))
		{
			return false;
		}
	}

	return true;
}
bool Address::isValidPhone(string phone)
{
	if (phone.length() != 10)
	{
		return false;
	}

	// Checks if it is a valid jordanian number in local form. (Internation form not supported).
	if (phone[0] != '0' && phone[1] != '7')
	{
		return false;
	}

	if (!(phone[2] >= '7' && phone[2] <= '9'))
	{
		return false;
	}

	for (int i = 0; i < phone.length(); i++)
	{
		if (!isNumber(phone[i]))
		{
			return false;
		}
	}

	return true;
}