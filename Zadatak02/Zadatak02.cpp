#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
	Na osnovu tablice <tablica s predavanja 3>, odgovorite koji algoritmi imaju najbolje performanse prilikom brisanja, 
	ako promatramo najgori sluèaj. b) Generirajte 10.000 sluèajnih cijelih brojeva izmeðu 1 i 5. 
	Nakon toga, izraèunajte i ispišite prosjek svih tih brojeva. 
	Potrebno je i izraèunati i ispisati ukupno trajanje cijelog posla (od generiranja do izraèuna prosjeka).
*/

int generate_rand_number(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int* prepare_array(int length)
{
	int* array = new int[length];
	
	for (int i = 0; i < length; i++)
	{
		array[i] = generate_rand_number(1, 5);
	}

	return array;
}

double calculate_average(int* array, int length)
{
	double sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		sum += array[i];
	}

	return sum / length;
}

int main()
{
	srand(time(nullptr));
	int length = 10000;
	
	auto begin = high_resolution_clock::now();

	int* array = prepare_array(length);
	double average = calculate_average(array, length);

	auto end = high_resolution_clock::now();

	cout << "Average: " << average << endl;
	cout << "Duration: " 
		<< duration_cast<microseconds>(end - begin).count()
		<< " us";

	delete[] array;
	return 0;
}