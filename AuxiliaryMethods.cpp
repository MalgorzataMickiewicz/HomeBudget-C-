#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

int AuxiliaryMethods::checkActualDate() {

    string actualDateInString = "";
    int actualDateInInt = 0;

    SYSTEMTIME st;
    GetSystemTime(&st);

    ostringstream yearInString;
    yearInString << st.wYear;
    string yearInString2 = yearInString.str();

    ostringstream monthInString;
    monthInString << st.wMonth;
    string monthInString2 = monthInString.str();

    ostringstream dayInString;
    dayInString << st.wDay;
    string dayInString2 = dayInString.str();


    if (dayInString2.length() < 2) {
        dayInString2.insert(0,"0");
    }

    if (monthInString2.length() < 2) {
        monthInString2.insert(0,"0");
    }

    actualDateInString.insert(0,yearInString2);
    actualDateInString.insert(4,monthInString2);
    actualDateInString.insert(6,dayInString2);

    istringstream changeDateFormat(actualDateInString);
    changeDateFormat >> actualDateInInt;

    return actualDateInInt;
}

int AuxiliaryMethods::conversionStringToIntDate(string dateInString) {

    string shortDateInString = "";
    string yearInString = "";
    string monthInString = "";
    string dayInString = "";
    int dateInInt = 0;
    int dayInInt = 0;
    int monthInInt = 0;
    int yearInInt = 0;

    if(dateInString.length() != 10) {
        cout << "Wprowadziles bledna date!" << endl;
        return 0;
    }
    dayInString = dateInString.substr(8,2);
    monthInString = dateInString.substr(5,2);
    yearInString = dateInString.substr(0,4);

    shortDateInString.insert(0,yearInString);
    shortDateInString.insert(4,monthInString);
    shortDateInString.insert(6,dayInString);

    istringstream changeDateFormat(shortDateInString);
    changeDateFormat >> dateInInt;

    istringstream changeDayFormat(dayInString);
    changeDayFormat >> dayInInt;

    istringstream changeMonthFormat(monthInString);
    changeMonthFormat >> monthInInt;

    istringstream changeYearFormat(yearInString);
    changeYearFormat >> yearInInt;

    if(checkMonth(monthInInt, yearInInt, dayInInt) == false) {
        cout << "Podales bledna date" << endl;
        return 0;
    }
    if(checkYear(monthInInt, yearInInt, dayInInt) == false) {
        cout << "Wprowadziles zbyt stara date! Zbieramy tylko dane z XI wieku" << endl;
        return 0;
    }
    return dateInInt;
}

bool AuxiliaryMethods::checkMonth(int month, int year, int day) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if(day < 31 && day > 0) {
            return true;
        } else {
            return false;
        }
    } else if (month == 2) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (leapyear == 0) {
            if(day < 29 && day > 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if(day < 30 && day > 0) {
                return true;
            } else {
                return false;
            }
        }
    } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

        if(day < 32 && day > 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool AuxiliaryMethods::checkYear(int month, int year, int day) {
    if(year < 2000) {
        return false;
    } else {
        return true;
    }
}

float AuxiliaryMethods::conversionStringToFloat(string valueInString) {
    string comma = ",";
    string dot = ".";
    string shortValueInString = "";
    int lengthOfString = 0;

    int placeOfComma = valueInString.find(comma);
    if(placeOfComma != string::npos){
        valueInString.replace(placeOfComma,1,".");
        lengthOfString = valueInString.length();
        shortValueInString = valueInString.substr(0,placeOfComma+3);
    }
    else{
        int placeOfDot = valueInString.find(dot);
        lengthOfString = valueInString.length();
        shortValueInString = valueInString.substr(0,placeOfDot+3);
    }

    float valueInFloat = atof(shortValueInString.c_str());
    return valueInFloat;
}

int AuxiliaryMethods::conversionStringToInt(string valueInString) {

    int valueInInt = atoi(valueInString.c_str());
    return valueInInt;
}

string AuxiliaryMethods::conversionIntToString(int numberInInt) {
    ostringstream ss;
    ss << numberInInt;
    string numberInString = ss.str();
    return numberInString;
}

string AuxiliaryMethods::conversionFloatToString(float numberInFloat){
    stringstream ss;
    ss << numberInFloat;
    string s(ss.str());
    return s;
}

string AuxiliaryMethods::conversionIntToStringSeparatedDash(int dateInInt) {

    string dateSeparatedDash = "";

    ostringstream changeDateFormat;
    changeDateFormat << dateInInt;
    string dateInString = changeDateFormat.str();

    dateSeparatedDash = dateInString.substr(0,4);
    dateSeparatedDash.insert(4,"-");
    dateSeparatedDash.insert(5,dateInString.substr(4,2));
    dateSeparatedDash.insert(7,"-");
    dateSeparatedDash.insert(8,dateInString.substr(6,2));

    return dateSeparatedDash;
}
