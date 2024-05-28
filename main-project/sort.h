#ifndef SORT_H
#define SORT_H
#include "structures.h"


bool _by_duration_desc(tell_subscribe* el1, tell_subscribe* el2);
bool _by_phone_asc_and_cost_desc(tell_subscribe* el1, tell_subscribe* el2);

void heapSort(tell_subscribe* arr[], int n, bool (*check)(tell_subscribe* el1, tell_subscribe* el2));
void qsort(tell_subscribe* a[], int first, int last, bool (*check)(tell_subscribe* el1, tell_subscribe* el2));

#endif