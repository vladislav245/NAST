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


	Interf* PTR;

	PTR = new Comp("ABC");
	PTR->Output();
	delete PTR;

	PTR = new Derived1("GG");
	PTR->Output();
	delete PTR;
	

	PTR = new Derived2("FOF");
	PTR->Output();
	delete PTR;

	PTR = new Derived3("CAD");
	PTR->Output();
	delete PTR;

	getchar();
	getchar();
	return 0;
}
