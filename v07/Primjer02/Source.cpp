#include <iostream>

using namespace std;

void print(int n) {
	if (n < 1) {
		return;
	}
	print(n - 1);
	cout << n << " ";
}

int main() {
	int n;
	cout << "Unesite broj:";
	cin >> n;

	print(n);
	cout << endl;
}