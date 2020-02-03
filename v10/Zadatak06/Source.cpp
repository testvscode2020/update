#include <iostream>
#include "insertion_sort.h"
#include "tocka.h"

using namespace std;

/*
Promijenite insertion sort tako da sortira 2D točke prema njihovoj 
udaljenosti od ishodišta. Zadajte nekoliko točaka u programu, 
sortirajte pa ispišite točke i udaljenosti.
*/

int main() 
{	
	Tocka tocke[] = 
	{ 
		Tocka(5, 0), 
		Tocka(0, 5), 
		Tocka(10, 10), 
		Tocka(5, 5), 
		Tocka(4, 7) 
	};
	
	int size = sizeof(tocke) / sizeof(Tocka);
	insertion_sort(tocke, size);

	for (int i = 0; i < size; i++) 
	{
		cout 
			<< tocke[i].x << ", " 
			<< tocke[i].y 
			<< " (D=" << tocke[i].distance() << ")" 
			<< endl;
	}
	
	return 0;
}