/********
 Author: Delwin Rosa
 Program: Money class - program assignment #1
 Due Date: 02/03/2020
 Purpose: Display change in different formats
 ********/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <locale>

using namespace std;
class Money
{
private:
    double total, temp, pennyCheck, purchase, change, temp2;
    int hundreds, tens, fives, ones, quarters, dimes, nickels, pennies;
    int hundreds2, tens2, fives2, ones2, quarters2, dimes2, nickels2, pennies2;
public:
    string toString();
    string toCurrency(double amount);
    string processChange();
    string processFloat();
    string processCheck();
    string processChangeFloat();
    string processChangeChange();
};
#endif
