#include <iostream>
#include "quick_sort.h"
using namespace std;

void quick_sort(int* data, int left, int right) {
	if (right <= left) {
		return;
	}

	int& pivot = data[left];
	int i = left + 1;
	int j = right;
	
	while (i <= j && i <= right && j > left) {
		// Pomièemo i u desno dok ne naðemo veæi element.
		while (data[i] <= pivot && i <= right) {
			i++;
		}

		// Pomièemo j u lijevo dok ne naðemo manji ili jednak element.
		while (data[j] > pivot && j > left) {
			j--;
		}

		// Ako smo našli oba elementa, zamijenimo ih.
		if (i < j) {
			swap(data[i], data[j]);
		}
	}

	swap(pivot, data[j]);
	quick_sort(data, left, j - 1);
	quick_sort(data, j + 1, right);
}

void quick_sort(int* data, int n) {
	quick_sort(data, 0, n - 1);
}