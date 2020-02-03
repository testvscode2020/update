#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

/*
Kreirajte ulaznu datoteku koja sadrzi brojeve od 1 do 10. 
Obradite datoteku na način da izlazna datoteka ima sljedeći sadržaj:
2 1 4 3 6 5 8 7 10 9
Odaberite pravilnu kolekciju (stack ili queue).
*/

void flush(stack<int> &s, ofstream& out)
{
	while (!s.empty())
	{
		out << s.top() << " ";
		s.pop();
	}
}

void parse(ifstream &in, ofstream& out)
{
	int n;
	stack<int> s;
	while (in >> n)
	{
		s.push(n);
		if (s.size() == 2)
		{
			flush(s, out);
		}
	}
	flush(s, out);

}

int main()
{
	ifstream in("brojevi.txt");
	ofstream out("output.txt");

	if (!in || !out)
	{
		cout << "Nije moguce pristupiti" << endl;
		return 1;
	}

	parse(in, out);

	in.close();
	out.close();

	return 0;
}