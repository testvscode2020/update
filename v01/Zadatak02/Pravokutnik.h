#pragma once
#include <string>

using namespace std;

class Pravokutnik
{
public:
	//obzirom da imamo polje, moramo imati defatult konstruktor
	//koji ne prima parametre - on implicitno postoji!
	//zato radimo metode za inicijalizaciju vrijednosti 
	void set_sirina(double sirina);
	void set_visina(double visina);
	double povrsina();
	string to_string();
private:
	double sirina;
	double visina;
};

