#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int convert(string& s)
{
	stringstream c(s); //prvo ga bacim u bacvu(container)
	int x; //imam variablu
	c >> x; // iz bacve u variablu
	return x;
}

void fill(ifstream& in, multimap<int, string>& mm)
{
	string line;
	while (getline(in, line))
	{
		//cout << line << endl; //koristimo za provjeru
		stringstream ss(line); // sa time je postao universalni parser
		string temp;
		getline(ss, temp, ' ');
		int id = convert(temp);

		string bill;
		getline(ss, bill);

		mm.insert({ id, bill });
	}
}


int main()
{
	ifstream in("Racuni2.csv");
	if (!in)
	{
		cout << "no can do" << endl;
		return 1;
	}

	multimap<int, string> mm;

	fill(in, mm);

	in.close();

	int id;
	cout << "id: ";
	cin >> id;

	auto rez = mm.equal_range(id); //pronađe nam par od parova. 

	if (rez.first == rez.second)
	{
		cout << "nema ga" << endl;
	}
	else
	{
		for (auto it = rez.first; it != rez.second; it++)
		{
			cout << it->second << endl; //ovo je par parova -> derefencira automatski iterator (*it).second je druga varianta
		}
	}

	return 0;
}