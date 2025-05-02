#define _CRT_SECURE_NO_WARNINGS
#include "OffTheShelf.h"

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

// Logic for getting the current date.
time_t now = time(0);
tm* ltm = localtime(&now);


OffTheShelf::OffTheShelf() : offer_ends(Date(to_string(ltm->tm_year + 1902), to_string(ltm->tm_mon + 1), to_string(ltm->tm_mday)))
{
    is_buy_one_get_one_free = false;
}

bool OffTheShelf::isBuyOneGetOneFree()
{
    return is_buy_one_get_one_free;
}

void OffTheShelf::setBuyOneGetOneFree(bool value)
{
    is_buy_one_get_one_free = value;
    if (is_buy_one_get_one_free)
    {
        offer_ends.setYear(to_string(stoi(offer_ends.getYear()) - 2));
        int new_month = ((stoi(offer_ends.getYear()) + 2) % 12) + 1;

        if ((stoi(offer_ends.getMonth()) + 3) > 12)
        {
            offer_ends.setYear(to_string(stoi(offer_ends.getYear()) + 1));
        }

        offer_ends.setMonth(to_string(new_month));
    }
}

const Date& OffTheShelf::getOfferEnds() const
{
    return offer_ends;
}

void OffTheShelf::printInfo() const
{
    this->Medication::printInfo();
    cout << "Buy One Get One Free: " << ((is_buy_one_get_one_free) ? "True" : "False") << endl;
    cout << "Offer End Date: ";
    offer_ends.printDateInfo();
}