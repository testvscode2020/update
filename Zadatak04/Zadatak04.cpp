#include <iostream>
#include <fstream>
#include <queue>

/*
	U prilogu se nalazi ulazna datoteka �brojevi.txt� koja sadr�i to�no 25 brojeva me�usobno odvojenih jednim razmakom, dok se iza zadnjeg broja nalazi znak enter. 
	Va� je zadatak da u�itate 5 brojeva iz ulazne datoteke u red, 
	nakon toga da iz reda prepi�ete tih 5 brojeva u izlaznu datoteku i da to ponavljate sve dok ne iscrpite 25 brojeva iz ulazne datoteke. 
	Izlazna datoteka na kraju treba imati identi�an sadr�aj kao i ulazna datoteka. 
*/

using namespace std;

void flush_queue(ofstream& output, queue<int>& queue)
{
	while (!queue.empty())
	{
		output << queue.front() << " ";
		queue.pop();
	}
}

void copy(ifstream& input, ofstream& output)
{
	queue<int> queue;
	int temp;

	while (input >> temp)
	{
		queue.push(temp);
		if (queue.size() == 5)
		{
			flush_queue(output, queue);
		}
	}

	flush_queue(output, queue);
}

int main()
{
	ifstream input("brojevi.txt");
	ofstream output("output.txt");

	if (!input || !output)
	{
		cout << "Gre�ka!" << endl;
		
		return 1;
	}

	copy(input, output);

	input.close();
	output.close();

	return 0;
}