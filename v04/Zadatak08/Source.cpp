#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "IpAdresa.h"

/*
Učitajte sve IP adrese iz datoteke „ip_adrese.txt” u vektor te 
nacrtajte histogram kojim prikazujete koliko ima adrese koje klase, primjerice:
Klasa A: ## (2)
Klasa B: # (1)
Klasa C: ### (3)
Klasa D: # (1)
Klasa E: (0)
*/

using namespace std;

int to_int(string &s, stringstream &converter) {
	converter.clear();
	converter << s;
	int n;
	converter >> n;
	return n;
}

void load_addresses(ifstream  &in, vector<IpAdresa> &addresses) {
	string line;
	stringstream converter;
	int a, b, c, d;
	string temp;
	while (getline(in, line)) {
		stringstream ss(line);
		getline(ss, temp, '.');
		a = to_int(temp, converter);
		getline(ss, temp, '.');
		b = to_int(temp, converter);
		getline(ss, temp, '.');
		c = to_int(temp, converter);
		getline(ss, temp);	
		d = to_int(temp, converter);

		addresses.emplace_back(a, b, c, d);
	}
}

int count_found(vector<IpAdresa> &contacts, char c) {
	int counter = 0;
	for (auto it = contacts.begin(); it != contacts.end(); ++it) {
		if (it->which_class() == c) {
			counter++;
		}
	}
	return counter;
}

void paint(char c, int n) {
	cout << "Klasa " << c << ": ";
	for (int i = 0; i < n; i++) {
		cout << "#";
	}
	cout << " (" << n << ")" << endl;
}

int main() {

	ifstream in("ip_adrese.txt");
	if (!in) {
		cout << "Greska pri otvaranju ip_adrese.txt" << endl;
		return 1;
	}
	vector<IpAdresa> addresses;
	load_addresses(in, addresses);
	in.close();

	char classes[] = { 'A', 'B', 'C', 'D', 'E' };
	for (unsigned i = 0; i < sizeof(classes) / sizeof(char); i++) {
		paint(classes[i], count_found(addresses, classes[i]));
	}

	return 0;
}
