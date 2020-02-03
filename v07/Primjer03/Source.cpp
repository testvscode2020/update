#include <iostream>
#include <string>

using namespace std;

void print_forward(string s, int i) {
	if (i < 0) {
		return;
	}
	print_forward(s, i - 1);
	cout << s[i] << " ";
}

void print_backward(string s, int i) {
	if (i < 0) {
		return;
	}
	cout << s[i] << " ";
	print_backward(s, i - 1);
}

int main() {
	string s;
	cout << "Unesite recenicu:";
	getline(cin, s);

	print_forward(s, s.length() - 1);
	cout << endl;

	print_backward(s, s.length() - 1);
	cout << endl;
}