#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

//iz jedne datoteke u drugu datoteku treba kopirati
//FIFO --- a to je queue

void read(ifstream &in, queue<string> &q)
{
	string line;
	while(getline(in, line))
	{
		q.push(line);
	}
	//Old MacDonald had a farm.txt
}

void write(ofstream &out, queue<string> &q)
{
	string line;
	while (!q.empty())
	{
		out << q.front();
		q.pop();
		
	}
}


int main()
{
	string filename;
	cout << "molimte unesi put datoteke: ";
	getline(cin,filename);

	ifstream in(filename);
	ofstream out("ispis.txt");
	if (!in || !out)
	{
		cout << "nema rad sa datotekama" << endl;
	}

	queue<string> mojiq;
	read(in, mojiq);

	write(out, mojiq);



	in.close();
	out.close();
	return 0;
}
