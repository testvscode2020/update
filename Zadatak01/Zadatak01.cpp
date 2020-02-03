#include <iostream>

#include "Http.h";
using namespace std;

/*
	Kreirajte tip podataka koji æe predstavljati HTTP klijenta i svojim korisnicima omoguæavati dohvaæanje HTTP sadržaja. 
	Želite korisnicima omoguæiti da pri izradi objekta mogu zadati samo URL (pa se podrazumijeva port 80) ili i URL i port. 
	Pružite korisnicima metode get i post bez parametara koje vraæaju neki sluèajni string od 10 znakova. 
	Iskoristite tip podataka za dohvat podataka POST-om s adrese https://www.bla.com i porta 443. 
*/

int main()
{
	Http http("https://www.bla.com");

	cout << http.post() << endl;
	cout << http.get() << endl;
	cout << http.get_config() << endl;
}