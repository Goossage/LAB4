// Реализация пирамидальной сортировки на C++
#include <iostream>
#include "sort.h"

using namespace std;


bool _by_duration_desc(tell_subscribe* el1, tell_subscribe* el2) {
    return el1->time_duration < el2->time_duration;
}
bool _by_phone_asc_and_cost_desc(tell_subscribe* el1, tell_subscribe* el2) {
    if (strcmp(el1->number, el2->number) == 0)
        return el1->cost < el2->cost;
    return strcmp(el1->number, el2->number) > 0;
}


void qsort(tell_subscribe* a[], int first, int last, bool (*check)(tell_subscribe* el1, tell_subscribe* el2))
{
    int _m = (last + first) / 2;
    tell_subscribe* p = a[_m];
    int i = first, j = last;

    do {
        while (check(a[i], p) and _m != i) i++;
        while (!check(a[j], p) and _m != j) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }

    } while (i <= j);

    if (j > first) qsort(a, first, j, check);
    if (last > i) qsort(a, i, last, check);
}





// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(tell_subscribe* arr[], int n, int i, bool (*check)(tell_subscribe* el1, tell_subscribe* el2))
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && check(arr[l], arr[largest]))
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && check(arr[r], arr[largest]))
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest, check);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(tell_subscribe* arr[], int n, bool (*check)(tell_subscribe* el1, tell_subscribe* el2))
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, check);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, check);
    }
}


