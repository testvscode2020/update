#include <iostream>
#include <vector>
#include "shell_sort.h"
using namespace std;

void shell_sort(int data[], int n) {
	// Prvo generiramo sekvencu.
	vector<int> sequence;
	int h;
	int k = 1;
	while (true) {
		h = ceil((pow(9, k) - pow(4, k)) / (5 * pow(4, k - 1)));
		if (h < n) {
			sequence.push_back(h);
			k++;
		}
		else {
			break;
		}
	}

	// Sad koristimo elemente sekvence.
	for (int k = sequence.size() - 1; k >= 0; k--) {
		int step = sequence[k];
		cout << step << endl;
		for (int i = step; i < n; i++) { // Izrada potpolja
			for (int j = i - step; j >= 0; j -= step) { // Insertion na potpolju
				if (data[j] > data[j + step]) {
					swap(data[j], data[j + step]);
				}
			}
		}
	}
}