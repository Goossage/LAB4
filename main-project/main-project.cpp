#include <iostream>

using namespace std;


#include "structures.h"
#include "constants.h"
#include "file_reader.h"
#include "filter.h"



int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №9. Телефонные разговоры\n";
    cout << "Автор: Орех Игорь\n";
    cout << "Группа: 23ПИ1д\n";
    tell_subscribe* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size); 

        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->number << '\n';
            cout << subscriptions[i]->date.day << ' ';
            cout << subscriptions[i]->date.month << ' ';
            cout << subscriptions[i]->date.year << '\n';
            cout << subscriptions[i]->time_start.seconds << ' ';
            cout << subscriptions[i]->time_start.minuts << ' ';
            cout << subscriptions[i]->time_start.hours << '\n';
            cout << subscriptions[i]->time_duration.seconds << ' ';
            cout << subscriptions[i]->time_duration.minuts << ' ';
            cout << subscriptions[i]->time_duration.hours << '\n';
            if (subscriptions[i]->tarif == Tarifs::город)
                cout << "город";
            else if (subscriptions[i]->tarif == Tarifs::межгород)
                cout << "межгород";
            else if (subscriptions[i]->tarif == Tarifs::международный)
                cout << "международный";
            else if (subscriptions[i]->tarif == Tarifs::мобильный)
                cout << "мобильный";
            cout << '\n';
            cout << subscriptions[i]->cost << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
