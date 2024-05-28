#ifndef FILTERS_H
#define FILTERS_H

#include <iostream>
#include "structures.h"

tell_subscribe** filter (
    tell_subscribe* array[],
    int size,
    bool (*check)(tell_subscribe* element),
    int& result_size
    );

bool areMobile(
    tell_subscribe* element
    );

bool isNovember2021(
    tell_subscribe* element
);

void printArray(tell_subscribe* subscriptions[], int size);

#endif