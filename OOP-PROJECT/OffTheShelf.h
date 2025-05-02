#ifndef OFF_THE_SHELF_H_
#define OFF_THE_SHELF_H_

#include "Medication.h"
#include "Date.h"


using namespace std;

class OffTheShelf : public Medication
{
private:
    bool is_buy_one_get_one_free;
    Date offer_ends;

public:
    OffTheShelf();

    bool isBuyOneGetOneFree();
    void setBuyOneGetOneFree(bool value);

    const Date& getOfferEnds() const;

    virtual void printInfo() const;
};
#endif // !OFF_THE_SHELF_H_
