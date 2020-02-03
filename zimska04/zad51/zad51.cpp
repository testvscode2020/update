#include <iostream>
#include <string>
#include <map>

using namespace std;

int menu()
{
	cout << "0. izlaz" << endl;
	cout << "1. unos" << endl;
	cout << "2. izmjena" << endl;
	cout << "3. brisanje" << endl;
	cout << "4. ispis grada " << endl; //moramo samo napraviti
	cout << "5. ispis svih gradova " << endl; //moramo sami napraviti
	int odabir;
	cin >> odabir;
	return odabir;
}

void unos(map<int, string>& m)
{
	cout << "pobox:";
	int po;
	cin >> po;
	cin.ignore();

	if (m.find(po) == m.end()) //end iterator je prvi posje skupine koji ne pripada u skupinu
	{
		string naziv;
		cout << "naziv:";
		getline(cin, naziv);

		m.insert({ po,naziv });
	}
	else
	{
		cout << "duplikat" << endl;
	}
	//svinjarija je sto ako po vec postoji?
	//sta ako vec postoju u mapi vec sa kljucem
	//ctrl+k+s i baciti to sve na if+else
}

void izmjena(map<int, string>& m)
{
	cout << "pobox:";
	int po;
	cin >> po;
	cin.ignore();

	if (m.find(po) != m.end()) //!= on dosta postoji
	{
		string naziv;
		cout << "naziv:";
		getline(cin, naziv);

		m[po] = naziv; 
	}
	else
	{
		cout << "nema ga" << endl;
	}
}

void brisanje(map<int, string>& m)
{
	cout << "pobox:";
	int po;
	cin >> po;
	cin.ignore();

	if (m.find(po) != m.end()) //!= on dosta postoji
	{
		m.erase(po);
	}
	else
	{
		cout << "nema ga" << endl;
	}
}

void ispisi_grad(map<int, string>& m)
{
	cout << "pobox:";
	int po;
	cin >> po;
	cin.ignore();

	if (m.find(po) != m.end()) //!= on dosta postoji
	{
		cout << m[po] << endl;
	}
	else
	{
		cout << "nema ga" << endl;
	}
}

void ispisi_sve_gradove(map<int, string>& m)
{
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}
}

int main()
{
	//mapa je hashtablica
	//sta stavljamo kao kljuc a kaj pod broj/value
	//imamo crud operacije
	map<int, string> m;

	int choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			unos(m);
			break;
		case 2:
			izmjena(m);
			break;
		case 3:
			brisanje(m);
			break;
		case 4:
			ispisi_grad(m);
			break;
		case 5:
			ispisi_sve_gradove(m);
			break;
		}


	} while (choice != 0);


	return 0;
}