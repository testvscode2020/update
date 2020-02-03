#include <iostream>
#include <vector>

/*
Ubacite 500 cijelih brojeva u vektor 
(1 po 1) i ispišite koliko puta je vektor rastao.
*/


int main() {
	
	std::vector<int> v;
	//ako odmah rezerviramo dovoljan kapacitet, vektor nece rasti i mozemo izbjeci rast!
	//v.reserve(500);

	int rastao = 0;
	int last_capacity = v.capacity();
	//std::cout << last_capacity << std::endl;
	for (unsigned i = 0; i < 500; i++) {
		v.push_back(i);
		if (last_capacity != v.capacity()) {
			rastao++;
			last_capacity = v.capacity();
			//std::cout << last_capacity << std::endl;
		}
	}

	std::cout << "Vector je rastao " << rastao << " puta" << std::endl;

	return 0;
}
