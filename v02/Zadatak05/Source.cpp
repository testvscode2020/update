#include <iostream>
#include <array>

using namespace std;

/*
Napišite program koji definira array s brojevima od 1 do 100. 
Ispišite sve proste brojeve koristeći algoritam for_each.
*/

void init_array(array<int, 100> &arr)
{
	for (unsigned i = 0; i < arr.size(); i++)
	{
		arr[i] = i + 1;
	}
}

bool prime(int &n) 
{
	for (int i = 2; i <= n/2; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return n != 1;
}

void print_if_prime(int &n) 
{
	if (prime(n)) 
	{
		cout << n << endl;
	}
}

int main() 
{
	array<int, 100> arr;
	init_array(arr);
	for_each(arr.begin(), arr.end(), print_if_prime);
	
	//print backwards
	//1. nacin
	//for_each(arr.rbegin(), arr.rend(), print_if_prime);
	//2. nacin
	//reverse(arr.begin(), arr.end());
	//for_each(arr.begin(), arr.end(), print_if_prime);
	return 0;
}