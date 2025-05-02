#include "validationfunctions.h"

#include <string>

using namespace std;

bool isNumber(const char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }

    return false;
}

bool isNumberOrDot(const char c)
{
    if ((c >= '0' && c <= '9') || c == '.')
    {
        return true;
    }

    return false;
}



bool isValidDouble(const string& string_to_check)
{
    // Dot counter to count the number of dots in the string for weird input cases.
    int dot_counter = 0;
    for (int i = 0; i < string_to_check.length(); i++)
    {
        // If the first symbol is a dot.
        // or if any symbol is neither a symbol or dot.
        // or if more than one dot is in the input.
        // or if the last symbol is a dot
        // This also implicitly makes sure the number is non-negative.
        if (string_to_check[0] == '.'
            || (!isNumberOrDot(string_to_check[i]))
            || dot_counter > 1
            || string_to_check[string_to_check.length() - 1] == '.')
        {
            return false;
        }

        // Counting the dots in the string.
        if (string_to_check[i] == '.')
        {
            dot_counter++;
        }
    }

    return true;
}
