#include "Proizvod.h"
#include <sstream>

Proizvod::Proizvod(string sifra, string naziv, int broj) : Proizvod(sifra, naziv, broj, 12)
{
}

Proizvod::Proizvod(string sifra, string naziv, int broj, int rok)
{
	this->sifra = sifra;
	this->naziv = naziv;
	this->broj = broj;
	set_rok(rok);
}

void Proizvod::set_rok(int rok)
{
	this->rok = rok;
}

int Proizvod::get_broj()
{
	return broj;
}

string Proizvod::to_string()
{
	stringstream ss;
	ss << sifra << " - " << naziv << ", " << broj << ", " << rok;
	return ss.str();
}
