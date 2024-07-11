#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
    int zi;
    int luna;
    int an;

    public:
        Date();
        ~Date();

        Date(string);

        void afisare();

};

#endif // DATE_H
