#include "interfacefunctions.h"
#include "validationfunctions.h"
#include "Pharmacy.h"
#include "Date.h"
#include "Address.h"
#include "MedicineList.h"

#include <iostream>


// For sequential id generation.
int Pharmacy::id_counter = 0;

// For formatting the menu purposes.
int Pharmacy::system_type = 1;

// Default Constructor
Pharmacy::Pharmacy() : ID(id_counter++)
{
    this->active = false;
    this->name = "N/A";
    this->sales = 0;
    this->profit = 0;

}

void Pharmacy::setSystemType(const int& system_type)
{
    Pharmacy::system_type = system_type;
}

string Pharmacy::getName()
{

    return name;
}

bool Pharmacy::setName(string name)
{
    if (name == "")
        return false;

    this->name = name;
    return true;
}

double Pharmacy::getSales()
{
    return sales;
}

double Pharmacy::getProfit()
{
    return profit;
}

void Pharmacy::recordPurchase()
{
    medicine_list.purchaseMedicine(sales, profit);
}

bool Pharmacy::setSales(string sales)
{
    if (isValidDouble(sales))
    {
        this->sales = stod(sales);
        return true;
    }

    return false;
}

bool Pharmacy::setProfit(string profit)
{
    if (isValidDouble(profit))
    {
        this->profit = stod(profit);
        return true;
    }

    return false;
}

bool Pharmacy::hasMoreMedicineThan(Pharmacy& pharmacy)
{
    if (medicine_list.getNumberOfActiveSlots() > pharmacy.medicine_list.getNumberOfActiveSlots())
    {
        return true;
    }
    return false;
}

bool Pharmacy::hasMoreCustomersThan(Pharmacy& pharmacy)
{
    if (this->customer_list.getNumberOfActiveSlots() > pharmacy.customer_list.getNumberOfActiveSlots())
    {
        return true;
    }
    return false;
}

bool Pharmacy::hasMoreProfitThan(Pharmacy& pharmacy)
{
    if (this->getProfit() > pharmacy.getProfit())
    {
        return true;
    }

    return false;
}

bool Pharmacy::hasMoreTotalSalesThan(Pharmacy& pharmacy)
{
    if (this->getSales() > pharmacy.getSales())
    {
        return true;
    }

    return false;
}
bool Pharmacy::activate() {
    this->active = true;
    return true;
}
bool Pharmacy::isActive() {
    return active;
}
void Pharmacy::deactivate() {
    this->active = false;
    this->name = "N/A";
    this->sales = 0.0;
    this->profit = 0.0;
}