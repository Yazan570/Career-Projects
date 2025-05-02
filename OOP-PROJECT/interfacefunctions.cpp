#include "interfacefunctions.h"

#include <iostream>
#include <string>

using namespace std;



// Number of the of operations the program offers per pharmacy.
const int NUMBER_OF_CATEGORIES = 4;

// Number of operations for Medicine category.
const int NUMBER_OF_MEDICINE_OPERATIONS = 9;

// Number of operations for Customer category.
const int NUMBER_OF_CUSTOMER_OPERATIONS = 4;

// Number of operations for Purchase category.
const int NUMBER_OF_PURCHASE_OPERATIONS = 2;

// Number of operations on the pharmacy level.
const int NUMBER_OF_PHARMACY_OPERATIONS = 5;


void clearScreen(const int system_type)
{
    // Clearing the screen.
    if (system_type == 1)
    {
        system("cls");
    }
    // For MacOS, Unix, Ed, onlineGDB and Repl.it, this is supposed to work.
    else
    {
        system("clear");
    }
}

// Functional Decomposition.
void listOptions(const int option)
{
    switch (option)
    {
        // Display category choices
    case 1:
    {
        cout << "1. Medication." << endl;
        cout << "2. Customer." << endl;
        cout << "3. Purchases." << endl;
        cout << "4. Exit." << endl;

        break;
    }
    // Display medicine category operations.
    case 2:
    {
        cout << "1. Add medication." << endl;
        cout << "2. Display all medication." << endl;
        cout << "3. Display available medication." << endl;
        cout << "4. Add stock." << endl;
        cout << "5. Display quantity sold." << endl;
        cout << "6. Display total sales." << endl;
        cout << "7. Display total profit." << endl;
        cout << "8. Delete medicine." << endl;
        cout << "9. Return." << endl;
        break;
    }
    // Display customer category operations.
    case 3:
    {
        cout << "1. Add customer." << endl;
        cout << "2. Edit customer details." << endl;
        cout << "3. List out customer details." << endl;
        cout << "4. Return." << endl;
        break;
    }
    // Display purchase category operations.
    case 4:
    {
        cout << "1. Record purchase." << endl;
        cout << "2. Return." << endl;
        break;
    }
    case 5:
    {
        cout << "1. Add a new pharmacy." << endl;
        cout << "2. Access a pharmacy" << endl;
        cout << "3. Remove a pharmacy" << endl;
        cout << "4. Add a new branch" << endl;
        cout << "5. Exit the system" << endl;
        break;
    }
    default:
    {
        break;
    }
    }
}

void getOption(const int mode, int& input, const int system_type)
{
    string user_input;
    int counter;
    switch (mode)
    {
        // pharmacy operation choice input.
    case 1:
    {
        counter = 1;
        cout << "Option: ";
        cin >> user_input;
        // This is caps the number of allowed operations from 1-9, this can be extended in the future.
        while (user_input.length() > 1 || !(user_input[0] >= '1' && user_input[0] <= ('0' + NUMBER_OF_CATEGORIES)))
        {
            clearScreen(system_type);
            cout << "Please select the category you want." << endl;
            listOptions(1);
            cout << "Invalid Option. " << "(" << counter++ << ")" << endl;
            cout << "Option: ";
            cin >> user_input;
        }
        input = user_input[0] % '0';

        break;
    }

    // Medicine operation choice input.
    case 2:
    {
        counter = 1;
        cout << "Option: ";
        cin >> user_input;
        // This is caps the number of allowed operations from 1-9, this can be extended in the future.
        while (user_input.length() > 1 || !(user_input[0] >= '1' && user_input[0] <= ('0' + NUMBER_OF_MEDICINE_OPERATIONS)))
        {
            clearScreen(system_type);
            cout << "Please select the operation you want." << endl;
            listOptions(2);
            cout << "Invalid Option. " << "(" << counter++ << ")" << endl;
            cout << "Option: ";
            cin >> user_input;
        }
        input = user_input[0] % '0';
        break;
    }

    // Customer operation choice input.
    case 3:
    {
        counter = 1;
        cout << "Option: ";
        cin >> user_input;
        // This caps the number of allowed operations to the range 1-9, this can be extended in the future.
        while (user_input.length() > 1 || !(user_input[0] >= '1' && user_input[0] <= ('0' + NUMBER_OF_CUSTOMER_OPERATIONS)))
        {
            clearScreen(system_type);
            cout << "Please select the operation you want." << endl;
            listOptions(3);
            cout << "Invalid Option. " << "(" << counter++ << ")" << endl;
            cout << "Option: ";
            cin >> user_input;
        }
        input = user_input[0] % '0';
        break;
    }

    // Purchase operation choice input.
    case 4:
    {
        counter = 1;
        cout << "Option: ";
        cin >> user_input;
        // This is caps the number of allowed operations from 1-9, this can be extended in the future.
        while (user_input.length() > 1 || !(user_input[0] >= '1' && user_input[0] <= ('0' + NUMBER_OF_PURCHASE_OPERATIONS)))
        {
            clearScreen(system_type);
            cout << "Please select the operation you want." << endl;
            listOptions(4);
            cout << "Invalid Option. " << "(" << counter++ << ")" << endl;
            cout << "Option: ";
            cin >> user_input;
        }
        input = user_input[0] % '0';
        break;
    }
    case 5:
    {
        counter = 1;
        cout << "Option: ";
        cin >> user_input;
        // This is caps the number of allowed operations from 1-9, this can be extended in the future.
        while (user_input.length() > 1 || !(user_input[0] >= '1' && user_input[0] <= ('0' + NUMBER_OF_PHARMACY_OPERATIONS)))
        {
            clearScreen(system_type);
            cout << "Please select the operation you want." << endl;
            listOptions(5);
            cout << "Invalid Option. " << "(" << counter++ << ")" << endl;
            cout << "Option: ";
            cin >> user_input;
        }
        input = user_input[0] % '0';
        break;
    }
    default:
    {
        break;
    }
    }
}

void continueDelay()
{
    string garbage;
    cout << "\nPress ENTER to continue.";
    clearStream();
    getline(cin, garbage);
}

void clearStream()
{
    cin.clear();
    cin.ignore(100000, '\n');
}