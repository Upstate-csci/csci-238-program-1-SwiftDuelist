/********
 Author: Delwin Rosa
 Program: Money class - program assignment #1
 Due Date: 02/03/2020
 Purpose: Display change in different formats
 ********/
#include "Money.h"

// convert current currency values to a string
string Money::toString()
{

    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {

    stringstream ss;
    ss.imbue(locale(""));

    ss << showbase << put_money(amount*100);

    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    stringstream ss;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies;
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + ones + (static_cast<double>(quarters) * 0.25) + (static_cast<double>(dimes) * 0.10) + (static_cast<double>(nickels) * 0.05) + (static_cast<double>(pennies) * .01);
    ss << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies = $" << total << endl;
    return ss.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    stringstream ss;
    cin >> total;
    temp = total;
    hundreds = total / 100.0;
    total = total - (hundreds * 100.0);
    tens = total / 10.0;
    total = total - (tens * 10.0);
    fives = total / 5.0;
    total = total - (fives * 5.0);
    ones = total / 1.0;
    total = total - ones;
    quarters = total / 0.25;
    total = total - (quarters * 0.25);
    dimes = total / 0.100;
    total = total - (dimes * 0.100);
    nickels = total / 0.0500;
    total = total - (nickels * 0.0500);
    pennyCheck = total / 0.01000;
    pennies = total / 0.0100;
    total = total - (pennies * 0.0100);
    if(pennyCheck > pennies){
        pennies = pennies + 1;
    }
    ss << temp << " = " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies" << endl;
    return ss.str();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    stringstream ss;

    cin >> total;
    temp = total;
    ones = total / 1;
    total = total - ones;
    pennyCheck = total / 0.01000;
    pennies = total / 0.0100;
    total = total - (pennies * 0.0100);
    if(pennyCheck > pennies){
        pennies = pennies + 1;
    }
    ss << "Check for $" << temp << " = " << ones << " dollars and " << pennies << " cents" << endl;
    return ss.str();
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    stringstream ss;

    cin >> total >> purchase;
    change = total - purchase;
    temp = change;

    hundreds = change / 100.0;
    change = change - (hundreds * 100.0);
    tens = change / 10.0;
    change = change - (tens * 10.0);
    fives = change / 5.0;
    change = change - (fives * 5.0);
    ones = change / 1.0;
    change = change - ones;
    quarters = change / 0.25;
    change = change - (quarters * 0.25);
    dimes = change / 0.100;
    change = change - (dimes * 0.100);
    nickels = change / 0.0500;
    change = change - (nickels * 0.0500);
    pennyCheck = change / 0.01000;
    pennies = change / 0.0100;
    change = change - (pennies * 0.0100);
    if(pennyCheck > pennies){
        pennies = pennies + 1;
    }
    ss << "change back on $" << total <<" for purchase of $" << purchase << " is " << temp << " which is " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies " << endl;
    return ss.str();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    stringstream ss;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> pennies >> purchase;
    temp = hundreds * 100;
    temp = temp + (tens * 10);
    temp = temp + (fives *5);
    temp = temp + ones;
    temp = temp + (quarters * 0.25);
    temp = temp + (dimes * 0.10);
    temp = temp + (nickels * 0.05);
    temp = temp + (pennies * 0.0100);
    change = temp - purchase;
    temp2 = change;

    hundreds2 = change / 100.0;
    change = change - (hundreds2 * 100.0);
    tens2 = change / 10.0;
    change = change - (tens2 * 10.0);
    fives2 = change / 5.0;
    change = change - (fives2 * 5.0);
    ones2 = change / 1.0;
    change = change - ones2;
    quarters2 = change / 0.25;
    change = change - (quarters2 * 0.25);
    dimes2 = change / 0.100;
    change = change - (dimes2 * 0.100);
    nickels2 = change / 0.0500;
    change = change - (nickels2 * 0.0500);
    pennyCheck = change / 0.01000;
    pennies2 = change / 0.0100;
    change = change - (pennies2 * 0.0100);
    if(pennyCheck > pennies2){
        pennies2 = pennies2 + 1;
    }
    ss << "change back on " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << pennies << " pennies for purchase of $" << purchase << " is $" << temp2 << " which is " <<  hundreds2 << " hundreds " << tens2 << " tens " << fives2 << " fives " << ones2 << " ones " << quarters2 << " quarters " << dimes2 << " dimes " << nickels2 << " nickels " << pennies2 << " pennies" << endl;

    return ss.str();
}