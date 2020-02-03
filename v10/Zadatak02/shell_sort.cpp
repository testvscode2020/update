#include <iostream>
#include "shell_sort.h"
using namespace std;

void shell_sort(int data[], int n) {
	for (int step = n / 2; step > 0; step = step / 2) {
		for (int i = step; i < n; i++) { // Izrada potpolja
			for (int j = i - step; j >= 0; j -= step) { // Insertion na potpolju
				if (data[j] > data[j + step]) {
					swap(data[j], data[j + step]);
				}
			}
		}
	}
}