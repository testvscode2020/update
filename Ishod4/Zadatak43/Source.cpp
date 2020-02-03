#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Solar.h" //povuce string i std iz headera

//43. ti je solar system, vjezbe 11. zadaci od 4. do 8.
//mozes proci sve za vjezbu, ali na ispitu ti se trazi samo ime i Diameter (Earth=1) ako se dobro sjecam.
//to ti je promjer i u biti sve sto se trazi na ispitu je da ispises ime planeta sa drugim najvecim promjerom(Jupiter)

template<typename T>
T convert(string &s) { //treba ti convert za diameter 

	stringstream ss(s);
	T result;
	ss >> result;
	return result;
}

void load(ifstream &in, vector<Solar> &v) { 

	string line;
	getline(in, line);
	
	//klasicno parsiramo datoteku
	while (getline(in, line))
	{
		///cout << line << endl; //test printing
		stringstream ss(line);
		string temp;
		Solar s; //najjednostavniji nacin za parsiranje, preko strukture

		getline(ss, temp, ','); //preskoci ID
		getline(ss, s.Name, ','); //dohvati ime; temp je ionako string, pa nemoras convertat

		getline(ss, temp, ','); //preskoci tip
		getline(ss, temp, ','); //preskoci udaljenost

		getline(ss, temp, ','); //dohvati promjer
		s.Diameter_Earth = convert<double>(temp); //sada koristimo convert da string prebacimo u double

		v.push_back(s); //za kraj gurni s u vektor
	}
}

void print(Solar &s) {

	cout << " Ime: " << s.Name << ", promjer: " << s.Diameter_Earth << endl;
}

bool sort_by_diameter(Solar a, Solar b) {

	return a.Diameter_Earth > b.Diameter_Earth;
}
int main() {

	ifstream in("Solar System.csv");
	if (!in) {

		cout << " Error 404 File Not Found! " << endl;
		return 1;
	}

	vector<Solar> v;
	load(in, v); //ucitamo u vektor
	in.close();

	///sort(v.begin(), v.end(), sort_by_diameter); //ovo je za testiranje, prvo ga sortas uzlazno,
	///for_each(v.begin(), v.end(), print);       // pa onda mozes vidjeti sa je drugi po promjeru stvarno Jupiter

	nth_element(v.begin(), v.begin() + 1, v.end(), sort_by_diameter); //nth_element je funkcija koju trebas, obavezno na kraju sortas po promjeru
	print(*(v.begin() + 1)); //pocinjes od pocetka (prvi je sunce), i samo dodas +1 da dobijes drugi(Jupiter)

	return 0;
}