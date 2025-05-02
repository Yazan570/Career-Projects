#include "Perscription.h"

#include <ctime>
#include <iostream>

using namespace std;

Perscription::Perscription()
{
    this->approval_date = Date();
    fda_number = 0;
}

void Perscription::setApprovalDate(Date approval_date)
{
    this->approval_date = approval_date;
}

const Date& Perscription::getApprovalDate() const
{
    return approval_date;
}


int Perscription::getFdaNumber()
{
    return fda_number;
}

void Perscription::setFdaNumber(int fda_number)
{
    this->fda_number = fda_number;
}

void Perscription::printInfo() const
{
    this->Medication::printInfo();
    cout << "FDA Number: " << fda_number << endl;
    cout << "Approval Date: ";
    approval_date.printDateInfo();
}