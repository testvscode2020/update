#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Napravite sljedeće:
a.Napravite unordered_map s cjelobrojnim ključem koja može čuvati stringove.
b.Ubacite proizvoljne vrijednosti za ključeve 1, 2, 3, 4 i 5.
c.Učitajte od korisnika ključ pa ili ispišite vrijednost pod tim ključem ili
napišite da ključ ne postoji.
d.Prepišite sve neparne ključeve i i njihove vrijednosti u unordered_multimap.
e.Ispišite sve iz multimape.
f.Prepišite sve vrijednosti s više od 3 znaka u unordered_set.
g.Uklonite prvu vrijednost iz seta.
h.Prepišite sve vrijednosti u unordered_multiset i ispišite ih
i.Pobrišite sve iz multiseta.
*/

void fill_map(unordered_map<int, string> &m) 
{
	m.insert(pair<int, string>(1, "Zec"));
	m.insert({ 2, "Zaba" });
	m.insert({ {3, "Tramvaj"}, {4, "Slon"} });
	m[5] = "Avion";
}

void search_map(unordered_map<int, string> &m)
{
	int key;
	cout << "Unesite kljuc:";
	cin >> key;
	//unordered_map<int, string>::iterator it = m.find(key);
	auto it = m.find(key);
	if (it != m.end()) 
	{
		cout << "Nadjen je kljuc:" << endl;
		cout << it->first << ": " << it->second << endl;
	}
	else 
	{
		cout << "Nema trazenog kljuca" << endl;
	}
}

void fill_multimap(unordered_map<int, string> &m, unordered_multimap<int, string> &mm)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		if (it->first % 2 != 0)
		{
			//mm.insert({ it->first, it->second });
			mm.insert(*it);
		}
	}
}

void print_multimap(unordered_multimap<int, string> &mm)
{
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << ": " << it->second << endl;
	}
}

void fill_set(unordered_multimap<int, string> &mm, unordered_set<string> &s)
{
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		if (it->second.length() > 3)
		{
			s.insert(it->second);
		}
	}
}

void fill_multiset(unordered_set<string> &s, unordered_multiset<string> &ms)
{
	//for (auto it = s.begin(); it != s.end(); ++it)
	//{
	//	ms.insert(*it);
	//}
	ms.insert(s.begin(), s.end());
}

void print_multiset(unordered_multiset<string> &ms)
{
	for (auto it = ms.begin(); it != ms.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main() 
{
	//a.
	unordered_map<int, string> m;
	//b.
	fill_map(m);	
	//c.
	search_map(m);
	//d.
	unordered_multimap<int, string> mm;
	fill_multimap(m, mm);
	//e.
	cout << "multimap:" << endl;
	print_multimap(mm);
	//f.
	unordered_set<string> s;
	fill_set(mm, s);
	//g.
	s.erase(s.begin());
	//h.
	unordered_multiset<string> ms;
	fill_multiset(s, ms);
	cout << "multiset:" << endl;
	print_multiset(ms);
	//i.
	ms.clear();

	return 0;
}