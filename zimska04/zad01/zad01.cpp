#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;

//prioritetni red je rijesen preko hrpe, to je trik pitanje
//kako radi priority queue
//onda nam treba nekaj obrnuto

int gen_rnd(int min, int max)
{
	return rand() % (max - min) + min;
}


void randomize(vector<int>& v, int limit, int min, int max)
{
	for (int i = 0; i < limit; i++)
	{
		v.push_back(gen_rnd(min, max));
		//test
		//cout << v[i] << endl;
	}
}

void print(priority_queue<int>& pq)
{
	while (!pq.empty())
	{
		cout << pq.top() <<  " ";
		pq.pop(); //radi padajuce
	}
}

void print(priority_queue<int, vector<int>, greater<int>> &pq)
{
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop(); //radi padajuce
	}
}


int main()
{
	srand(time(nullptr)); //time vraca time i mozes mu dati pointer,
	vector<int> v;
	randomize(v, 50, 100, 999);

	int order;
	cout << "order: ASC- 0, DESC - 1:";
	cin >> order;

	switch (order)
	{
	case 0:
		//priority_queue<int> pq(v.begin(), v.end()); 
		//priority encapsulira vector ispod sebe, moze i biti lista i ktome komparira elemente
		//ali vidili smo da defaultno rado sa vektorom i to descending,
		//mozemo mu podvaliti listu i komparataor
		//srecom int ima svoje komparatore
		//ovaj komparator se zove "greater", ali ako se da komparator, onda mora ici underlying type .. kod nas gore je vector<int>
		//nemozemo imato pq u dva 
		//bolje je bilo da bi rijeslili sa if+else-om!!
	{
		priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
		print(pq);
		break;
	}

	case 1:
		priority_queue<int> pq(v.begin(), v.end()); //in ima konstruktora i ima range //ali neznamo jeli je do asc ili desc
		print(pq);
		break;
	}



	

	return 0;
}