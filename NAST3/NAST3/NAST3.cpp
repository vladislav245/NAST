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

	List list;

	char v = '-';
	int ind = 0;
	while (1) {

		v = '-';

		std::cout << "1 - Добавить объект" << std::endl;
		std::cout << "2 - Удалить объект" << std::endl;
		std::cout << "3 - Вывести все объекты" << std::endl;
		std::cout << "0 - закончить" << std::endl;
		
		std::cin >> v;

		if (v == '1') {

			std::cout << "1 - Comp" << std::endl;
			std::cout << "2 - Derived1" << std::endl;
			std::cout << "3 - Derived2" << std::endl;
			std::cout << "4 - Derived3" << std::endl;

			std::cin >> v;

			Interf* ptr;

			if (v == '1') {
				ptr = new Comp;
				ptr->Input();
			}

			else if (v == '2') {
				ptr = new Derived1;
				ptr->Input();
			}

			else if (v == '3') {
				ptr = new Derived2;
				ptr->Input();
			}

			else if (v == '4') {
				ptr = new Derived3;
				ptr->Input();
			}

			else {
				std::cout << "Данного варианта нет" << std::endl;
				continue;
			}


			std::cout << "Введите индекс" << std::endl;
			std::cin >> ind;

			list.InsertAt(ptr, ind);
		}

		else if (v == '2') {

			std::cout << "Введите индекс" << std::endl;
			std::cin >> ind;

			list.DeleteAt(ind);
		}

		else if (v == '3') {
			
			Interf* ptr = list.Get_First();

			while (ptr != nullptr) {
				ptr->Output();
				ptr = list.Get_Next(ptr);
			}
		}

		else if (v == '0') {
			break;
		}

		else {
			std::cout << "Данного варианта нет" << std::endl;
		}
	}

	getchar();
	getchar();
	return 0;
}
