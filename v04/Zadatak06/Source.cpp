#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Kontakt.h"

/*
Učitajte sve kontakte iz datoteke „kontakti.txt” u vektor. 
Omogućite korisniku da upiše znak, a nakon toga mu prikažete 
sve kontakte čije ime ili prezime započinje traženim znakom.
*/

using namespace std;

void load_contacts(ifstream  &in, vector<Kontakt> &contacts) {
	string line;
	string ime;
	string prezime;
	while (getline(in, line)) {
		stringstream ss(line);
		getline(ss, ime, ';');
		getline(ss, prezime);
		contacts.emplace_back(ime, prezime);
	}
}

void print_if_found(vector<Kontakt> &contacts, char query) {
	for (auto it = contacts.begin(); it != contacts.end(); ++it) {
		if (it->ime[0] == query || it->prezime[0] == query) {
			cout << it->ime << " " << it->prezime << endl;
		}
	}
}

int main() {

	ifstream in("kontakti.txt");
	if (!in) {
		cout << "Greska pri otvaranju kontakti.txt" << endl;
		return 1;
	}
	vector<Kontakt> contacts;
	load_contacts(in, contacts);
	in.close();

	// Pretraga
	char query;
	while (true) {
		cout << "Unesite prvo slovo imena ili prezimena (ili 0 za kraj): ";
		cin >> query;

		if (query == '0') {
			break;
		}
		print_if_found(contacts, query);
	}

	return 0;
}
