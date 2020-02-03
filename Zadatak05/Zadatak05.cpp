#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
/*
	 U prilogu se nalazi ulazna datoteka „brojevi.txt“ koja sadrži točno 25 brojeva međusobno odvojenih jednim razmakom, dok se iza zadnjeg broja nalazi znak enter. 
	 Vaši su zadaci sljedeći: 
		Učitajte sve brojeve u listu (koristite list<T>). 
		Iz liste izbrišite sve negativne brojeve. 
		Preostale brojeve pomnožite sa 3. 
		Sve brojeve iz liste prepišite od kraja prema početku u vektor. 
		Sve brojeve u vektoru pomnožite sa 3. 
		Sve brojeve iz vektora smjestite na stog. 
		Ispišite sve elemente stoga.
 
*/
void load_into_list(ifstream& input, list<int>& list)
{
	int temp;
	while (input >> temp)
	{
		list.push_back(temp);
	}
}

void print(int &number)
{
	cout << number << " ";
}

bool is_negative(int& number)
{
	return number < 0;
}

void multiplyWithThree(int& number)
{
	number *= 3;
}

void fill_stack(vector<int> &vector, stack<int> &stack)
{
	for (auto i = vector.begin(); i != vector.end(); i++)
	{
		stack.push(*i);
	}
}

int main()
{
	ifstream input("brojevi.txt");
	if (!input)
	{
		cout << "Nema fajla!" << endl;
		return 1;
	}
	list<int> list;
	
	load_into_list(input, list);
	input.close();

	for_each(list.begin(), list.end(), print);
	cout << endl;

	list.remove_if(is_negative);
	for_each(list.begin(), list.end(), print);
	cout << endl;

	for_each(list.begin(), list.end(), multiplyWithThree);
	for_each(list.begin(), list.end(), print);
	cout << endl;

	vector<int> vector(list.rbegin(), list.rend());

	for_each(vector.begin(), vector.end(), print);
	cout << endl;

	for_each(vector.begin(), vector.end(), multiplyWithThree);
	for_each(vector.begin(), vector.end(), print);
	cout << endl;

	stack<int> stack;
	fill_stack(vector, stack);
	
	while (!stack.empty())
	{
		print(stack.top());
		stack.pop();
	}

	cout << endl;
	return 0;
}