#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>

/*
Kreirajte listu brojeva veličine 10. Potom:
•ispišite vrijednosti koje se nalaze u listi – koji su to brojevi i zašto?
•u listi izmijenite vrijednosti elemenata tako da vrijednosti budu 1 - 10, koristeći reverse_iterator
•ispišite prvi i zadnji element liste
•ispišite samo neparne vrijednosti koje se nalaze u listi, međutim nemojte koristiti modulo 
operator već increment na iteratoru – u čemu je problem i koja je razlika naspram vectora?
•kreirajte forward_list i u nju prepišite samo parne brojeve iz liste, unazad, ali idući unaprijed po listi
•iz forward_liste izbacite broj 10 i ispišite prvi broj
•ispišite brojeve iz forward_liste koristeći for_each – možete li ih ispisati unazad i zašto?
•izbrišite sadržaj forward_liste (jedan po jedan element) – možete li ispisati size()?
•iz liste izbrišite sve elemente odjednom i ispišite size()
*/

void print_odd(int &n) {
	if (n % 2 != 0)
	{
		std::cout << n << " ";
	}
}

void print(int &n) {
	std::cout << n << " ";
}

int main() {
	//Kreirajte listu brojeva velicine 10
	int n = 10;
	std::list<int> brojevi(n);

	//ispisite vrijednosti koje se nalaze u listi
	for (auto it = brojevi.begin(); it != brojevi.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//u listi izmijenite vrijednosti elemenata tako da vrijednosti budu 1 - 10, koristeci reverse_iterator 
	int i = 10;
	for (auto it = brojevi.rbegin(); it != brojevi.rend(); ++it) {
		*it = i--;
	}

	//ispisite prvi i zadnji element liste
	std::cout << "prvi broj: " << brojevi.front() << std::endl;
	std::cout << "zadnji broj: " << brojevi.back() << std::endl;
	
	//ispisite samo neparne vrijednosti koje se nalaze u listi
	//1.nacin
	for (auto it = brojevi.begin(); it != brojevi.end(); ++it) {
		std::cout << *it << " ";
		//mozemo direktno povecati iterator
		//++it;
		//ili napredovati po njemu za kolicinu zeljenih mjesta
		std::advance(it, 1);
	}
	std::cout << std::endl;
	//2. nacin
	for_each(brojevi.begin(), brojevi.end(), print_odd);
	std::cout << std::endl;

	//kreirajte forward_list i u nju prepisite samo parne brojeve iz liste
	std::forward_list<int> parni;
	for (auto it = brojevi.begin(); it != brojevi.end(); ++it) {
		std::advance(it, 1);
		parni.push_front(*it);
	}

	//iz forward_liste izbacite broj 10 i ispisite prvi broj
	//parni.pop_front();
	//ili:
	parni.remove(10);
	std::cout << "prvi parni broj: " << parni.front() << std::endl;

	//ispisite brojeve iz forward_liste koristeci for_each 
	for_each(parni.begin(), parni.end(), print);
	std::cout << std::endl;

	//izbrisite sadrzaj forward_liste (jedan po jedan element)
	while (!parni.empty()) {
		parni.pop_front();
	}

	//iz liste izbrisite sve elemente odjednom i ispišite size()
	//brojevi.clear();
	brojevi.erase(brojevi.begin(), brojevi.end());
	std::cout << "brojevi size(): " << brojevi.size() << std::endl;
}