#include "CustomerList.h"
#include "interfacefunctions.h"
#include "validationfunctions.h"

#include <iostream>
#include <string>

using namespace std;

int CustomerList::system_type = 1;

bool CustomerList::setSystemType(const int& system_type)
{
    if (system_type != 1 && system_type != 2)
    {
        return false;
    }

    CustomerList::system_type = system_type;
    return true;
}

CustomerList::CustomerList()
{
    this->customer_list = new Customer[1];
    this->latest_active_index = -1;
    this->next_available_slot = 0;
    this->size = 1;
}

void CustomerList::updateLastestActiveIndex()
{
    for (int i = 0; i < this->size; i++)
    {
        if (customer_list[i].isActive())
        {
            latest_active_index = i;
        }
    }
}

bool CustomerList::updateNextAvailableSlot()
{
    for (int i = 0; i < this->size; i++)
    {
        // Looking for next available slot.
        if (!customer_list[i].isActive())
        {
            next_available_slot = i;
            break;
        }
    }

    // Checks if all slots are active.
    if (customer_list[next_available_slot].isActive())
    {
        return false;
    }

    return true;
}

int CustomerList::getNumberOfAvailableSlots() const
{
    int available_slot_counter = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (!customer_list[i].isActive())
        {
            available_slot_counter++;
        }
    }

    return available_slot_counter;
}

bool CustomerList::hasAvailableSlot() const
{
    for (int i = 0; i < this->size; i++)
    {
        if (!customer_list[i].isActive())
        {
            return true;
        }
    }

    return false;
}

int CustomerList::getNumberOfActiveSlots()
{
    updateLastestActiveIndex();
    int active_slot_counter = 0;
    for (int i = 0; i <= latest_active_index; i++)
    {
        if (customer_list[i].isActive())
        {
            active_slot_counter++;
        }
    }

    return active_slot_counter;
}

void CustomerList::addCustomer()
{
    // Making sure that there is an available slot.
    if (!(this->updateNextAvailableSlot()))
    {
        addSlot(1);
    }
    this->updateNextAvailableSlot();

    // Lists the number of available customer slots.
    cout << "Currently available customer slots: " << getNumberOfAvailableSlots() << endl;

    string name;
    cout << "Please enter the Customer name: ";
    cin >> name;
    customer_list[next_available_slot].setName(name);

    clearScreen(system_type);
    Address address;
    string email;
    clearStream();
    cout << "Please enter email: ";
    cin >> email;
    address.setEmail(email);
    clearScreen(system_type);

    string city;
    clearStream();
    cout << "Please enter city: ";
    cin >> city;
    address.setCity(city);
    clearScreen(system_type);

    string street;
    clearStream();
    cout << "Please enter street: ";
    cin >> street;
    address.setStreet(street);
    clearScreen(system_type);

    string phone;
    clearStream();
    cout << "Please enter phone: ";
    cin >> phone;
    address.setPhone(phone);
    clearScreen(system_type);

    customer_list[next_available_slot].setAddress(address);

    customer_list[next_available_slot].activate();
    return;
}

void CustomerList::displayActive()
{
    if (this->getNumberOfActiveSlots() == 0)
    {
        cout << "There are no customers in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex();
    for (int i = 0; i <= latest_active_index; i++)
    {
        if (!customer_list[i].isActive())
        {
            continue;
        }

        customer_list[i].printInfo();

        if (i != latest_active_index)
        {
            cout << "---------------------" << endl;
        }
    }
}

void CustomerList::addSlot(const int added_slots)
{
    Customer* temp = new Customer[added_slots + size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = customer_list[i];
    }
    delete[] customer_list;
    customer_list = temp;
    size += added_slots;
}

CustomerList::~CustomerList()
{
    delete[] customer_list;
}