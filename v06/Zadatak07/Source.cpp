#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

/*
Napišite program koji korisniku u petlji nudi opcije:
•Upis novog broja: INPUT n
•Slanje svih do sada upisanih brojeva u datoteku: FLUSH
•Kraj rada: EXIT
Unesene brojeve čuvajte u stogu ili redu. Zadavanjem naredbe za slanje 
brojeva u datoteku se svi upisani podaci iz kontejnera upisuju u tekstualnu 
datoteku te je kontejner spreman za upis novih podataka.
*/

void work(ofstream &out) 
{
	queue<int> q;
	string command_line;
	string command;
	int argument;
	do
	{
		cout << "Unesite naredbu: ";
		getline(cin, command_line);

		stringstream ss(command_line);
		ss >> command;
		ss >> argument;

		if (command == "INPUT") 
		{
			q.push(argument);
		}
		else if (command == "FLUSH") 
		{
			while (!q.empty()) 
			{
				out << q.front() << endl;
				q.pop();
			}
		}
		else if (command == "EXIT") 
		{
			break;
		}
	} while (true);

}

int main() 
{
	ofstream out("brojevi.txt");
	if (!out) 
	{
		cout << "Greska pri otvaranju datoteke za pisanje" << endl;
		return 1;
	}
	work(out);
	out.close();

	return 0;
}