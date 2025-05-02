#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	//data members
	static int system_type;
	string year;
	string month;
	string day;

	// Utitility Functions
	//for validation 
	bool isValidDay(string day) const;
	bool isValidMonth(string month) const;
	bool isValidYear(string year) const;
public:
	//Constructors
	Date();
	Date(string year, string month, string day);
	Date(const Date& x);
	~Date();
	//setters
	void setYear(string year);
	void setMonth(string month);
	void setDay(string day);
	static void setSystemType(const int system_type);
	//getters
	string getYear() const;
	string getMonth() const;
	string getDay() const;
	//for print date information
	void printDateInfo() const;


};
#endif