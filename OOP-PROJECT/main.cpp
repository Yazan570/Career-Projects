#include <iostream>
#include <string>
#include <regex>
#include "medication.h"
#include "Customer.h"
#include "interfacefunctions.h"
#include "operationfunctions.h"
#include "pharmacy.h"

using namespace std;

// 1 For Windows, 2 for non-Windows.
int system_typ = 1;

int main() {
    int BRANCHES = 0;
    int menu = 0, w = 0, pc = 0;
    bool checkforAccess = false;
    int checkpharma = 0;
    char cho;
    string n;
    bool exitPharmacy = false;
    // To store the pharmacy level operation the user wants to perform
    int pharmacy_choice;

    // To store the category the user wants to perform.
    int category_choice;

    // To store the operation the user wants to perform.
    int operation_choice;
    // Program Cycle.

    int current_pharmacy = 0; //pharmacy counter

    string pharmacy_name;

    string system_choice;
    cout << "Are you a windows user? (y,n)";
    cin >> system_choice;
    while ((system_choice[0] != 'y' && system_choice[0] != 'Y' && system_choice[0] != 'n' && system_choice[0] != 'N') || system_choice.length() > 1) {
        cout << "Invalid choice, please enter a valid choice: ";
        cin >> system_choice;
    }
    switch (system_choice[0])
    {
    case 'y':
    case 'Y':
        break;

    case 'n':
    case 'N':
        system_typ = 2;
        break;
    }

    Medication::setSystemType(system_typ);
    Customer::setSystemType(system_typ);
    Address::setSystemType(system_typ);
    Date::setSystemType(system_typ);
    Pharmacy::setSystemType(system_typ);

    // Clearing the screen.
    clearScreen(system_typ);

    // Start the official program.
    cout << "Welcome to the Pharmacy Management System.\n";

    cout << "To start managing your pharmacy system, please decide the number of pharmacy branches you would like to have(don't go 100 branches!):" << endl;
    cin >> BRANCHES;
    Pharmacy* pharmacy_list = new Pharmacy[BRANCHES];
    continueDelay();
    while (1) {
        clearScreen(system_typ);
        cout << "Please choose the required operation for accessing the system:" << endl;
        listOptions(5);
        getOption(5, pharmacy_choice, system_typ);

        switch (pharmacy_choice) {
            //Add Pharmacy.
        case 1:
        {
            clearScreen(system_typ);
            if (current_pharmacy == BRANCHES)
            {
                cout << "No more space for an extra pharmacy!";
                continueDelay();
                continue;
            }
            cout << "To add a new pharmacy, follow this procedure: " << endl;
            cout << "Please enter the pharmacy name: " << endl;
            clearStream();
            getline(cin, pharmacy_name);
            pharmacy_list[current_pharmacy].setName(pharmacy_name);


            pharmacy_list[current_pharmacy].activate();

            clearScreen(system_typ);
            cout << "Welcome to " << pharmacy_list[current_pharmacy].getName() << " pharmacy" << endl;
            cout << "Please go to Add a new pharmacy -> Medication -> Add medication, in order for the program to unlock most program functionalities." << endl;
            cout << "Please enter the number of the category you want to access." << endl;
            listOptions(1);
            getOption(1, category_choice, system_typ);
            while (1) {

                switch (category_choice)
                {
                    // Medicine Category.
                case 1:
                    clearScreen(system_typ);
                    cout << "Please enter the number of the operation you want to perform." << endl;
                    listOptions(2);
                    getOption(2, operation_choice, system_typ);

                    medicineOperation(system_typ, pharmacy_list[current_pharmacy], operation_choice);
                    break;
                    //------
                case 2:
                    // Customer category.
                    clearScreen(system_typ);
                    cout << "Please enter the number of the operation you want to perform." << endl;
                    listOptions(3);
                    getOption(3, operation_choice, system_typ);

                    customerOperation(system_typ, pharmacy_list[current_pharmacy], operation_choice);
                    break;
                case 3:
                    // Purchase Category.
                    clearScreen(system_typ);
                    cout << "Please enter the number of the operation you want to perform." << endl;
                    listOptions(4);
                    getOption(4, operation_choice, system_typ);

                    purchaseOperation(system_typ, pharmacy_list[current_pharmacy], operation_choice);
                    break;
                    // numOfCategories is used because the last operation will always be exiting the program,
                    // no matter how many operations we decide to add later.
                case 4:
                    // Exit
                    //exit(0);
                    exitPharmacy = true;
                    break;


                }
                if (exitPharmacy) break;
                // Listing operations and getting user's choice for next program cycle.
                clearScreen(system_typ);
                cout << "Please enter the number of the category you want to access next." << endl;
                listOptions(1);
                getOption(1, category_choice, system_typ);

            }
            cout << pharmacy_list[current_pharmacy].getName() << " pharmacy details have been successfully registered" << endl;
            continueDelay();
            clearScreen(system_typ);
            current_pharmacy++;
            if (exitPharmacy) continue;
            break;
        }
        current_pharmacy = 0;
        //Access Pharmacy.
        case 2:
        {
            clearScreen(system_typ);
            for (int i = 0; i < BRANCHES; i++)
            {
                if (pharmacy_list[i].isActive())
                {
                    checkforAccess = true;
                }
            }
            if (!checkforAccess)
            {
                cout << "No available pharmacy branch to access." << endl;
                cout << "Would you like to return to the main menu(y,n)?" << endl;
                cin >> cho;
                while ((cho != 'y' && cho != 'Y' && cho != 'n' && cho != 'N'))
                {
                    cout << "Invalid choice, please enter a valid choice: ";
                    cin >> cho;
                }
                if (cho == 'n' || cho == 'N') exit(0);
                else
                {
                    menu = 2; continueDelay(); break;
                }
            }
            if (menu == 2) continue;

            cout << "Which pharmacy would you like to access(Enter its name below)?" << endl;
            clearStream();
            getline(cin, n);
            for (int i = 0; i < BRANCHES; i++)
            {
                if (pharmacy_list[i].getName() != n)
                {
                    // cout << "No available branches with that name." << endl;
                     //continueDelay();
                     //break;
                    continue;
                }
                else if (pharmacy_list[i].getName() == n)
                {
                    cout << "Welcome to " << n << endl;
                    while (1)
                    {
                        cout << "Welcome back to <<n<< pharmacy" << endl;
                        clearScreen(system_typ);
                        listOptions(1);
                        getOption(1, category_choice, system_typ);
                        switch (category_choice)
                        {
                            // Medicine Category.
                        case 1:
                            clearScreen(system_typ);
                            cout << "Please enter the number of the operation you want to perform." << endl;
                            listOptions(2);
                            getOption(2, operation_choice, system_typ);

                            medicineOperation(system_typ, pharmacy_list[i], operation_choice);
                            break;
                            //------
                        case 2:
                            // Customer category.
                            clearScreen(system_typ);
                            cout << "Please enter the number of the operation you want to perform." << endl;
                            listOptions(3);
                            getOption(3, operation_choice, system_typ);

                            customerOperation(system_typ, pharmacy_list[i], operation_choice);
                            break;
                        case 3:
                            // Purchase Category.
                            clearScreen(system_typ);
                            cout << "Please enter the number of the operation you want to perform." << endl;
                            listOptions(4);
                            getOption(4, operation_choice, system_typ);

                            purchaseOperation(system_typ, pharmacy_list[i], operation_choice);
                            break;
                            // numOfCategories is used because the last operation will always be exiting the program,
                            // no matter how many operations we decide to add later.
                        case 4:
                            // Return
                            //exit(0);
                            w = 5;
                            break;
                        }
                        if (w == 5) break;
                        //Listing operations and getting user's choice for next program cycle.
                        clearScreen(system_typ);
                        cout << "Please enter the number of the category you want to access next." << endl;
                        listOptions(1);
                        getOption(1, category_choice, system_typ);
                    }
                    if (w == 5)break;
                }

            }
            break;
        }
        //-----------------------------------------------------------------------------------------------------------------------
            //Remove Pharmacy.
        case 3:
        {
            clearScreen(system_typ);
            string removePharmacy;
            bool checker = true; //to check if the name is included
            for (int i = 0; i < BRANCHES; i++) {
                if (pharmacy_list[i].isActive()) checkpharma = 1;
            }
            if (checkpharma == 0) {
                cout << "No available branches to remove.\n";
                continueDelay();
                break;
            }
            cout << "List of all pharmacies: " << endl;
            for (int i = 0, j = 1; i < BRANCHES; i++)
            {

                if (pharmacy_list[i].isActive())
                    cout << j << ". " << pharmacy_list[i].getName() << endl; j++;
            }

            cout << "Enter the name of the pharmacy you want to remove: " << endl;
            clearStream();
            getline(cin, removePharmacy);

            for (int i = 0; i < BRANCHES; i++) {
                if (pharmacy_list[i].getName() == removePharmacy) {
                    clearScreen(system_typ);
                    cout << "Pharmacy " << pharmacy_list[i].getName() << " removed.";
                    pharmacy_list[i].deactivate();
                    continueDelay();
                    checker = false;
                    break;
                }

            }
            if (checker) {
                cout << "Sorry, but there is no pharmacy with this name." << endl;
                continueDelay();
            }
            break;
        }
        //Add a Branch.
        case 4:
        {
            clearScreen(system_typ);
            int extraBranches = 0;
            cout << "Enter the number of extra branches you'd like to add:" << endl;
            cin >> extraBranches;
            Pharmacy* temp = new Pharmacy[BRANCHES + extraBranches];
            for (int i = 0; i < BRANCHES; i++)
            {
                temp[i] = pharmacy_list[i];
            }
            BRANCHES += extraBranches;
            delete[] pharmacy_list;
            pharmacy_list = temp;
            temp = NULL;
            break;
        }
        //Exit The System.
        case 5:
            clearScreen(system_typ);
            cout << "Thank you for using the system";
            exit(0);
        }

        if (w == 5)continue;
    }
    return 0;
}