#include <iostream>
#include "Http.h"

/*
Kreirajte tip podataka koji će predstavljati HTTP klijenta i 
svojim korisnicima omogućavati dohvaćanje HTTP sadržaja. 
Želite korisnicima omogućiti da pri izradi objekta mogu 
zadati samo URL (pa se podrazumijeva port 80) ili i URL i port. 
Pružite korisnicima metode get i post bez parametara koje vraćaju 
neki slučajni string od 10 znakova. Iskoristite tip podataka 
za dohvat podataka POST-om s adrese https://www.bla.com i porta 443.
*/

using namespace std;

int main()
{
	Http http("https://www.bla.com", 443);
	cout << http.to_string() << endl;
	http.set_port(80);
	cout << http.to_string() << endl;

	cout << "get:\t" << http.get() << endl;
	cout << "post:\t" << http.post() << endl;

	return 0;
}