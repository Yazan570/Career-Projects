#ifndef VALIDATION_FUNCTIONS_H_
#define VALIDATION_FUNCTIONS_H_
#include <string>

using namespace std;

bool isNumber(const char c);
bool isNumberOrDot(const char c);
bool isValidDouble(const string& string_to_check);

#endif // !VALIDATION_FUNCTIONS_H_