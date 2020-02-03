#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

/*
Napišite program za obradu teksta koji korisniku u petlji pruža opcije:
•Unos nove riječi: ADD riječ
•Odustajanje od zadnje naredbe: UNDO
•Završetak rada i ispis unesenog teksta: EXIT
Pretpostavite da će korisnik uvijek naredbe pisati točno kako smo definirali. 
Ignorirajte sve što nije ispravna naredba. Ispravno odaberite stog ili red.
*/


void input(stack<string> &s) 
{
	string command_line;
	string command;
	string argument;
	do
	{
		cout << "Unesite naredbu: ";
		getline(cin, command_line);

		stringstream ss(command_line);
		ss >> command;
		ss >> argument;

		if (command == "ADD") 
		{
			s.push(argument);
		}
		else if (command == "UNDO") 
		{
			if (!s.empty()) 
			{
				s.pop();
			}
		}
		else if (command == "EXIT") 
		{
			return;
		}
	} while (true);
}

void output(stack<string> &s) 
{
	stack<string> output;
	while (!s.empty()) 
	{
		output.push(s.top());
		s.pop();
	}

	while (!output.empty()) 
	{
		cout << output.top() << " ";
		output.pop();
	}
	cout << endl;
}

int main() 
{
	stack<string> s;
	input(s);
	output(s);

	return 0;
}