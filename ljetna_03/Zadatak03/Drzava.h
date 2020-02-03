#pragma once
#include <string>
#include <vector>

using namespace std;

class Drzava
{
private:
	string naziv;
	vector<int> broj_znanstvenika;
public:
	Drzava(string naziv);
	void dodaj_broj_znanstvenika(int n);
	string get_naziv();
	double prosjecan_broj_znanstvenika();
};

