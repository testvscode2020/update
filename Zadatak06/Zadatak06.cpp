#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

/*
	U prilogu su tri C++ datoteke, dvije neispravne i jedna ispravna. 
	Napišite program koji æe provjeravati je li zadana C++ datoteka balansirana po pitanju zagrada ‘{‘, ‘[‘ i ‘(‘. Algoritam provjere je sljedeæi: 
	a) Proðite datoteku znak po znak. 
	b) Ako je znak otvarajuæa zagrada, gurnite ga na stog. 
	c) Ako je znak zatvarajuæa zagrada, i ima istu otvarajucu skinite znak sa stoga i usporedite jesu li jednaki. Ako nisu, greška i kraj. 
	d) Ako na kraju ostane išta na stogu, greška i kraj. 
	Iskoristite gornji algoritam i za svaku od tri datoteke iz priloga ispišite je li balansirana ili nije
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