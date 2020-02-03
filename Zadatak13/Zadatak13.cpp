#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<int> set;
	int current = 1;
	int limit = 22;
	bool dalje;

	do
	{
		while (current <= limit)
		{
			set.insert(current++);
		}
		limit += 22;
		
		for (int i = 0; i < set.bucket_count(); i++)
		{
			cout << "Bucket: " << i << " " << set.bucket_size(i) << " elemenata" << endl;
		}

		cout << "Elements in set: " << set.size() << endl;
		cout << "Number of buckets: " << set.bucket_count() << endl;

		cout << "Dalje (1 = da, 0 = ne)";
		cin >> dalje;
	} while (dalje);

	return 0;
}