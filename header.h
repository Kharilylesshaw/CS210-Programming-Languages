#ifndef HEADER_H
#define HEADER_H

#include <string>

// Function declarations

/**
* Converts a number to a two digit string
* @param n the number to convert
* @return a string representation of the number, with leading zero if neccessary
*/
std::string twoDigitString(unsigned int n);

/*Creates a string of n characters
* @param n the number of characters
* @param c the character to repeat
* @return a string of n repeated characters
*/
std::string nCharString(size_t n, char c);

/*Formats time in 24 hour format
* @param h hours (0-23)
* @param m minutes (0-59)
* @param s seconds (0-59)
* @return a string representing the time in 24 hour format
*/
std::string formatTime24(unsigned int h, unsigned int m, unsigned int s);

/*Formats time in 12 hour format
* @param h hours (0-23)
* @param m minutes (0-59)
* @param s seconds (0-59)
* @return a string representing the time in 12 hour format
*/
std::string formatTime12(unsigned int h, unsigned int m, unsigned int s);

/*Prints a menu with options
* @param strings array of menu option strings
* @param numStrings number if menu options
* @param width- width of the menu
*/
void printMenu(const char* strings[], unsigned int numStrings, unsigned char width);

/*Gets a menu choice from the user
* @param maxChoice the maximum valid menu choice
* @return the user's choice (1 to maxChoice)
*/
unsigned int getMenuChoice(unsigned int maxChoice);

/*Displays the clock in both 12 hour and 24 hour formats
* @param h hours (0-23)
* @param m minutes (0-59)
* @param s seconds (0-59)
*/
void displayClocks(unsigned int h, unsigned int m, unsigned int s);

void addOneHour(); //Adds an hour to the current time 
void addOneMinute(); //Adds a minute to the current time
void addOneSecond(); //Adds a second to the current time
void mainMenu(); //The main menu function. Displays the menu and handles user choices
void getInitialTime(); //Gets the initial time from the user



//Stub functions for time management

/*Gets the current hour
* @return the current hour (0-23)
*/
unsigned int getHour();

/*Gets the current minute
* @return the current minute (0-59)
*/
unsigned int getMinute();

/*Gets the current second
* @return the current second
*/
unsigned int getSecond();

/*Sets the current hour
* @param h the hour set (0-23)
*/
void setHour(unsigned int h);

/*Sets the current minute
* @param m the minute is set (0-59)
*/
void setMinute(unsigned int m);

/*Sets the current second
* @param s the second is set (0-59)
*/
void setSecond(unsigned int s);

#endif // HEADER_H