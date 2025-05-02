#ifndef INTERFACE_FUNCTIONS_H_
#define INTERFACE_FUNCTIONS_H_

// Functions for the sake of organizing the interface.
void listOptions(const int option);
void getOption(const int mode, int& input, const int system_type);
void clearScreen(const int systemtype);
void continueDelay();
void clearStream();

#endif