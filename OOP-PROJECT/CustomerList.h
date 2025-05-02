#ifndef CUSTOMER_LIST_H_
#define CUSTOMER_LIST_H_

#include "Customer.h"

#include <iostream>
#include <string>

using namespace std;

class CustomerList
{
private:
    Customer* customer_list;
    int size;
    int next_available_slot;
    int latest_active_index;
    static int system_type;

    // Utitlity Functions
    void updateLastestActiveIndex();
    bool updateNextAvailableSlot();

    // Internal process functions.
    int getNumberOfAvailableSlots() const;
    bool hasAvailableSlot() const;

public:
    CustomerList();

    static bool setSystemType(const int& system_type);

    int getNumberOfActiveSlots();

    void addCustomer();

    void displayActive();

    void addSlot(const int added_slot);

    ~CustomerList();

};

#endif // !CUSTOMER_LIST_H_