#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

/*
Napišite program koji od korisnika učitava naziv ulazne datoteke. 
Nakon toga, sve retke iz ulazne datoteke prepišite obrnutim redoslijedom 
u novu datoteku. Za primjer možete koristiti datoteku Old MacDonald had a 
farm.txt. Ispravno odaberite stog ili red.
*/

void load(ifstream &in, stack<string> &s) 
{
	string line;
	while (getline(in, line)) 
	{
		s.push(line);
	}
}

void save(ofstream &out, stack<string> &s) 
{
	while (!s.empty()) 
	{
		//cout << s.top() << endl;
		out << s.top() << endl;
		s.pop();
	}
}

int main() {

	string file_name;
	cout << "Upisite naziv datoteke: ";
	getline(cin, file_name);

	ifstream in(file_name);
	ofstream out("reversed.txt");
	if (!in || !out) {
		cout << "Greska pri otvaranju datoteke za citanje" << endl;
		return 1;
	}
	
	stack<string> s;

	load(in, s);
	in.close();

	save(out, s);
	out.close();

	return 0;
}