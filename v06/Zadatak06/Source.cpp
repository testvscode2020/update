#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

/*
Omogućite korisniku izračun matematičkih izraza napisanih u reverznoj poljskoj 
notaciji (RPN). RPN je način zapisivanja izraza u kojemu operator slijedi iza 
svojih operanada. Primjerice, izraz (4 + 2 * 5) / (1 + 3 * 2) bismo u RPN-u 
zapisali: 4 2 5 * + 1 3 2 * + /
RPN je zgodan jer ga sljedećim algoritmom lako izračunavamo pomoću stoga:
1.Uzmi sljedeći niz znakova do razmaka, sve dok nismo došli do kraja. 
Kad smo sve obradili, na stogu je rezultat.
a.Ako je broj, gurni na stog.
b.Ako je operator, skini dvije vrijednosti sa stoga, izračunaj rezultat i 
gurni ga na stog.
Pretpostavite da će korisnik ispravno upisivati samo cijele brojeve i 
operatore +, -, *, /, međusobno odvojene razmacima.
*/

template<typename T>
T convert(string &s) 
{
	stringstream c(s);
	T result;
	c >> result;
	return result;
}

int calculate(string &expression) 
{
	stack<int> s;
	stringstream ss(expression);
	string temp;
	while (ss >> temp) 
	{
		if (temp == "+" || temp == "-" || temp == "*" || temp == "/") 
		{
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();

			switch (temp[0])
			{
			case '+':
				s.push(a + b);
				break;
			case '-':
				s.push(a - b);
				break;
			case '*':
				s.push(a * b);
				break;
			case '/':
				s.push(a / b);
				break;
			}
		}
		else 
		{
			int val = convert<int>(temp);
			s.push(val);
		}
	}
	return s.top();
}

int main() 
{
	//string expression = "2 1 12 3 / - +"; // -1
	//string expression = "4 2 5 * + 1 3 2 * + /"; // 2
	string expression = "2 3 11 + 5 - *"; // 18

	cout << "Rezultat: " << calculate(expression) << endl;

	return 0;
}