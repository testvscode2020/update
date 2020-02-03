#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

/*
U prilogu se nalazi ulazna datoteka „brojevi.txt“ 
koja sadrži točno 25 brojeva međusobno odvojenih 
jednim razmakom, dok se iza zadnjeg broja nalazi 
znak enter. Vaš je zadatak da učitate 5 brojeva 
iz ulazne datoteke u red, nakon toga da iz reda 
prepišete tih 5 brojeva u izlaznu datoteku i da 
to ponavljate sve dok ne iscrpite 25 brojeva iz 
ulazne datoteke. Izlazna datoteka na kraju treba 
imati identičan sadržaj kao i ulazna datoteka.
*/

void flush_queue(queue<int> &q, ofstream &out)
{
	while (!q.empty())
	{
		out << q.front() << " ";
		q.pop();
	}
}

void copy_file(ifstream &in, ofstream &out)
{
	queue<int> q;
	int n;
	while (in >> n)
	{
		q.push(n);
		if (q.size() == 5)
		{
			flush_queue(q, out);
		}
	}
	//sto ako ih nema tocno 25 -> znaci da su neki zaostali u redu i treba ih pocistiti
	flush_queue(q, out);
}

void flush_stack(stack<int> &s, ofstream &out) {
	while (!s.empty())
	{
		out << s.top() << " ";
		s.pop();
	}
}
void reverse_file(ifstream &in, ofstream &out)
{
	stack<int> s;
	int n;
	while (in >> n)
	{
		s.push(n);
	}
	flush_stack(s, out);
}

int main()
{
	ifstream in("brojevi.txt");
	ofstream out("output.txt");
	if (!in || !out)
	{
		cout << "Nije moguce pristupiti datotekama" << endl;
		return 1;
	}

	copy_file(in, out);

	//dodatno - sto da je bilo rijec o stacku?
	//reverse_file(in, out);

	out.close();
	in.close();

	return 0;
}