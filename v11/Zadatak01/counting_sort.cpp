#include <iostream>
#include "counting_sort.h"
using namespace std;

int max_element(int* data, int n) {
	int max = data[0];
	for (int i = 1; i < n; i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	return max;
}

int* napravi_polje(int n) {
	int* polje = new int[n];
	for (int i = 0; i < n; i++) {
		polje[i] = 0;
	}
	return polje;
}

void prebroji_ponavljanje(int* data, int n, int* sljedeci_indeks) {
	int element;
	for (int i = 0; i < n; i++) {
		element = data[i];
		sljedeci_indeks[element]++;
	}
}

void pretvori_ponavljanje_u_indekse(int* sljedeci_indeks, int n) {
	sljedeci_indeks[0]--;
	for (int i = 1; i < n; i++) {
		sljedeci_indeks[i] += sljedeci_indeks[i - 1];
	}
}

void prepisi_u_sortirano(int* data, int n, int* sljedeci_indeks, int* sortirano) {
	for (int i = n - 1; i >= 0; i--) {
		int element = data[i];
		int stavi_na_indeks = sljedeci_indeks[element]--;
		sortirano[stavi_na_indeks] = element;
	}
}

void prekopiraj(int* sortirano, int n, int* data) {
	for (int i = 0; i < n; i++) {
		data[i] = sortirano[i];
	}
}

void counting_sort(int* data, int n) {
	// Pronalazak najveæeg elementa.
	int max = max_element(data, n);
	
	// Priprema polja za èuvanje podataka o broju ponavljanja i indeksima na koje doðu sortirani elementi.
	int* sljedeci_indeks = napravi_polje(max + 1);

	// Pomoæno polje koje æe sadržavati sortirane podatke.
	int* sortirano = napravi_polje(n);

	// Brojanje ponavljanja.
	prebroji_ponavljanje(data, n, sljedeci_indeks);

	// Pretvaranje broja pojavljivanja u indekse sortiranog polja. Trenutno nam sljedeci_indeks sadržava BROJ PONAVLJANJA, a nakon petlje æe sadržavati INDEKSE u sortiranom polju.
	pretvori_ponavljanje_u_indekse(sljedeci_indeks, max + 1);

	// Smještanje elemenata u sortirano polje na izraèunate indekse.
	prepisi_u_sortirano(data, n, sljedeci_indeks, sortirano);
	
	// Kopiranje iz pomoænog u glavno.
	prekopiraj(sortirano, n, data);
	
	delete[] sljedeci_indeks;
	delete[] sortirano;
}
