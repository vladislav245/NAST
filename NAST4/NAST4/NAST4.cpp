#include "Comp.h"
#include "List.cpp"


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


	factory->add<Comp>("Comp");
	factory->add<Derived1>("Derived1");
	factory->add<Derived2>("Derived2");
	factory->add<Derived3>("Derived3");




	List* list = new List;

	
	Interf* PTR = new Comp("A");
	list->InsertAt(PTR, 0);
	PTR = new Comp("B");
	list->InsertAt(PTR, 1);
	PTR = new Comp("C");
	list->InsertAt(PTR, 2);
	PTR = new Comp("D");
	list->InsertAt(PTR, 3);
	PTR = new Comp("E");
	list->InsertAt(PTR, 4);
	PTR = new Comp("F");
	list->InsertAt(PTR, 5);

	list->DeleteAt(0);
	list->DeleteAt(4);

	list->Draw();

	list->Serialize("data.txt");

	delete list;

	list = new List;

	list->Deserialize("data.txt");
	std::cout << std::endl << std::endl;
	list->Draw();

	getchar();
	getchar();
	return 0;
}
