#pragma once
#include <string>

using namespace std;

class Proizvod
{
private:
	string sifra;
	string naziv;
	int broj;
	int rok;
public:
	Proizvod(string sifra, string naziv, int broj);
	Proizvod(string sifra, string naziv, int broj, int rok);
	void set_rok(int rok);
	int get_broj();
	string to_string();
};

