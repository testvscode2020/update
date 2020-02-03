#include <iostream>
#include "insertion_sort.h"
using namespace std;

void insertion_sort(Tocka data[], int n) {
	for (int i = 1; i < n; i++) { // Prvog preskaèemo.
		for (int j = i; j > 0; j--) {
			if (data[j - 1].distance() > data[j].distance()) {
				swap(data[j], data[j - 1]);
			}
		}
	}
}