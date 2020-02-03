#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>
#include <list>
#include <forward_list>

/*
Izmjerite vrijeme potrebno za dodavanje 100000 random stringova od 30 slova,
za sljedeće scenarije:
•list – dodavanje na kraj
•list – dodavanje na početak
•forward_list – dodavanje na početak
Usporedite vrijeme u mikrosekundama.
*/

using namespace std;
using namespace std::chrono;

int generate_random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

string generate_random_string(int n) {
	stringstream ss;
	for (int i = 0; i < n; i++) {
		ss << (char)generate_random(97, 122);
	}
	return ss.str();
}

void measure_list_back(int n) {
	list<string> rijeci;
	auto begin = high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
		rijeci.push_back(generate_random_string(30));
	}
	auto end = high_resolution_clock::now();
	cout << "list - push back: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}

void measure_list_front(int n) {
	list<string> rijeci;
	auto begin = high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
		rijeci.push_front(generate_random_string(30));
	}
	auto end = high_resolution_clock::now();
	cout << "list - push front: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}

void measure_forward_list_front(int n) {
	forward_list<string> rijeci;
	auto begin = high_resolution_clock::now();
	for (int i = 0; i < n; i++) {
		rijeci.push_front(generate_random_string(30));
	}
	auto end = high_resolution_clock::now();
	cout << "forward_list - push front: " << duration_cast<microseconds>(end - begin).count() << " us" << endl;
}

int main() {
	srand(time(nullptr));
	
	int n = 100000;

	measure_list_back(n);
	measure_list_front(n);
	measure_forward_list_front(n);
}