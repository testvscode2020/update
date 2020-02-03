#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Napišite program koji u mainu učitava naziv 
datoteke od korisnika, a zatim u funkciji 
otvara datoteku te ispisuje njen sadržaj. 
Što god da se dogodi, program se ne smije 
srušiti! Koristite ili tradicionalni ili 
moderni način upravljanja pogreškama.
*/

void read_file(const string &fname) 
{
	ifstream in(fname);
	if (!in) 
	{
		throw exception("Nije moguce pristupiti datoteci");
	}
	string line;
	while (getline(in, line)) 
	{
		cout << line << endl;
	}
	in.close();
}


int main() 
{
	string fname;
	cout << "Unesite naziv datoteke:";
	getline(cin, fname);

	try
	{
		read_file(fname);
	}
	catch (const exception &e)
	{
		cout << "Pogreska:" << e.what() << endl;
		return 1;
	}

	return 0;
}