#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "IpAdresa.h"

/*
Učitajte IP adrese iz datoteke „ip_adrese.txt” u vektor te 
ispišite sve adrese klase C (vlsm-calc.net/ipclasses.php)
*/

using namespace std;

int convert(string &s) {
	stringstream converter(s);
	int n;
	converter >> n;
	return n;
}

void load_addresses(ifstream  &in, vector<IpAdresa> &addresses) {
	string line;
	int a, b, c, d;
	string temp;
	while (getline(in, line)) {
		stringstream ss(line);
		getline(ss, temp, '.');
		a = convert(temp);
		getline(ss, temp, '.');
		b = convert(temp);
		getline(ss, temp, '.');
		c = convert(temp);
		getline(ss, temp);
		d = convert(temp);

		addresses.emplace_back(a, b, c, d);
	}
}

void print(IpAdresa &address)
{
	cout << address.to_string() << " ";
}

void print_if_found(vector<IpAdresa> &addresses, char c) {
	for (auto it = addresses.begin(); it != addresses.end(); ++it) {
		if (it->which_class() == c) {
			cout << it->to_string() << endl;
		}
	}
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

	//Provjera da li je ucitano
	for_each(addresses.begin(), addresses.end(), print);
	cout << endl;

	//Pretraga
	char c = 'C';
	print_if_found(addresses, c);

	return 0;
}
