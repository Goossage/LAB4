#include <string>


struct Date
{
    int day;
    int month;
    int year;
};


struct Time
{
    int day;
    int month;
    int year;
};

enum Tarifs {
    город, 
    межгород, 
    международный, 
    мобильный
};

struct tell_subscribe {
    char* number;
    Date date;
    Time time;
    Tarifs tarif;
    double cost;
};