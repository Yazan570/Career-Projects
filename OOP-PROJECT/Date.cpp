#include "Date.h"
#include "interfacefunctions.h"
#include "validationfunctions.h"

#include <iostream>
#include <string>

using namespace std;

int Date::system_type = 1;

bool Date::isValidDay(string day) const
{
    // Checks if string contains a non-number.
    // Prevents a negative number from being entered implicitly
    for (int i = 0; i < day.length(); i++)
    {
        if (!isNumber(day[i]))
        {
            return false;
        }
    }

    // Prevents input to have more than tens and ones.
    if (day.length() > 2)
    {
        return false;
    }

    // Makes sure that if the day has two numbers, the tens is not 0.
    if (day.length() == 2 && day[0] == '0')
    {
        return false;
    }

    // Prevents zero from being accepted as input.
    if (day.length() == 1 && day[0] == '0')
    {
        return false;
    }

    // Prevents tens from being larger than 3.
    if (day.length() == 2 && day[0] > '3')
    {
        return false;
    }

    // Prevents days larger than 31.
    if (day.length() == 2 && day[0] == '3' && day[1] > '1')
    {
        return false;
    }

    // Apr, Jun, Sep, Nov have 30 days.
    if (month == "4" || month == "6" || month == "9" || month == "11")
    {
        // Prevents days larger than 30.
        if (day.length() == 2 && day[0] == '3' && day[1] > '0')
        {
            return false;
        }
    }

    // Leap year checking.
    else if (month == "2")
    {
        // Prevents tens from being larger than 2.
        if (day.length() == 2 && day[0] > '2')
        {
            return false;
        }
        // If it is not a leap year:
        if (!(stoi(year) % 4 == 0 && stoi(year) % 100 != 0 || (stoi(year) % 400 == 0)))
        {    //2023 feb have 28 days, 2024 feb have 29 days
            if (day.length() == 2 && day[1] > '8')
            {
                return false;
            }
        }

        // The rest of the months are 31 by process of elimination.
    }

    return true;
}

bool Date::isValidMonth(string month) const
{
    // Prevents non-numbers and negative numbers.
    for (int i = 0; i < month.length(); i++)
    {
        if (!isNumber(month[i]))
        {
            return false;
        }
    }

    // Makes sure that the month is not larger than 2 place values
    if (month.length() > 2)
    {
        return false;
    }

    // Makes sure that if the month has two numbers, the tens is not 0.
    if (month.length() == 2 && month[0] == '0')
    {
        return false;
    }

    // Prevents zero from being accepted as input.
    if (month.length() == 1 && month[0] == '0')
    {
        return false;
    }

    // Prevents months from being larger than 12.
    if (month.length() == 2 && (month[0] > '1' || month[1] > '2'))
    {
        return false;
    }

    return true;


}

bool Date::isValidYear(string year) const
{
    for (int i = 0; i < year.length(); i++)
    {
        if (!isNumber(year[i]))
        {
            return false;
        }
    }

    if (stoi(year) < 1970 || stoi(year) > 2050)
    {
        return false;
    }

    return true;
}

//Constructors
Date::Date()
{
    this->year = "2023";
    this->month = "1";
    this->day = "1";
}

Date::Date(string year, string month, string day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date(const Date& x)
{
    this->year = x.year;
    this->month = x.month;
    this->day = x.day;
}

Date::~Date()
{

}

//setters
void Date::setYear(string year)
{
    //for validation
    for (int i = 0; i < 10; i++)
    {
        if (isValidYear(year))
        {
            continue;
        }

        i = -1;  //if its not valid 
        clearScreen(system_type);
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Invalid entry, please try again." << endl;
        cout << "Please enter a year between 1970 & 2050: ";
        cin >> year;
    }
    this->year = year;
}

//for validation
void Date::setMonth(string month) {
    for (int i = 0; i < month.length(); i++)
    {
        if (isValidMonth(month))
        {
            continue;
        }

        i = -1;   //if its not valid 
        clearScreen(system_type);
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Invalid entry, please try again." << endl;
        cout << "Please enter the month: ";
        cin >> month;
    }
    this->month = month;
}

//for validation
void Date::setDay(string day)
{
    for (int i = 0; i < day.length(); i++)
    {
        if (isValidDay(day))
        {
            continue;  //for bool validation function
        }

        i = -1;    //if its not valid 
        clearScreen(system_type);
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Invalid entry, please try again." << endl;
        cout << "Please enter the day: ";
        cin >> day;
    }
    this->day = day;
}

void Date::setSystemType(const int system_type)
{
    Date::system_type = system_type;
}

//getters
string Date::getYear() const
{
    return year;
}

string Date::getMonth() const
{
    return month;
}

string Date::getDay() const
{
    return day;
}

//for print date information
void Date::printDateInfo() const
{
    cout << day << "/" << month << "/" << year << endl;
}
