#include <iostream>
#include "Osoba.h"

using namespace std;

/*
Definirati novi tip podataka za čuvanje imena, prezimena i OIB-a osobe uz sljedeće uvjete:
•Nije dopušteno kreirati osobu bez imena i prezimena
•Pri kreiranju osobe upis OIB-a je opcionalan
•Na tipu postoji metoda koja vraća tekst u formatu “prezime, ime (oib)”
•Na tipu postoji metoda koja omogućuje naknadno upisivanje OIB-a
•* Na tipu postoji metoda koja iscrtava osobu:
Demonstrirajte rad novog tipa podataka iz main-a.
*/

int main() 
{
	Osoba o1("Miro", "Miric", 123);
	o1.set_oib(123);
	cout << o1.to_string() << endl;

	o1.draw();

	return 0;
}
