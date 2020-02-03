#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

/*
Napišite program koji u array učitava sve riječi 
iz datoteke NekiTekst.txt (kao granicu „riječi” 
uzmite bilo koju bjelinu – razmak, tab, enter).
Ispišite koliko puta se u tekstu pojavljuje riječ „the”. 
Hint: kad učitavate string na način „cin >> str”, 
onda će se učitavanje raditi do prve bjeline. 
U čemu je problem sa ovim zadatkom?
*/

int count_words(ifstream &in)
{
	int counter = 0;
	string word;
	while (in >> word) 
	{
		counter++;
	}
	return counter;
}

void fill_words(ifstream &in, array<string, 250> &words)
{
	int pos = 0;
	string word;
	while (in >> word)
	{
		words[pos++] = word;
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
	//prvo pokrenem ovu funkciju, kako bih doznao koliko ima rijeci
	//int nr_words = count_words(in); 
	//cout << nr_words << endl; //250

	//potom mogu kreirati array
	array<string, 250> words;
	fill_words(in, words);

	in.close();

	string what = "the";
	//koristenje funkcije count:
	int counter = count(words.begin(), words.end(), what);
	cout << "rijec " << what << " se pojavljuje " << counter << " puta" << endl;

	//problem ovog zadatka je sto moramo prethodno znati za velicinu array-a
	return 0;
}