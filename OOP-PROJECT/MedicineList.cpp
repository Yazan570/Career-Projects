#include "MedicineList.h"
#include "interfacefunctions.h"
#include "validationfunctions.h"

#include <iostream>
#include <string>

using namespace std;

int MedicineList::system_type = 1;

// Update array size, or create the array
void MedicineList::addMoreMedicine(const int size)
{
    string n = offTheShelfOrPerscription();
    if (n == "1")
    {
        Perscription* new_array = new Perscription[size + current_size_perscription];
        for (int i = 0; i < current_size_perscription; i++)
        {
            new_array[i] = medicine_list_perscription[i];
        }
        delete[] medicine_list_perscription;
        medicine_list_perscription = new_array;
        current_size_perscription += size;
    }
    else {
        OffTheShelf* new_array = new OffTheShelf[size + current_size_offTheShelf];
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            new_array[i] = medicine_list_offTheShelf[i];
        }
        delete[] medicine_list_offTheShelf;
        medicine_list_offTheShelf = new_array;
        current_size_offTheShelf += size;
        updateLastestActiveIndex("2");
    }
}

MedicineList::~MedicineList()
{
    delete[] medicine_list_perscription;
    delete[] medicine_list_offTheShelf;
}

// Ask the user if he wants the perscription medicine list or off the shelf medicine list
string MedicineList::offTheShelfOrPerscription() const
{
    cout << "For perscription medicine list enter 1, and for off the shelf medicine list enter 2: ";
    string n;
    cin >> n;
    while (n != "1" && n != "2") {
        cout << "Invalid value" << endl;
        cout << "For perscription medicine list enter 1, and for off the shelf medicine list enter 2: ";
        cin >> n;
    }
    clearScreen(system_type);
    return n;
}

// System type -> windows or other operting systems
bool MedicineList::setSystemType(const int& system_type)
{
    if (system_type != 1 && system_type != 2)
    {
        return false;
    }

    MedicineList::system_type = system_type;
    return true;
}

// Counstructor
MedicineList::MedicineList()
{
    this->next_available_slot_perscription = 0;
    this->latest_active_index_perscription = -1;
    this->next_available_slot_offTheShelf = 0;
    this->latest_active_index_offTheShelf = -1;
    this->current_size_perscription = 1;
    this->current_size_offTheShelf = 1;
    this->medicine_list_perscription = new Perscription[current_size_perscription];
    this->medicine_list_offTheShelf = new OffTheShelf[current_size_perscription];

}

// For the other classes like pharmacy
// Int n, the function should just call in this class, when we call it i decide if it's the perscrption medicine list or the off the shelf medicine list
bool MedicineList::updateNextAvailableSlot(string n)
{

    if (n == "1")
    {
        for (int i = 0; i < current_size_perscription; i++)
        {
            // Looking for next available slot.
            if (!medicine_list_perscription[i].isActive())
            {
                next_available_slot_perscription = i;
                break;
            }
        }

        if (next_available_slot_perscription >= current_size_perscription)
        {
            return false;
        }
        // Checks if all slots are active.
        if (medicine_list_perscription[next_available_slot_perscription].isActive())
        {
            return false;
        }

        return true;
    }

    else
    {
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            // Looking for next available slot.
            if (!medicine_list_offTheShelf[i].isActive())
            {
                next_available_slot_offTheShelf = i;
                break;
            }
        }

        // Checks if all slots are active.
        if (medicine_list_offTheShelf[next_available_slot_offTheShelf].isActive())
        {
            return false;
        }

        return true;
    }


}

//for this class
//int n, the function should just call in this class, when we call it i decide if it's the perscrption medicine list or the off the shelf medicine list
int MedicineList::getNumberOfAvailableSlots(string n) const
{

    if (n == "1")
    {
        int available_slot_counter = 0;
        for (int i = 0; i < current_size_perscription; i++)
        {
            if (!medicine_list_perscription[i].isActive())
            {
                available_slot_counter++;
            }
        }

        return available_slot_counter;
    }
    else
    {
        int available_slot_counter = 0;
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            if (!medicine_list_offTheShelf[i].isActive())
            {
                available_slot_counter++;
            }
        }

        return available_slot_counter;
    }
}

// Int n, the function should just call in this class, when we call it i decide if it's the perscrption medicine list or the off the shelf medicine list
bool MedicineList::hasAvailableSlot(string n) const
{
    if (n == "1")
    {
        for (int i = 0; i < current_size_perscription; i++)
        {
            if (!medicine_list_perscription[i].isActive())
            {
                return true;
            }
        }

        return false;
    }
    else
    {
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            if (!medicine_list_offTheShelf[i].isActive())
            {
                return true;
            }
        }

        return false;

    }
}
// Int n, the function should just call in this class, when we call it i decide if it's the perscrption medicine list or the off the shelf medicine list
void MedicineList::updateLastestActiveIndex(string n)
{
    if (n == "1")
    {
        for (int i = 0; i < current_size_perscription; i++)
        {
            if (medicine_list_perscription[i].isActive())
            {
                latest_active_index_perscription = i;
            }
        }
    }
    else
    {
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            if (medicine_list_offTheShelf[i].isActive())
            {
                latest_active_index_offTheShelf = i;
            }
        }
    }
}
// When i call it, i call it in other function in this class, and i call it in the cases for perscription
int MedicineList::getNumberOfActiveSlotsPerscription()
{
    updateLastestActiveIndex("1");
    int active_slot_counter = 0;
    for (int i = 0; i <= latest_active_index_perscription; i++)
    {
        if (medicine_list_perscription[i].isActive())
        {
            active_slot_counter++;
        }
    }

    return active_slot_counter;

}
// When i call it, i call it in other function in this class, and i call it in the cases for off the shelf
int MedicineList::getNumberOfActiveSlotsOffTheShelf() {
    updateLastestActiveIndex("2");
    int active_slot_counter = 0;
    for (int i = 0; i <= latest_active_index_offTheShelf; i++)
    {
        if (medicine_list_offTheShelf[i].isActive())
        {
            active_slot_counter++;
        }
    }

    return active_slot_counter;
}

// this function for the other classes 
int MedicineList::getNumberOfActiveSlots()
{
    updateLastestActiveIndex("1");
    updateLastestActiveIndex("2");
    int active_slot_counter1 = 0;
    for (int i = 0; i <= latest_active_index_perscription; i++)
    {
        if (medicine_list_perscription[i].isActive())
        {
            active_slot_counter1++;
        }
    }
    int active_slot_counter2 = 0;
    for (int i = 0; i <= latest_active_index_offTheShelf; i++)
    {
        if (medicine_list_offTheShelf[i].isActive())
        {
            active_slot_counter2++;
        }
    }
    return active_slot_counter1 + active_slot_counter2;

}


void MedicineList::addMedicine()
{
    // ask the user if he wants to add a medicine in the perscription medicine list
    string n = offTheShelfOrPerscription();
    if (n == "1")
    {
        // it will enter the else if the user choose to enter the off the perscription medicine list
        if (!(this->updateNextAvailableSlot("1")))
        {
            clearScreen(system_type);
            Perscription* new_array = new Perscription[1 + current_size_perscription];
            for (int i = 0; i < current_size_perscription; i++)
            {
                new_array[i] = medicine_list_perscription[i];
            }

            delete[] medicine_list_perscription;

            medicine_list_perscription = new_array;

            current_size_perscription++;
        }
        this->updateNextAvailableSlot("1");
        cout << "Currently available medicine slots: " << this->getNumberOfAvailableSlots("1") << endl;

        // Gets the name.
        string name;
        cout << "Please enter the medication's name: ";
        cin >> name;
        medicine_list_perscription[next_available_slot_perscription].setName(name);

        // Gets the description.
        string description;
        clearScreen(system_type);
        cout << "Please enter the medication's description: ";
        cin.clear();
        cin.ignore(100000, '\n');
        getline(cin, description);
        medicine_list_perscription[next_available_slot_perscription].setDescription(description);

        // Gets the retail price.
        string retail_price;

        // Input Prompt.
        clearScreen(system_type);
        cout << "Please enter the medication's retail price in JOD." << endl;
        cout << "Price: ";
        cin >> retail_price;

        if (!(medicine_list_perscription[next_available_slot_perscription].setRetailPrice(retail_price)))
        {
            medicine_list_perscription[next_available_slot_perscription].deactivate();
            return;
        }

        // Gets the Whole Sale Price.
        clearScreen(system_type);
        string wholesale_price;

        // Input Prompt.
        cout << "Please enter the medication's wholesale price in JOD." << endl;
        cout << "Price: ";
        cin >> wholesale_price;

        if (!(medicine_list_perscription[next_available_slot_perscription].setWholesalePrice(wholesale_price)))
        {
            medicine_list_perscription[next_available_slot_perscription].deactivate();
        }

        //because the whole price is more than the retail price, it will cause a loss
        string answer;
        while (stoi(wholesale_price) > stoi(retail_price))
        {
            cout << "The wholesale price is more than the retail price, this will cause loss in profit, are you sure you want to continue? (y,n)";
            cin >> answer;
            while ((answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N') || answer.length() > 1)
            {
                cout << "Invalid choice, please enter a valid choice: ";
                cin >> answer;
            }
            if (answer == "y" || answer == "Y")
            {
                break;
            }


            cout << "Please enter the medication's retail price in JOD." << endl;
            cout << "Price: ";
            cin >> retail_price;

            if (!(medicine_list_perscription[next_available_slot_perscription].setRetailPrice(retail_price)))
            {
                medicine_list_perscription[next_available_slot_perscription].deactivate();
                return;
            }

        }
        // Gets the quantity in stock.
        clearScreen(system_type);
        string quantity_in_stock_input;
        cout << "Please enter the medication's quantity in stock: ";
        cin >> quantity_in_stock_input;

        if (!(medicine_list_perscription[next_available_slot_perscription].setQuantityInStock(quantity_in_stock_input)))
        {
            medicine_list_perscription[next_available_slot_perscription].deactivate();
            return;
        }

        // Setting the expiration date of the year.
        clearScreen(system_type);
        string year;
        cout << "Please enter the expiry date year [Between 1970 & 2050]: ";
        cin >> year;
        medicine_list_perscription[next_available_slot_perscription].getExpiryDate().setYear(year);

        clearScreen(system_type);
        string month;
        cout << "Please enter the expiry date month: ";
        cin >> month;
        medicine_list_perscription[next_available_slot_perscription].getExpiryDate().setMonth(month);

        clearScreen(system_type);
        string day;
        cout << "Please enter the expiry date day: ";
        cin >> day;
        medicine_list_perscription[next_available_slot_perscription].getExpiryDate().setDay(day);


        // Gets the Barcode.
        clearScreen(system_type);
        string barcode;
        cout << "Please enter the medication's barcode: ";
        cin >> barcode;
        if (!(medicine_list_perscription[next_available_slot_perscription].setBarcode(barcode)))
        {
            medicine_list_perscription[next_available_slot_perscription].deactivate();
            return;
        }
        clearScreen(system_type);
        medicine_list_perscription[next_available_slot_perscription].activate();


        // Gets the Fda Number
        clearScreen(system_type);
        int fda_number;
        cout << "Please enter the medicatien fda number: ";
        cin >> fda_number;
        medicine_list_perscription[next_available_slot_perscription].setFdaNumber(fda_number);


        //gets the approval date
        clearScreen(system_type);
        Date approvalDate;
        string year_approvalDate;
        cout << "Please enter the approval date year: ";
        cin >> year_approvalDate;
        approvalDate.setYear(year_approvalDate);

        clearScreen(system_type);
        string month_approvalDate;
        cout << "Please enter the approval date month: ";
        cin >> month_approvalDate;
        approvalDate.setMonth(month_approvalDate);

        clearScreen(system_type);
        string day_approvalDate;
        cout << "Please enter the approval date day: ";
        cin >> day_approvalDate;
        approvalDate.setDay(day_approvalDate);

        medicine_list_perscription[next_available_slot_perscription].setApprovalDate(approvalDate);


        clearScreen(system_type);
        medicine_list_perscription[next_available_slot_perscription].activate();
        this->updateLastestActiveIndex("1");
        this->updateNextAvailableSlot("1");
        cout << "Medicine Added." << endl;

        return;
    }

    // it will enter the else, if the user choose to enter the off the shelf medicine list
    else
    {
        if (!(this->updateNextAvailableSlot("2")))
        {
            clearScreen(system_type);
            OffTheShelf* new_array = new OffTheShelf[1 + current_size_offTheShelf];
            for (int i = 0; i < current_size_offTheShelf; i++)
            {
                new_array[i] = medicine_list_offTheShelf[i];
            }
            delete[] medicine_list_offTheShelf;
            medicine_list_offTheShelf = new_array;
            current_size_offTheShelf++;

        }
        this->updateNextAvailableSlot("2");

        cout << "Currently available medicine slots: " << this->getNumberOfAvailableSlots("2") << endl;

        // Gets the name.
        string name;
        cout << "Please enter the medication's name: ";
        cin >> name;
        medicine_list_offTheShelf[next_available_slot_offTheShelf].setName(name);

        // Gets the description.
        string description;
        clearScreen(system_type);
        cout << "Please enter the medication's description: ";
        cin.clear();
        cin.ignore(100000, '\n');
        getline(cin, description);
        medicine_list_offTheShelf[next_available_slot_offTheShelf].setDescription(description);

        // Gets the retail price.
        string retail_price;

        // Input Prompt.
        clearScreen(system_type);
        cout << "Please enter the medication's retail price in JOD." << endl;
        cout << "Price: ";
        cin >> retail_price;

        if (!(medicine_list_offTheShelf[next_available_slot_offTheShelf].setRetailPrice(retail_price)))
        {
            medicine_list_offTheShelf[next_available_slot_offTheShelf].deactivate();
            return;
        }

        // Gets the Whole Sale Price.
        clearScreen(system_type);
        string wholesale_price;

        // Input Prompt.
        cout << "Please enter the medication's wholesale price in JOD." << endl;
        cout << "Price: ";
        cin >> wholesale_price;

        if (!(medicine_list_offTheShelf[next_available_slot_offTheShelf].setWholesalePrice(wholesale_price)))
        {
            medicine_list_perscription[next_available_slot_offTheShelf].deactivate();
        }
        string answer;
        while (stoi(wholesale_price) > stoi(retail_price))
        {
            cout << "The wholesale price is more than the retail price, this will cause loss in profit, are you sure you want to continue? (y,n)";
            cin >> answer;
            while ((answer[0] != 'y' && answer[0] != 'Y' && answer[0] != 'n' && answer[0] != 'N') || answer.length() > 1)
            {
                cout << "Invalid choice, please enter a valid choice: ";
                cin >> answer;
            }
            if (answer == "y" || answer == "Y")
            {
                break;
            }


            cout << "Please enter the medication's retail price in JOD." << endl;
            cout << "Price: ";
            cin >> retail_price;

            if (!(medicine_list_offTheShelf[next_available_slot_offTheShelf].setRetailPrice(retail_price)))
            {
                medicine_list_offTheShelf[next_available_slot_offTheShelf].deactivate();
                return;
            }

        }
        // Gets the quantity in stock.
        clearScreen(system_type);
        string quantity_in_stock_input;
        cout << "Please enter the medication's quantity in stock: ";
        cin >> quantity_in_stock_input;

        if (!(medicine_list_offTheShelf[next_available_slot_offTheShelf].setQuantityInStock(quantity_in_stock_input)))
        {
            medicine_list_offTheShelf[next_available_slot_offTheShelf].deactivate();
            return;
        }

        // Setting the expiration date of the year.
        clearScreen(system_type);
        string year;
        cout << "Please enter the expiry date year [Between 1970 & 2050]: ";
        cin >> year;
        medicine_list_offTheShelf[next_available_slot_offTheShelf].getExpiryDate().setYear(year);

        clearScreen(system_type);
        string month;
        cout << "Please enter the expiry date month: ";
        cin >> month;
        medicine_list_offTheShelf[next_available_slot_offTheShelf].getExpiryDate().setMonth(month);

        clearScreen(system_type);
        string day;
        cout << "Please enter the expiry date day: ";
        cin >> day;
        medicine_list_offTheShelf[next_available_slot_offTheShelf].getExpiryDate().setDay(day);


        // Gets the Barcode.
        clearScreen(system_type);
        string barcode;
        cout << "Please enter the medication's barcode: ";
        cin >> barcode;
        if (!(medicine_list_offTheShelf[next_available_slot_offTheShelf].setBarcode(barcode)))
        {
            medicine_list_offTheShelf[next_available_slot_offTheShelf].deactivate();
            return;
        }
        clearScreen(system_type);
        medicine_list_offTheShelf[next_available_slot_offTheShelf].activate();

        this->updateNextAvailableSlot("2");
        cout << "Medicine Added." << endl;

        //buy one get one free
        clearScreen(system_type);
        string choice;
        cout << "medicine have one buy get one offer? (y,n)";
        cin >> choice;
        while ((choice[0] != 'Y' && choice[0] != 'y' && choice[0] != 'N' && choice[0] != 'n') || choice.length() > 1)
        {
            cout << "invalid value" << endl;
            cin >> choice;

        }
        if (choice == "Y")
        {
            medicine_list_offTheShelf[next_available_slot_offTheShelf].setBuyOneGetOneFree(1);
        }


        return;
    }
}

void MedicineList::removeMedicine()
{
    // if the user choose 1, it will enter the perscription medicine list
    string n = offTheShelfOrPerscription();
    if (n == "1")
    {
        // it will enter the else if the user choose to enter the perscription medicine list
        if (getNumberOfActiveSlotsPerscription() == 0)
        {
            cout << "There is no medicine in this pharmacy!" << endl;
            return;
        }

        this->displayAllPerscription();

        string deleted_medicine_id;
        cout << "Please enter the ID of the medicine that you want to delete: ";
        cin >> deleted_medicine_id;
        for (int i = 0; i < deleted_medicine_id.length(); i++)
        {
            if (isNumber(deleted_medicine_id[i]))
            {
                continue;
            }

            i = -1;
            clearScreen(system_type);
            clearStream();
            cout << "Invalid input." << endl;
            cout << "Please enter the id of the medicine that you want to delete: ";
            cin >> deleted_medicine_id;
        }

        clearScreen(system_type);
        Perscription* new_array = new Perscription[current_size_perscription - 1];
        int counter_for_perscription = 0;
        for (int i = 0; i < current_size_perscription; i++)
        {
            if (medicine_list_perscription[i].getID() == stoi(deleted_medicine_id))
            {
                continue;
            }
            else
            {
                new_array[counter_for_perscription] = medicine_list_perscription[i];
                counter_for_perscription++;
            }

        }
        delete[] medicine_list_perscription;
        medicine_list_perscription = new_array;
        current_size_perscription -= 1;

        cout << "Medicine Removed." << endl;
        return;

    }


    else
    {
        // it will enter the else if the user choose to enter the off the shelf medicine list
        if (getNumberOfActiveSlotsOffTheShelf() == 0)
        {
            cout << "There is no medicine in this pharmacy!" << endl;
            return;
        }

        this->displayAllOffTheShelf();

        string deleted_medicine_id;
        cout << "Please enter the ID of the medicine that you want to delete: ";
        cin >> deleted_medicine_id;
        for (int i = 0; i < deleted_medicine_id.length(); i++)
        {
            if (isNumber(deleted_medicine_id[i]))
            {
                continue;
            }

            i = -1;
            clearScreen(system_type);
            clearStream();
            cout << "Invalid input." << endl;
            cout << "Please enter the id of the medicine that you want to delete: ";
            cin >> deleted_medicine_id;
        }
        bool flag = false;
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            if (medicine_list_offTheShelf[i].getID() == stoi(deleted_medicine_id)) flag = true;
        }
        if (flag == false)
        {
            cout << "There's no medicine with this id" << endl;
            return;
        }
        clearScreen(system_type);
        OffTheShelf* new_array = new OffTheShelf[current_size_offTheShelf - 1];
        int counter_for_offTheShelf = 0;
        for (int i = 0; i < current_size_offTheShelf; i++)
        {
            if (medicine_list_offTheShelf[i].getID() == stoi(deleted_medicine_id))
            {
                continue;
            }
            else
            {
                new_array[counter_for_offTheShelf] = medicine_list_offTheShelf[i];
                counter_for_offTheShelf++;
            }

        }
        delete[] medicine_list_offTheShelf;
        medicine_list_offTheShelf = new_array;
        current_size_offTheShelf -= 1;

        cout << "Medicine Removed." << endl;
        return;


    }

}

// for the classes
void MedicineList::displayActive()
{
    string n = offTheShelfOrPerscription();
    if (n == "1")
    {
        if (this->getNumberOfActiveSlotsPerscription() == 0)
        {
            cout << "There is no medicine in this pharmacy!" << endl;
            return;
        }

        updateLastestActiveIndex("1");
        for (int i = 0; i <= latest_active_index_perscription; i++)
        {
            if (!medicine_list_perscription[i].isActive())
            {
                continue;
            }

            medicine_list_perscription[i].printInfo();

            if (i != latest_active_index_perscription)
            {
                cout << "---------------------" << endl;
            }
        }
    }

    else
    {
        if (this->getNumberOfActiveSlotsOffTheShelf() == 0)
        {
            cout << "There is no medicine in this pharmacy!" << endl;
            return;
        }

        updateLastestActiveIndex("2");
        for (int i = 0; i <= latest_active_index_offTheShelf; i++)
        {
            if (!medicine_list_offTheShelf[i].isActive())
            {
                continue;
            }

            medicine_list_offTheShelf[i].printInfo();

            if (i != latest_active_index_offTheShelf)
            {
                cout << "---------------------" << endl;
            }
        }
    }
}

// for the other classes
void MedicineList::displayAvailable()
{
    string n = offTheShelfOrPerscription();
    if (n == "1")
    {

        if (this->getNumberOfActiveSlotsPerscription() == 0)
        {
            cout << "There is no medicine in this pharmacy!" << endl;
            return;
        }

        updateLastestActiveIndex("1");
        for (int i = 0; i <= latest_active_index_perscription; i++)
        {
            if (!medicine_list_perscription[i].isActive())
            {
                continue;
            }

            if (medicine_list_perscription[i].getQuantityInStock() == 0)
            {
                continue;
            }

            medicine_list_perscription[i].printInfo();

            if (i != latest_active_index_perscription)
            {
                cout << "---------------------" << endl;
            }
        }
    }
    else
    {

        if (this->getNumberOfActiveSlotsOffTheShelf() == 0)
        {
            cout << "There is no medicine in this pharmacy!" << endl;
            return;
        }

        updateLastestActiveIndex("2");
        for (int i = 0; i <= latest_active_index_offTheShelf; i++)
        {
            if (!medicine_list_offTheShelf[i].isActive())
            {
                continue;
            }

            if (medicine_list_offTheShelf[i].getQuantityInStock() == 0)
            {
                continue;
            }

            medicine_list_offTheShelf[i].printInfo();

            if (i != latest_active_index_offTheShelf)
            {
                cout << "---------------------" << endl;
            }
        }
    }
}


void MedicineList::displayAllPerscription()
{

    if (this->getNumberOfActiveSlotsPerscription() == 0)
    {
        cout << "There is no medicine in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex("1");
    for (int i = 0; i <= latest_active_index_perscription; i++)
    {
        medicine_list_perscription[i].printInfo();
        if (i != latest_active_index_perscription)
        {
            cout << "---------------------" << endl;
        }
    }


}

void MedicineList::displayAllOffTheShelf()
{
    if (this->getNumberOfActiveSlotsOffTheShelf() == 0)
    {
        cout << "There is no medicine in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex("2");
    for (int i = 0; i <= latest_active_index_offTheShelf; i++)
    {
        medicine_list_offTheShelf[i].printInfo();

        if (i != latest_active_index_offTheShelf)
        {
            cout << "---------------------" << endl;
        }
    }
}



void MedicineList::displayActivePerscription()
{

    if (this->getNumberOfActiveSlotsPerscription() == 0)
    {
        cout << "There is no medicine in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex("1");
    for (int i = 0; i <= latest_active_index_perscription; i++)
    {
        if (!medicine_list_perscription[i].isActive())
        {
            continue;
        }

        medicine_list_perscription[i].printInfo();

        if (i != latest_active_index_perscription)
        {
            cout << "---------------------" << endl;
        }
    }

}
void MedicineList::displayActiveOffTheShelf()
{
    if (this->getNumberOfActiveSlotsOffTheShelf() == 0)
    {
        cout << "There is no medicine in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex("2");
    for (int i = 0; i <= latest_active_index_offTheShelf; i++)
    {
        if (!medicine_list_offTheShelf[i].isActive())
        {
            continue;
        }

        medicine_list_offTheShelf[i].printInfo();

        if (i != latest_active_index_offTheShelf)
        {
            cout << "---------------------" << endl;
        }
    }
}

void MedicineList::displayAvailablePerscription()
{

    if (this->getNumberOfActiveSlotsPerscription() == 0)
    {
        cout << "There is no medicine in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex("1");
    for (int i = 0; i <= latest_active_index_perscription; i++)
    {
        if (!medicine_list_perscription[i].isActive())
        {
            continue;
        }

        if (medicine_list_perscription[i].getQuantityInStock() == 0)
        {
            continue;
        }

        medicine_list_perscription[i].printInfo();

        if (i != latest_active_index_perscription)
        {
            cout << "---------------------" << endl;
        }
    }
}

void MedicineList::displayAvailableOffTheShelf()
{
    if (this->getNumberOfActiveSlotsOffTheShelf() == 0)
    {
        cout << "There is no medicine in this pharmacy!" << endl;
        return;
    }

    updateLastestActiveIndex("2");
    for (int i = 0; i <= latest_active_index_offTheShelf; i++)
    {
        if (!medicine_list_offTheShelf[i].isActive())
        {
            continue;
        }

        if (medicine_list_offTheShelf[i].getQuantityInStock() == 0)
        {
            continue;
        }

        medicine_list_offTheShelf[i].printInfo();

        if (i != latest_active_index_offTheShelf)
        {
            cout << "---------------------" << endl;
        }
    }
}

// for the remove medicine function in this class
int MedicineList::findIndexWithId(const int& medicine_id, string n)
{
    if (n == "1")
    {
        updateLastestActiveIndex("1");
        int medicine_index = -1;
        for (int i = 0; i <= latest_active_index_perscription; i++)
        {
            if (!medicine_list_perscription[i].isActive())
            {
                continue;
            }

            if (medicine_list_perscription[i].getID() == medicine_id)
            {
                medicine_index = i;
            }
        }

        return medicine_index;
    }
    else
    {
        updateLastestActiveIndex("2");
        int medicine_index = -1;
        for (int i = 0; i <= latest_active_index_offTheShelf; i++)
        {
            if (!medicine_list_offTheShelf[i].isActive())
            {
                continue;
            }

            if (medicine_list_offTheShelf[i].getID() == medicine_id)
            {
                medicine_index = i;
            }
        }

        return medicine_index;
    }

}


void MedicineList::purchaseMedicine(double& pharmacy_total_sales, double& pharmacy_total_profit)
{
    string n = offTheShelfOrPerscription();
    if (n == "1")
    {
        if (getNumberOfActiveSlotsPerscription() == 0)
        {
            clearScreen(system_type);
            cout << "There's no medicine available, Please try again later." << endl;
            continueDelay();
            return;
        }

        // Print available medication names, retail prices, and quantity in stock.
        this->displayAvailablePerscription();

        // Check if user has inputted an entry that is all numbers.
        string selected_id_input;
        cout << "Please enter the ID of the medicine you want to buy: ";
        cin >> selected_id_input;
        for (int i = 0; i < selected_id_input.length(); i++)
        {
            if (isNumber(selected_id_input[i]))
            {
                continue;
            }

            i = -1;
            clearScreen(system_type);
            cout << "Invalid entry, please try again." << endl;
            cout << "Please enter the ID of the medicine you want to buy: ";
            cin >> selected_id_input;
        }

        int purchased_medicine_index = this->findIndexWithId(stoi(selected_id_input), "1");

        // If no active medicine matches the selected medicine id.
        if (purchased_medicine_index == -1)
        {
            clearScreen(system_type);
            cout << "Medicine selected does not exist." << endl;
            return;
        }

        // Checks if medicine does not have any stock.
        if (medicine_list_perscription[purchased_medicine_index].getQuantityInStock() == 0)
        {
            clearScreen(system_type);
            cout << "Medicine is out of stock." << endl;
            return;
        }

        // Validation for quantity purchased input.
        string quantity_purchased_input;
        cout << "Please enter the purchased quantity: ";
        cin >> quantity_purchased_input;
        for (int i = 0; i < quantity_purchased_input.length(); i++)
        {
            if (isNumber(quantity_purchased_input[i]))
            {
                continue;
            }

            i = -1;
            cout << "Invalid entry, please try again." << endl;
            cout << "Please enter the purchased quantity: ";
            clearStream();
            cin >> quantity_purchased_input;
        }

        // If the quantity purchased is larger than the quantity in stock.
        if (stoi(quantity_purchased_input) > medicine_list_perscription[purchased_medicine_index].getQuantityInStock())
        {
            clearScreen(system_type);
            cout << "Medicine does not have purchased quantity." << endl;
            return;
        }

        // Subtracting previously added sales and profit
        pharmacy_total_sales -= medicine_list_perscription[purchased_medicine_index].getTotalSales();
        pharmacy_total_profit -= medicine_list_perscription[purchased_medicine_index].getTotalProfit();

        // Recording the purchase.
        medicine_list_perscription[purchased_medicine_index].purchaseMedicine(stoi(quantity_purchased_input));

        // Adding the new sales and profit
        pharmacy_total_sales += medicine_list_perscription[purchased_medicine_index].getTotalSales();
        pharmacy_total_profit += medicine_list_perscription[purchased_medicine_index].getTotalProfit();

        clearScreen(system_type);
        cout << "Purchase recorded." << endl;
    }


    else
    {
        if (getNumberOfActiveSlotsOffTheShelf() == 0)
        {
            clearScreen(system_type);
            cout << "There's no medicine available, Please try again later." << endl;
            continueDelay();
            return;
        }

        // Print available medication names, retail prices, and quantity in stock.
        this->displayAvailableOffTheShelf();

        // Check if user has inputted an entry that is all numbers.
        string selected_id_input;
        cout << "Please enter the ID of the medicine you want to buy: ";
        cin >> selected_id_input;
        for (int i = 0; i < selected_id_input.length(); i++)
        {
            if (isNumber(selected_id_input[i]))
            {
                continue;
            }

            i = -1;
            clearScreen(system_type);
            cout << "Invalid entry, please try again." << endl;
            cout << "Please enter the ID of the medicine you want to buy: ";
            cin >> selected_id_input;
        }

        int purchased_medicine_index = this->findIndexWithId(stoi(selected_id_input), "2");

        // If no active medicine matches the selected medicine id.
        if (purchased_medicine_index == -1)
        {
            clearScreen(system_type);
            cout << "Medicine selected does not exist." << endl;
            return;
        }

        // Checks if medicine does not have any stock.
        if (medicine_list_offTheShelf[purchased_medicine_index].getQuantityInStock() == 0)
        {
            clearScreen(system_type);
            cout << "Medicine is out of stock." << endl;
            return;
        }

        // Validation for quantity purchased input.
        string quantity_purchased_input;
        cout << "Please enter the purchased quantity: ";
        cin >> quantity_purchased_input;
        for (int i = 0; i < quantity_purchased_input.length(); i++)
        {
            if (isNumber(quantity_purchased_input[i]))
            {
                continue;
            }

            i = -1;
            cout << "Invalid entry, please try again." << endl;
            cout << "Please enter the purchased quantity: ";
            clearStream();
            cin >> quantity_purchased_input;
        }

        // If the quantity purchased is larger than the quantity in stock.
        if (stoi(quantity_purchased_input) > medicine_list_offTheShelf[purchased_medicine_index].getQuantityInStock())
        {
            clearScreen(system_type);
            cout << "Medicine does not have purchased quantity." << endl;
            return;
        }

        // Subtracting previously added sales and profit
        pharmacy_total_sales -= medicine_list_offTheShelf[purchased_medicine_index].getTotalSales();
        pharmacy_total_profit -= medicine_list_offTheShelf[purchased_medicine_index].getTotalProfit();

        // Recording the purchase.
        medicine_list_offTheShelf[purchased_medicine_index].purchaseMedicine(stoi(quantity_purchased_input));

        // Adding the new sales and profit
        pharmacy_total_sales += medicine_list_offTheShelf[purchased_medicine_index].getTotalSales();
        pharmacy_total_profit += medicine_list_offTheShelf[purchased_medicine_index].getTotalProfit();

        clearScreen(system_type);
        cout << "Purchase recorded." << endl;
    }

}