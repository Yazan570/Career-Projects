#ifndef _MEDICATION_H__
#define _MEDICATION_H__

#include "Date.h"

#include <iostream>
#include <string>
#include <regex>


using namespace std;
class Medication
{
private:
    static int system_type;
    // Data required to implement sequential IDs for medication objects.
    long ID;
    static int id_counter;

    string name; // Medication name.
    string description; // Medication description. 
    int quantity_in_stock; // Quantity in stock.
    Date expiry_date; // Expiry date of the medicine.
    string barcode; // Medication barcode.

    // Economical attributes
    double retail_price; // Price in retail in JOD.
    double wholesale_price; // Price to buy medicine in JOD.
    double total_sales; // Total sales from specific medicine object.
    double total_profit; // Total profit from specific medicine object.

    // If the object is initialized with valid values, and not the default values.
    // For sorting purposes when we want to remove a medicine, we know which medicine was actively deleted when its
    // active value is set to false.
    bool active;

public:
    //Default Constructor:
    Medication();

    static void setSystemType(const int& system_type);

    // ID Getter
    long getID() const;

    //Name Setter & Getter:
    bool setName(string Medication_Name);
    string getName() const;

    //Description Setter & Getter:
    bool setDescription(string Description);
    string getDescription() const;

    // Retail Price Setter & Getter
    bool setRetailPrice(string retail_price);
    double getRetailPrice() const;

    // Production Price Setter & Getter
    bool setWholesalePrice(string wholesale_price);
    double getWholesalePrice() const;

    // Quantity in stock setter & getter:
    bool setQuantityInStock(string quantity_in_stock);
    int getQuantityInStock() const;

    // Date Setter & Getter
    bool setExpiryDate(const Date& expiry_date);
    Date& getExpiryDate();

    // Barcode setter & getter.
    bool setBarcode(string Barcode);
    string getBarcode() const;

    //print function:
    virtual void printInfo() const;

    // Purchase mechanic.
    void purchaseMedicine(int quantity);

    // Total Sales & total profit getter & setter.

    double getTotalProfit() const;
    void setTotalProfit(double choice);

    double getTotalSales() const;
    void setTotalSales(double choice);

    // Activity functions.
    bool isActive() const;
    void activate();
    void deactivate();

};

#endif