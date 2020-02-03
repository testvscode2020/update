#include <iostream>
#include <ctime>
#include <queue>
#include "Message.h"

using namespace std;

/*
Napravite program koji koristi prioritetni red za obradu
zaprimljenih poruka prema prioritetima (1 = minimalni,
2 = normalni, 3 = visoki prioritet). Zaprimite nekoliko poruka pa
ih obradite ispisivanjem na ekran.
*/

int main()
{
	priority_queue<message, vector<message>, message_comparer_desc> pq;

	pq.push(message("Kupi kruh", 2));
	pq.push(message("Pokupi punicu", 3));
	pq.push(message("Nauci raditi s hrpom", 1));
	pq.push(message("Kupi mlijeko", 1));
	pq.push(message("Nauci rjesavati diferencijalne jednadzbe", 3));

	while (!pq.empty())
	{
		cout << pq.top().text << "(" << pq.top().priority << ")" << endl;
		pq.pop();
	}
	
	return 0;
}