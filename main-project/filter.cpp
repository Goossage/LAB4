#include "filter.h"

using namespace std;

tell_subscribe** filter(
    tell_subscribe* array[],
    int size,
    bool (*check)(tell_subscribe* element),
    int& result_size
) {
	tell_subscribe** result = new tell_subscribe * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
		if (check(array[i]))
			result[result_size++] = array[i];
	return result;
}

bool areMobile(
	tell_subscribe* element
) {
	return element->tarif == Tarifs::���������;
}

bool isNovember2021(
	tell_subscribe* element
) {
	return element->date.month == 10 && element->date.year == 21;
}

void printArray(tell_subscribe* subscriptions[], int size)
{
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
        if (subscriptions[i]->tarif == Tarifs::�����)
            cout << "�����";
        else if (subscriptions[i]->tarif == Tarifs::��������)
            cout << "��������";
        else if (subscriptions[i]->tarif == Tarifs::�������������)
            cout << "�������������";
        else if (subscriptions[i]->tarif == Tarifs::���������)
            cout << "���������";
        cout << '\n';
        cout << subscriptions[i]->cost << '\n';
        cout << '\n';
    }
}