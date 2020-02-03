#include <iostream>
#include "MojRed.h"

using namespace std;

/*
Implementirajte svoj red cijelih brojeva po želji tako da ga možete koristiti
na ovakav način:
int main () {
MojRed q;
for (int i = 1; i <= 5; i++) q.push(i);
while (!q.empty()) {
cout << ' ' << q.front();
q.pop();
}
cout << endl;
return 0;
}
*/

int main() {
	MojRed q;

	for (int i = 1; i <= 5; ++i) q.push(i);

	while (!q.empty()) {
		cout << ' ' << q.front();
		q.pop();
	}
	cout << endl;

	return 0;
}
