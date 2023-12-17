#include "comp.h"

Comp::Comp() {
	brand = "";
	memorySize = 0;
}

void Comp::Input() {
	std::cout << "----------------------------" << std::endl;
	std::cout << "Введите марку компьютера:" << std::endl;
	std::cin >> brand;
	std::cout << "Введите размер памяти:" << std::endl;
	std::cin >> memorySize;
}

void Comp::Output() const {
	std::cout << "Марка компьютера: " << brand << std::endl;
	std::cout << "Размер памяти: " << memorySize << std::endl;
}




void Comp::Serialize(std::fstream& f) {
	f << brand << std::endl;
	f << memorySize  << std::endl;
}
void Comp::Deserialize(std::fstream& f) {
	char buffer[256];

	for (int i = 0; i < 2; i++) {
		f >> buffer;

		if (i == 0) {
			brand = buffer;
		}
		else if (i == 1) {
			this->memorySize = atoi(buffer);
		}
	}
}



Derived1::Derived1() : Comp() {
	screenSize = 0;
}

void Derived1::Input() {
	Comp::Input();

	std::cout << "Введите размер экрана:" << std::endl;
	std::cin >> screenSize;
}

void Derived1::Output() const {
	Comp::Output();

	std::cout << "Размер экрана: " << screenSize << std::endl;
}

void Derived1::Serialize(std::fstream& f) {
	f << screenSize << std::endl;
}
void Derived1::Deserialize(std::fstream& f) {
	char buffer[256];

	f >> buffer;
	this->screenSize = atoi(buffer);
}


Derived2::Derived2() : Comp() {
	weight = 0;
}

void Derived2::Input() {
	Comp::Input();

	std::cout << "Введите вес:" << std::endl;
	std::cin >> weight;
}

void Derived2::Output() const {
	Comp::Output();

	std::cout << "Вес: " << weight << std::endl;
}

void Derived2::Serialize(std::fstream& f) {
	f << weight << std::endl;
}
void Derived2::Deserialize(std::fstream& f) {
	char buffer[256];

	f >> buffer;
	this->weight = atoi(buffer);
}


Derived3::Derived3() : Derived2() {
	batteryCapacity = 0;
}

void Derived3::Input() {
	Derived2::Input();

	std::cout << "Введите емкость аккумулятора:" << std::endl;
	std::cin >> batteryCapacity;
}

void Derived3::Output() const {
	Derived2::Output();

	std::cout << "Емкость аккумулятора: " << batteryCapacity << std::endl;
}


void Derived3::Serialize(std::fstream& f) {
	f << batteryCapacity << std::endl;
}
void Derived3::Deserialize(std::fstream& f) {
	char buffer[256];

	f >> buffer;
	this->batteryCapacity = atoi(buffer);
}


bool Derived3::operator <= (std::string str) {

	for (int i = 0; i < 5; i++) {

		if (str[i] == '\0' || brand[i] == '\0') return 1;

		if (brand[i] <= str[i]) return 1;
		else return 0;
	}
}
bool Derived3::operator <= (Comp& obj) {
	for (int i = 0; i < 5; i++) {

		if (obj.brand[i] == '\0' || brand[i] == '\0') return 1;

		if (brand[i] <= obj.brand[i]) continue;
		else return 0;
	}
}

void Derived3::operator -= (std::string str) {
	brand += str;
}

void Derived3::operator -= (Comp& obj) {
	brand += obj.brand;
}