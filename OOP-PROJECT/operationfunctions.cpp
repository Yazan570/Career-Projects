#include "Customer.h"
#include "Medication.h"
#include "interfacefunctions.h"
#include "validationfunctions.h"
#include "operationfunctions.h"
#include "Pharmacy.h"

#include <iostream>
#include <string>

using namespace std;


void medicineOperation(const int system_type, Pharmacy& pharmacy, const int choice)
{
    switch (choice)
    {
        // Add Medicine
    case 1:
    { 
        clearScreen(system_type);
        pharmacy.medicine_list.addMedicine();
        continueDelay();
        break;
    }
    case 2:
    {
        // Active Slots
        clearScreen(system_type);
        pharmacy.medicine_list.displayActive();
        continueDelay();
        break;
    }
    case 3:
    {
        //  Display available medication.
        // Check if there is no medication.
        clearScreen(system_type);
        pharmacy.medicine_list.displayAvailable();
        continueDelay();
        break;
    }
    case 4:
    {
        // Add stock.
        clearScreen(system_type);
        cout << "Feature coming soon if Allah wills." << endl;
        continueDelay();
        break;
    }
    case 5:
    {
        // Display quantities sold.
        clearScreen(system_type);
        cout << "Feature coming soon if Allah wills." << endl;
        continueDelay();
        break;
    }
    case 6:
    {
        // Display total sales.
        clearScreen(system_type);
        cout << "Total Sales: " << pharmacy.getSales() << endl;
        continueDelay();
        break;
    }

    case 7:
    {
        // Display total profit.
        clearScreen(system_type);
        cout << "Total Profit: " << pharmacy.getProfit() << endl;
        continueDelay();
        break;
    }
    case 8:
    {
        // Delete medicine.
        clearScreen(system_type);

        pharmacy.medicine_list.removeMedicine();
        continueDelay();
        break;
    }
    case 9:
    {
        // Return.
        break;
    }
    }
}

void customerOperation(const int system_type, Pharmacy& pharmacy, const int choice) {
    switch (choice)
    {
    case 1:
    {
        // Add customer.
        clearScreen(system_type);
        pharmacy.customer_list.addCustomer();
        continueDelay();
        break;
    }

    case 2:
    {
        // Edit customer details.
        clearScreen(system_type);
        cout << "Feature coming soon if Allah wills." << endl;
        continueDelay();
        break;
    }
    case 3:
    {
        // List out customer details.
        clearScreen(system_type);
        pharmacy.customer_list.displayActive();
        continueDelay();
        break;
    }
    case 4:
    {
        // Return.
        break;
    }
    default:
    {
        break;
    }
    }
}

void purchaseOperation(const int system_type, Pharmacy& pharmacy, const int choice) {
    switch (choice)
    {
    case 1:
    {
        clearScreen(system_type);
        pharmacy.recordPurchase();
        continueDelay();
    }

    case 2:
    {
        //Return 
        break;
    }

    default:
    {
        break;
    }
    }
}
