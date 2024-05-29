#include "processing.h"


double process(tell_subscribe* subscriptions[], int size) {
	int S = 0;
	for (int i = 0; i < size; i++)
		S += subscriptions[i]->cost;
	return (double)S / size;
}