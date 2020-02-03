#include <iostream>
#include "merge_sort.h"

using namespace std;

void merge(Pravokutnik* poljea, int na, Pravokutnik* poljeb, int nb) {
	Pravokutnik* poljec = new Pravokutnik[na + nb];

	int ia = 0, ib = 0;
	for (int ic = 0; ic < na + nb; ic++) {
		if (ia == na) { // Ispraznili smo polje a.
			poljec[ic] = poljeb[ib++];
			continue;
		}
		if (ib == nb) { // Ispraznili smo polje b.
			poljec[ic] = poljea[ia++];
			continue;
		}

		if (poljea[ia].getPovrisna() < poljeb[ib].getPovrisna()) {
			poljec[ic] = poljea[ia++];
		}
		else {
			poljec[ic] = poljeb[ib++];
		}
	}

	for (int i = 0; i < na + nb; i++) {
		poljea[i] = poljec[i];
	}

	delete[] poljec;
}

void merge_sort(Pravokutnik data[], int from, int to) {
	if (from == to) { // Uvjet zaustavljanja.
		return;
	}

	int mid = (from + to) / 2;
	merge_sort(data, from, mid);
	merge_sort(data, mid + 1, to);

	merge(data + from, mid - from + 1, data + mid + 1, to - mid);
}

void merge_sort(Pravokutnik data[], int n) {
	merge_sort(data, 0, n - 1);
}