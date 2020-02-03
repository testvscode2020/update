#include <iostream>
#include <unordered_set>

using namespace std;

/*
Napišite program koji kreira unordered_multiset cijelih brojeva. 
Sve dok korisnik to želi, ubacujte u set brojeve od 1 do 22.
Nakon svakog ubacivanja ispišite sve buckete i pokraj svakog u 
zagradi broj elemenata hashiranih u njega.
*/

int main()
{
	unordered_multiset<int> s;
	int current = 1;
	int limit = 22;
	bool dalje;
	do
	{
		while (current <= limit)
		{
			s.insert(current++);
		}
		limit += 22;

		for (unsigned i = 0; i < s.bucket_count(); i++)
		{
			cout << "Bucket:" << i << ": " << s.bucket_size(i) << " elemenata" << endl;
		}

		cout << "Elements in set: " << s.size() << endl;
		cout << "Number of buckets: " << s.bucket_count() << endl;

		cout << "dalje (1=da, 0=ne): ";
		cin >> dalje;
	} while (dalje);

}