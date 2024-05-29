#include "processing.h"


double process(tell_subscribe* subscriptions[], int size) {
	int S = 0;
	tell_subscribe* iter = *subscriptions;
	tell_subscribe* end = *subscriptions + size;
	for (iter; iter <= end; iter++)
		S += iter->cost;
	return (double)S / size;
}