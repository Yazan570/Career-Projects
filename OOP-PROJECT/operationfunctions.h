#ifndef OPERATION_FUNCTIONS_H_
#define OPERATION_FUNCTIONS_H_

#include "Pharmacy.h"

void medicineOperation(const int system_type, Pharmacy& pharmacy, const int choice);

void customerOperation(const int system_type, Pharmacy& pharmacy, const int choice);

void purchaseOperation(const int system_type, Pharmacy& pharmacy, const int choice);


#endif // !OPERATION_FUNCTIONS_H_