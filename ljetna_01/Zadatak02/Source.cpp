#include <iostream>
#include <ctime>
#include <chrono>

/*
a) Na osnovu tablice <tablica s predavanja 3>, odgovorite
koji algoritmi imaju najbolje performanse prilikom brisanja,
ako promatramo najgori slučaj. b) Generirajte 10.000 slučajnih
cijelih brojeva između 1 i 5. Nakon toga, izračunajte i ispišite
prosjek svih tih brojeva. Potrebno je i izračunati i ispisati
ukupno trajanje cijelog posla (od generiranja do izračuna prosjeka).
*/

using namespace std;
using namespace std::chrono;

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int* prepare_array(int length)
{
	int *polje = new int[length];
	for (int i = 0; i < length; i++)
	{
		polje[i] = generate_random(1, 5);
	}
	return polje;
}

double average(int *arr, int length)
{
	double sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum / length;
}


int main()
{
	srand(time(nullptr));
	int n = 10000;

	auto begin = high_resolution_clock::now();

	int *arr = prepare_array(n);
	double avg = average(arr, n);

	auto end = high_resolution_clock::now();

	cout << "Average: " << avg << endl;
	cout << "Time: "
		<< duration_cast<microseconds>(end - begin).count()
		<< " us" << endl;

	delete[] arr;

	return 0;
}