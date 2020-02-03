#include <iostream>
#include <fstream>

#include "Pravokutnik.h"
#include "merge_sort.h"

using namespace std;

void load_file(ifstream &input, Pravokutnik *pravokutnici, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		input >> pravokutnici[i].a >> pravokutnici[i].b;
	}
}

void write_file(ofstream& output, Pravokutnik* pravokutnici, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		output << pravokutnici[i].a << " " << pravokutnici[i].b << " " << pravokutnici[i].getPovrisna() <<endl;
	}
}

int main()
{
	ifstream input("pravokutnici.txt");
	ofstream output("pravokutnici_rastuce.txt");

	if (!input || !output)
	{
		cout << "Nist od toga" << endl;
		return 1;
	}

	const int BROJ_ELEMENATA = 1000;

	Pravokutnik* pravokutnici = new Pravokutnik[BROJ_ELEMENATA];
	load_file(input, pravokutnici, BROJ_ELEMENATA);
	input.close();

	merge_sort(pravokutnici, BROJ_ELEMENATA);
	write_file(output, pravokutnici, BROJ_ELEMENATA);

	output.close();
	delete[] pravokutnici;
	return 0;
}