#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <string>
#include "constants.h"


struct Date
{
    int day;
    int month;
    int year;
};






struct Time
{
    int hours;
    int minuts;
    int seconds;

    operator int() const {
        return this->hours * 3600 + this->minuts * 60 + this->seconds;
    }
};



enum Tarifs {
    город, 
    межгород, 
    международный, 
    мобильный
};

struct tell_subscribe {
    char number[MAX_NUMBER_SIZE];
    Date date;
    Time time_start, time_duration;
    Tarifs tarif;
    double cost;
};

#endif