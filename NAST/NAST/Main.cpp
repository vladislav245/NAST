#include "Comp.h"



bool operator <= (std::string& ptr, Comp& obj1) {

	for (int i = 0; i < 5; i++) {

		if (ptr[i] == '\0' || obj1.brand[i] == '\0') return 1;

		if (ptr[i] <= obj1.brand[i]) return 1;
		else return 0;
	}

}


void operator -= (std::string& str, Comp& obj1) {
	str += obj1.brand;
}


int main() {
	setlocale(LC_ALL, "Russian");

	/*Comp* t[6];

	t[0] = new Derived1();
	t[0]->Input();

	t[1] = new Derived1();
	t[1]->Input();

	t[2] = new Derived2();
	t[2]->Input();

	t[3] = new Derived2();
	t[3]->Input();

	t[4] = new Derived3();
	t[4]->Input();

	t[5] = new Derived3();
	t[5]->Input();

	for (int i = 0; i < 6; i++) {
		t[i]->Output();
		delete t[i];
	}*/



	Derived3 a("ABC");
	Derived3 b("Z");
	Derived3 c("ZZ");
	Derived3 d("ABA");

	std::cout << (a <= b) << std::endl;
	std::cout << (b <= a) << std::endl;
	std::cout << (b <= c) << std::endl;
	std::cout << (a <= d) << std::endl;


	a -= b;
	c -= d;

	a.Output();
	c.Output();

	a -= c;

	a.Output();


	std::string ABC = "ABC";
	std::string ZZZZ = "ZZZZ";


	std::cout << (a <= ABC) << std::endl;
	std::cout << (b <= ZZZZ) << std::endl;
	std::cout << (ABC <= a) << std::endl;
	std::cout << (ZZZZ <= a) << std::endl;

	ABC -= a;

	std::cout << ABC << std::endl;

	getchar();
	getchar();
	return 0;
}
