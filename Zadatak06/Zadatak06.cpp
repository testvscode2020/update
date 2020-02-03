#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

/*
	U prilogu su tri C++ datoteke, dvije neispravne i jedna ispravna. 
	Napi�ite program koji �e provjeravati je li zadana C++ datoteka balansirana po pitanju zagrada �{�, �[� i �(�. Algoritam provjere je sljede�i: 
	a) Pro�ite datoteku znak po znak. 
	b) Ako je znak otvaraju�a zagrada, gurnite ga na stog. 
	c) Ako je znak zatvaraju�a zagrada, i ima istu otvarajucu skinite znak sa stoga i usporedite jesu li jednaki. Ako nisu, gre�ka i kraj. 
	d) Ako na kraju ostane i�ta na stogu, gre�ka i kraj. 
	Iskoristite gornji algoritam i za svaku od tri datoteke iz priloga ispi�ite je li balansirana ili nije
*/

bool check_file(ifstream& stream, stack<char>& stack)
{
	string line;
	while (getline(stream, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			char current_character = line[i];
			if (current_character == '{' || current_character == '[' || current_character == '(')
			{
				stack.push(current_character);
			}
			else if (current_character == '}')
			{
				if (!stack.empty() && stack.top() == '{')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
			else if (current_character == ']')
			{
				if (!stack.empty() && stack.top() == '[')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
			else if (current_character == ')')
			{
				if (!stack.empty() && stack.top() == '(')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}


	return stack.empty();
}

int main()
{
	ifstream file("proba1.txt");

	if (!file)
	{
		cout << "Nema fajla!" << endl;
		return 1;
	}

	stack<char> stack;

	if (check_file(file, stack))
	{
		cout << "Balans!" << endl;
	}
	else 
	{
		cout << "Nije dobro!" << endl;
	}

	return 0;
}