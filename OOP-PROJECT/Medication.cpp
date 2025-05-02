#include "Medication.h"
#include "Date.h"
#include "validationfunctions.h"
#include "interfacefunctions.h"

#include <iostream>
#include <string>

using namespace std;

int Medication::id_counter = 1;
int Medication::system_type = 1;

Medication::Medication()
    : ID(id_counter++)
    , expiry_date(Date())
    , active(false)
{
    this->name = "N/A";
    this->description = "N/A";
    this->retail_price = 0;
    this->wholesale_price = 0;
    this->total_profit = 0;
    this->total_sales = 0;
    this->quantity_in_stock = 0;
    this->barcode = "N/A";
}

void Medication::setSystemType(const int& system_type)
{
    Medication::system_type = system_type;
}

long Medication::getID() const
{
    return ID;
}

bool Medication::setName(string name)
{
    if (name == "")
    {
        return false;
    }

    this->name = name;
    return true;
}

string Medication::getName() const
{
    return name;
}

//Description setter:
bool Medication::setDescription(string description)
{
    if (description == "")
    {
        return false;
    }

    this->description = description;
    return true;
}

//Description getter:
string Medication::getDescription() const
{
    return description;
}

// Retail Price Setter & Getter
bool Medication::setRetailPrice(string retail_price)
{
    string choice;
    while (!isValidDouble(retail_price))
    {
        clearScreen(system_type);
        cout << "Invalid input." << endl;
        cout << "press '1' to enter the retail price again or '0' to return: ";
        clearStream();
        cin >> choice;
        if (choice.length() > 1 || (choice[0] != '1' && choice[0] != '0'))
        {
            continue;
        }

        if (choice[0] == '1')
        {
            cout << "Enter the retail price: ";
            clearStream();
            cin >> retail_price;
        }

        else
        {
            return false;
        }
    }

    this->retail_price = stod(retail_price);
    return true;
}

double Medication::getRetailPrice() const
{
    return retail_price;
}

// Production Price Setter & Getter
bool Medication::setWholesalePrice(string wholesale_price)
{
    string choice;
    while (!isValidDouble(wholesale_price))
    {
        clearScreen(system_type);
        cout << "Invalid input." << endl;
        cout << "press '1' to enter the wholesale price again or '0' to return: ";
        clearStream();
        cin >> choice;
        if (choice.length() > 1 || (choice[0] != '1' && choice[0] != '0'))
        {
            continue;
        }

        if (choice[0] == '1')
        {
            cout << "Enter the wholesale price: ";
            clearStream();
            cin >> wholesale_price;
        }

        else
        {
            return false;
        }
    }
    this->wholesale_price = stod(wholesale_price);
    return true;
}

double Medication::getWholesalePrice() const
{
    return wholesale_price;
}

//Quantity setter:
bool Medication::setQuantityInStock(string quantity_in_stock)
{
    string choice;
    for (int i = 0; i < quantity_in_stock.length(); i++) {
        if (isNumber(quantity_in_stock[i]))
        {
            continue;
        }
        clearScreen(system_type);
        cout << "Invalid input." << endl;
        cout << "Press '1' to enter the quantity price again or '0' to return: ";
        clearStream();
        cin >> choice;
        if (choice.length() > 1 || (choice[0] != '1' && choice[0] != '0'))
        {
            i--;
            continue;
        }

        if (choice[0] == '1')
        {
            clearScreen(system_type);
            cout << "Enter the quantity: ";
            clearStream();
            cin >> quantity_in_stock;
        }

        else
        {
            return false;
        }

    }

    this->quantity_in_stock = stoi(quantity_in_stock);
    return true;
}

//Quantity getter:
int Medication::getQuantityInStock() const
{
    return quantity_in_stock;
}

bool Medication::setExpiryDate(const Date& expiry_date)
{
    this->expiry_date.setDay(expiry_date.getDay());
    this->expiry_date.setMonth(expiry_date.getMonth());
    this->expiry_date.setYear(expiry_date.getYear());
    return true;
}

Date& Medication::getExpiryDate()
{
    return expiry_date;
}

//Barcode setter:
bool Medication::setBarcode(string barcode)
{
    //Setter for the barcode of the medicine.
    string choice; //to store user's choice.
    while (barcode.length() != 12) //12 is the standard barcode length.
    {
        clearScreen(system_type);
        cout << "Invalid barcode." << endl;
        cout << "press '1' to enter the barcode again or '0' to return: ";
        clearStream();
        cin >> choice;
        if (choice.length() > 1 || (choice[0] != '1' && choice[0] != '0'))
        {
            continue;
        }

        if (choice[0] == '1')
        {
            cout << "Enter the barcode [Exactly 12 characters]: ";
            clearStream();
            cin >> barcode;
        }

        else
        {
            return false;
        }
    }

    this->barcode = barcode;
    return true;
}

//Barcode getter:
string Medication::getBarcode() const
{
    return barcode;
}


void Medication::printInfo() const
{
    cout << "Medicine ID: " << getID() << endl;
    cout << "Medicine Name: " << getName() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Retail Price (JOD): " << getRetailPrice() << " JOD" << endl;
    cout << "Wholesale Price (JOD): " << getWholesalePrice() << " JOD" << endl;
    cout << "Quantity: " << getQuantityInStock() << endl;
    cout << "Expiry Date: ";
    expiry_date.printDateInfo();
    cout << endl;
    cout << "Barcode: " << getBarcode() << endl;
}

void Medication::purchaseMedicine(int quantity_bought)
{
    quantity_in_stock -= quantity_bought;
    total_sales += retail_price * quantity_bought;
    total_profit += (retail_price - wholesale_price) * quantity_bought;
}

double Medication::getTotalProfit() const
{
    return total_profit;
}

void Medication::setTotalProfit(double total_profit)
{
    this->total_profit = total_profit;
}

double Medication::getTotalSales() const
{
    return total_sales;
}

void Medication::setTotalSales(double total_sales)
{
    this->total_sales = total_sales;
}

bool Medication::isActive() const
{
    return active;
}

void Medication::activate()
{
    this->active = true;
}

void Medication::deactivate()
{
    this->name = "N/A";
    this->description = "N/A";
    this->retail_price = 0;
    this->wholesale_price = 0;
    this->total_profit = 0;
    this->total_sales = 0;
    this->quantity_in_stock = 0;
    this->barcode = "N/A";
    this->active = false;
}