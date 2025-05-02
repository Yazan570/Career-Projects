#ifndef PERSCRIPTION_H_
#define PERSCRIPTION_H_

#include "Medication.h"
#include "Date.h"

using namespace std;

class Perscription : public Medication
{
private:
    // FDA approval number.
    int fda_number;

    // The date of approval of the medicine.
    Date approval_date;

public:
    Perscription();
    Perscription(Perscription& arr);
    void setApprovalDate(Date approval_date);
    const Date& getApprovalDate() const;

    int getFdaNumber();
    void setFdaNumber(int fda_number);

    virtual void printInfo() const;
};

#endif // !PERSCRIPTION_H_
