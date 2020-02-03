#include <iostream>
#include "selection_sort.h"
using namespace std;

void selection_sort(pravokutnik data[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j].a * data[j].b < data[min_index].a * data[min_index].b) {
				min_index = j;
			}
		}
		swap(data[min_index], data[i]);
	}
}