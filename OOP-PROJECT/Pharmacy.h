#ifndef PHARMACY_H_
#define PHARMACY_H_
#include "Medication.h"
#include "MedicineList.h"
#include "Date.h"

#include "Customer.h"
#include "Address.h"
#include "CustomerList.h"

using namespace std;

class Pharmacy
{
private:
    static int system_type;
    bool active;
    long ID;
    static int id_counter;

    string name;

    double sales;
    double profit;

public:
    MedicineList medicine_list;
    CustomerList customer_list;

    Pharmacy();

    static void setSystemType(const int& system_type);

    string getName();
    bool setName(string name);

    void recordPurchase();

    double getSales();
    double getProfit();

    bool setSales(string sales);
    bool setProfit(string profit);

    bool hasMoreMedicineThan(Pharmacy& pharmacy);
    bool hasMoreCustomersThan(Pharmacy& pharmacy);
    bool hasMoreProfitThan(Pharmacy& pharmacy);
    bool hasMoreTotalSalesThan(Pharmacy& pharmacy);
    bool isActive();
    bool activate();
    void deactivate();
};

#endif // !PHARMACY_H_