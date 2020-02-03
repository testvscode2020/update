#include <iostream>
#include <string>
#include <unordered_set>
#include <ctime>
#include <algorithm>

using namespace std;

/*
Napišite program koji u unordered_set ubacuje 1000 slučajnih stringova 
duljine 5 znakova i sastavljenih od slova ‘a’, ‘b’, ‘c’, ‘d’ i ‘e’. 
Ispišite svaki put kad se ubacivanje ne napravi jer vrijednost već postoji.
*/

int main()
{
	srand(time(nullptr));
	unordered_set<string> set;
	string s = "abcde";
	int coll = 0;
	for (int i = 0; i < 1000; i++)
	{
		random_shuffle(s.begin(), s.end());
		//pair<unordered_set<string>::iterator, bool> retval = set.insert(s);
		auto retval = set.insert(s);
		if (!retval.second)
		{
			cout << "iteracija: "<< i << ",  broj kolizija: " << ++coll << endl;
		}
	}

	return 0;
}