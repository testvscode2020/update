#include <iostream>
#include "merge_sort.h"
using namespace std;

void merge(Racuni* poljea, int na, Racuni* poljeb, int nb) {
	Racuni* poljec = new Racuni[na + nb]; //isto kao i na dopunskoj

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

		if (poljea[ia].iznos < poljeb[ib].iznos) { // e sad se tu ne sjecam po cemu ga sortiras, mislim da je bilo po iznosu rastuce
			poljec[ic] = poljea[ia++];            // ako je po broju racuna samo ubacis umjesto iznosa
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

void merge_sort(Racuni data[], int from, int to) { //isto kao i na dopunskoj
	if (from == to) { // Uvjet zaustavljanja.
		return;
	}

	int mid = (from + to) / 2;
	merge_sort(data, from, mid);
	merge_sort(data, mid + 1, to);

	merge(data + from, mid - from + 1, data + mid + 1, to - mid);
}

void merge_sort(Racuni data[], int n) { //isto kao i na dopunskoj
	merge_sort(data, 0, n - 1);
}