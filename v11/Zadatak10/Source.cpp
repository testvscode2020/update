#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Napišite program koji omogućuje pretraživanje datoteke puno_malih_brojeva1.txt 
na način da pitate korisnika koji broj želi tražiti, a onda mu vi ispišete ima 
li tog broja ili nema. Optimizirajte rješenje u svrhu pretraživanja.
*/

void load(ifstream& in, vector<int> &v)
{
	int n;
	while (in >> n) 
	{
		v.push_back(n);
	}
}

void search(vector<int> &v)
{
	bool dalje;
	int upit;
	do 
	{
		cout << "Upisite broj koji zelite traziti: ";
		cin >> upit;

		if (binary_search(v.begin(), v.end(), upit)) 
		{
			cout << "Broj " << upit << " postoji" << endl;
		}
		else 
		{
			cout << "Broj " << upit << " ne postoji" << endl;
		}

		cout << "Dalje (1=da, 0=ne): ";
		cin >> dalje;
	} while (dalje);
}

int main() 
{
	ifstream in("puno_malih_brojeva1.txt");
	if (!in)
	{
		cout << "Greska pri otvaranju datoteka" << endl;
		return 1;
	}

	vector<int> v;
	load(in, v);
	in.close();

	sort(v.begin(), v.end());

	search(v);

	return 0;
}