#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date()
{
    //ctor
}

Date::~Date()
{
    //dtor
}

Date::Date(string date)
{
    this->zi = stoi(date.substr(0,2));
    this->luna = stoi(date.substr(3,2));
    this->an = stoi(date.substr(6));
}

void Date::afisare()
{
    cout << this->zi << "-" << this->luna << "-" << this->an << endl;
}
