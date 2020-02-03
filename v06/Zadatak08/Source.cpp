#include <iostream>
#include "MojStog.h"

using namespace std;

/*
Implementirajte svoj stog cijelih brojeva po želji tako da ga možete koristiti
na ovakav način:
int main () {
MojStog s;
for (int i = 1; i <= 5; i++) s.push(i);
while (!s.empty()) {
cout << ' ' << s.top();
s.pop();
}
cout << endl;
return 0;
}
*/

int main() {
	MojStog s;

	for (int i = 1; i <= 5; i++) s.push(i);

	while (!s.empty()) {
		cout << ' ' << s.top();
		s.pop();
	}
	cout << endl;

	return 0;
}
