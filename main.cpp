#include <iostream>
#include <string>
#include <cstring> //allows use of strlen()
#include "header.h" //Includes the header file

using namespace std;

//Global time variables
unsigned int hour = 0;
unsigned int minute = 0;
unsigned int second = 0;

//Implementations of the declared functions


/*Converts a number to a two digit string
* @param n the number to convert
* @return a string representation of the number, with leading zero if neccessary
*/
std::string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    }
    else {
        return to_string(n);
    }
}

/*Creates a string of n characters
* @param n the number of characters
* @param c the character to repeat
* @return a string of n repeated characters
*/
std::string nCharString(size_t n, char c) {
    return string(n, c);
}

/*Formats time in 24 hour format
* @param h hours (0-23)
* @param m minutes (0-59)
* @param s seconds (0-59)
* @return a string representing the time in 24 hour format
*/
std::string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

/*Formats time in 12 hour format
* @param h hours (0-23)
* @param m minutes (0-59)
* @param s seconds (0-59)
* @return a string representing the time in 12 hour format
*/
std::string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string period = (h >= 12) ? " PM" : " AM";
    h = (h % 12 == 0) ? 12 : h % 12;
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + period;
}

/*Prints a menu with options
* @param strings array of menu option strings
* @param numStrings number if menu options
* @param width- width of the menu
*/
void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width, '*') << endl;
    for (unsigned int i = 0; i < numStrings; ++i) {
        cout << "* " << (i + 1) << " - " << strings[i];
        cout << nCharString(width - 6 - to_string(i + 1).length() - strlen(strings[i]), ' ') << "*" << endl;
    }
    cout << nCharString(width, '*') << endl;
}

/*Gets a menu choice from the user
* @param maxChoice the maximum valid menu choice
* @return the user's choice (1 to maxChoice)
*/
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    while (true) {
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            break;
        }
    }
    return choice;
}

/*Displays the clock in both 12 hour and 24 hour formats
* @param h hours (0-23)
* @param m minutes (0-59)
* @param s seconds (0-59)
*/
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    //Line 1: 26 stars, 3 spaces, 26 stars
    cout << nCharString(26, '*') << "   " << nCharString(26, '*') << endl;

    //Line 2: 1 star, 5 spaces, "12-HOUR CLOCK", 6 spaces, 1 star, 3 spaces, 1 star, 5 spaces, "24-HOUR CLOCK", 6 spaces, 1 star
    cout << "*     12-HOUR CLOCK      *   *     24-HOUR CLOCK      *" << endl;

    //Line 3: 26 stars, 3 spaces, 26 stars
    cout << nCharString(26, '*') << "   " << nCharString(26, '*') << endl;

    //Line 4: 1 star, 7 spaces, formatted time in 12-hour clock format, 6 spaces, 1 star, 3 spaces, 1 star, 7 spaces, formatted time in 24-hour clock format, 9 spaces, 1 star
    cout << "*       " << formatTime12(h, m, s) << "      *   *       " << formatTime24(h, m, s) << "         *" << endl;

    //Line 5: 26 stars, 3 spaces, 26 stars
    cout << nCharString(26, '*') << "   " << nCharString(26, '*') << endl;
}

void addOneHour() { //Adds an hour to the current time 
    unsigned int h = getHour();
    if (h < 23) {
        setHour(h + 1);
    }
    else {
        setHour(0);
    }
}

void addOneMinute() { //Adds a minute to the current time
    unsigned int m = getMinute();
    if (m < 59) {
        setMinute(m + 1);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}

void addOneSecond() { //Adds a second to the current time
    unsigned int s = getSecond();
    if (s < 59) {
        setSecond(s + 1);
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}

void getInitialTime() { //Gets the initial time from the user
    unsigned int h, m, s;
    //Loop for validating hour input
    while (true) {
        cout << "Enter initial hour (0-23): ";
        cin >> h;
        if (h >= 0 && h <= 23) break; //Valid input, break out of the loop
        cout << "Invalid hour. Please enter a value between 0 and 23." << endl;
    }
    //Loop for validating minute input
    while (true) {
        cout << "Enter initial minute (0-59): ";
        cin >> m;
        if (m >= 0 && m <= 59) break; //Valid input, break out of the loop
        cout << "Invalid minute. Please enter a value between 0 and 59." << endl;
    }
    //Loop for validating second input
    while (true) {
        cout << "Enter initial second (0-59): ";
        cin >> s;
        if (s >= 0 && s <= 59) break; //Valid input, break out of the loop
        cout << "Invalid second. Please enter a value between 0 and 59." << endl;
    }
    //Set the validated initial time
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void mainMenu() { //The main menu function. Displays the menu and handles user choices
    const char* menuItems[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
    unsigned int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
    unsigned char menuWidth = 26;

    getInitialTime(); //Get initial time from user

    while (true) {
        //Get current values
        unsigned int h = getHour(), m = getMinute(), s = getSecond();
        displayClocks(h, m, s); //Display the current time
        printMenu(menuItems, menuSize, menuWidth); //Display the menu
        unsigned int choice = getMenuChoice(menuSize); //Get the user's menu choice

        //Executes the correct action based on user's choice
        switch (choice) {
        case 1: addOneHour(); break;
        case 2: addOneMinute(); break;
        case 3: addOneSecond(); break;
        case 4: return; //Exits the program
        }
    }
}

//Implement stub functions for time management

/*Gets the current hour
* @return the current hour (0-23)
*/
unsigned int getHour() {
    return hour;
}

/*Gets the current minute
* @return the current minute (0-59)
*/
unsigned int getMinute() {
    return minute;
}

/*Gets the current second
* @return the current second
*/
unsigned int getSecond() {
    return second;
}

/*Sets the current hour
* @param h the hour set (0-23)
*/
void setHour(unsigned int h) {
    hour = h;
}

/*Sets the current minute
* @param m the minute is set (0-59)
*/
void setMinute(unsigned int m) {
    minute = m;
}

/*Sets the current second
* @param s the second is set (0-59)
*/
void setSecond(unsigned int s) {
    second = s;
}


int main() { //The main function
    mainMenu(); //Starts the main menu
    return 0;
}
//Coded by: Khari Lyles