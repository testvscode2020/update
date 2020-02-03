#include <iostream>

using namespace std;

unsigned long long factorial(unsigned n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	for (unsigned i = 1; i <= 20; i++) {
		cout << i << "! = " << factorial(i) << endl;
	}
}