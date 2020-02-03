#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


/*
Prethodni zadatak riješite korištenjem vektora. Potom prebrojavanje 
napravite korištenjem metode find. Što je jednostavnije, a što 
složenije?
*/

void fill_words(ifstream &in, vector<string> &words)
{
	int pos = 0;
	string word;
	while (in >> word)
	{
		words.push_back(word);
	}
}

int main()
{
	ifstream in("NekiTekst.txt");
	if (!in)
	{
		cout << "nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<string> words;
	fill_words(in, words);

	in.close();

	string what = "the";
	//ovo radi potpuno isto kao i za array:
	//int counter = count(words.begin(), words.end(), what);
	
	//koristenje funkcije find:
	int counter = 0;
	//duzi oblik povratne vrijednosti:
	//vector<string>::iterator pos = find(words.begin(), words.end(), what);
	//skraceni oblik povratne vrijednosti (povratna vrijednost se automatski 
	//deducira prema vrijednosti koju vraca funkcija):
	auto pos = find(words.begin(), words.end(), what);
	while (pos != words.end()) {
		counter++;
		pos = find(pos + 1, words.end(), what);
	}

	cout << "rijec " << what << " se pojavljuje " << counter << " puta" << endl;

	return 0;
}