// ���������� ������������� ���������� �� C++
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





// ��������� ��� �������������� � �������� ���� ��������� � �������� ����� i, ��� ��������
// �������� � arr[]. n - ������ ����

void heapify(tell_subscribe* arr[], int n, int i, bool (*check)(tell_subscribe* el1, tell_subscribe* el2))
{
    int largest = i;
    // �������������� ���������� ������� ��� ������
    int l = 2 * i + 1; // ����� = 2*i + 1
    int r = 2 * i + 2; // ������ = 2*i + 2

    // ���� ����� �������� ������� ������ �����
    if (l < n && check(arr[l], arr[largest]))
        largest = l;

    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (r < n && check(arr[r], arr[largest]))
        largest = r;

    // ���� ����� ������� ������� �� ������
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // ���������� ����������� � �������� ���� ���������� ���������
        heapify(arr, n, largest, check);
    }
}

// �������� �������, ����������� ������������� ����������
void heapSort(tell_subscribe* arr[], int n, bool (*check)(tell_subscribe* el1, tell_subscribe* el2))
{
    // ���������� ���� (�������������� ������)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, check);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i >= 0; i--)
    {
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        // �������� ��������� heapify �� ����������� ����
        heapify(arr, i, 0, check);
    }
}


