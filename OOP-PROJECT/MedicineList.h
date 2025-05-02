#ifndef MEDICINE_LIST_H_
#define MEDICINE_LIST_H_

#include "Medication.h"
#include "OffTheShelf.h"
#include "Perscription.h"
#include <iostream>
#include <string>

using namespace std;



class MedicineList
{
private:
    Perscription* medicine_list_perscription;
    OffTheShelf* medicine_list_offTheShelf;
    int next_available_slot_perscription;
    int latest_active_index_perscription;
    int next_available_slot_offTheShelf;
    int latest_active_index_offTheShelf;
    static int system_type;
    int current_size_perscription;
    int current_size_offTheShelf;

    // Ask the user if he wants to access the persription medicine list or the off the shelf medicine list
    string offTheShelfOrPerscription() const;

    // Utitlity Functions
    void updateLastestActiveIndex(string n);
    bool updateNextAvailableSlot(string n);
    int findIndexWithId(const int& medicine_id, string n);

    // Functionality of class.
    int getNumberOfAvailableSlots(string n) const;
    bool hasAvailableSlot(string n) const;

    
    void displayAllPerscription();
    void displayAllOffTheShelf();
    void displayActivePerscription();
    void displayActiveOffTheShelf();
    void displayAvailablePerscription();
    void displayAvailableOffTheShelf();

public:
    //update array size, or create the array
    void addMoreMedicine(const int size);

    //Counstructors and destructor
    MedicineList();
    ~MedicineList();

    //system type -> windows or other operting systems
    static bool setSystemType(const int& system_type);


    int getNumberOfActiveSlotsPerscription();
    int getNumberOfActiveSlotsOffTheShelf();

    // for the other classes
    int getNumberOfActiveSlots();

    void addMedicine();
    void removeMedicine();

    // for the other classes
    void displayActive();
    void displayAvailable();



    void purchaseMedicine(double& pharmacy_total_sales, double& pharmacy_total_profit);

};

#endif // !MEDICINE_LIST_H_
