#pragma once

#include "Comp.h"

class List {

public:

	class Store {
	public:
		Interf* obj;
		Store* Next;
		Store* Back;

		//конструктор бех аргументов
		Store() {
			obj = nullptr;
			Next = nullptr;
			Back = nullptr;
		}

		//конструктор с аргументом
		Store(Interf* obj) {
			this->obj = obj;
			Next = nullptr;
			Back = nullptr;
		};

		~Store() {
			if (obj != nullptr) delete obj;
			if (Back != nullptr) Back = nullptr;
			if(Next != nullptr) delete Next;
			Next = nullptr;
		}
	};

	
	Store* store; //хранилище наших данных
	Store* step;  //переменная для функции GetNext (вывода значений на экран)


	//конструктор без аргументов
	List() {
		store = new Store;
	}


	//добавляем объект по данному индексу
	void InsertAt(Interf* obj, int ind) {

		//указатель на первую переменную
		Store* ptr = store->Next;

		if (ind < 0) {
			std::cout << "Индекс не может быть меньше 0" << std::endl;
		}

		//если удаляем 1-ый объект
		if (ind == 0) {

			Store* tmp = new Store(obj);
			tmp->Next = ptr;
			tmp->Back = nullptr;

			if(ptr != nullptr && ptr->Back != nullptr) ptr->Back = tmp;

			store->Next = tmp;
			return;
		}

		//поиск
		while (ind - 1 > 0) {
			if (ptr == nullptr) {
				std::cout << "Данный индекс превышает размер листа" << std::endl;
				return; // выходим из функции
			}

			ptr = ptr->Next;
			ind--;
		}

		if (ptr == nullptr) {
			std::cout << "Данный индекс превышает размер листа" << std::endl;
			return; // выходим из функции
		}

		Store* tmp = new Store(obj);

		//добавляем наше значение
		if (ptr->Next != nullptr) {
			ptr->Next->Back = tmp;
		}
		tmp->Next = ptr->Next;
		tmp->Back = ptr;
		ptr->Next = tmp;

		//шаг переходит в начало
		step = store->Next;
	}

	//удаляем объект
	void DeleteAt(int ind) {

		if (ind < 0) {
			std::cout << "Индекс не может быть меньше 0" << std::endl;
		}

		if (store->Next == nullptr) {
			std::cout << "Лист пуст" << std::endl;
			return;
		}

		Store* ptr = store->Next;

		//если удаляем 1-ый объект
		if (ind == 0) {
			delete store->Next->obj;
			if(ptr->Next != nullptr) store->Next = ptr->Next;
			ptr->Back = nullptr;
			if(ptr->Next != nullptr) ptr->Next->Back = nullptr;
			
			return;
		}
		
		//поиск
		while (ind - 1 > 0) {
			if (ptr->Next != nullptr) {
				std::cout << "Данный индекс превышает размер листа" << std::endl;
				return; // выходим из функции
			}

			ptr = ptr->Next;
			ind--;
		}

		if (ptr == nullptr || ptr->Next == nullptr) {
			std::cout << "Данный индекс превышает размер листа" << std::endl;
			return; // выходим из функции
		}

		//удаляем объект
		delete ptr->Next->obj;

		if (ptr->Next->Next != nullptr) {
			ptr->Next->Next->Back = ptr;
		}
		ptr->Next = ptr->Next->Next;
	}

	//выводим первый объект
	Interf* Get_First() {
		return step->obj;
	}

	//выводим следующий объект после указанного, если он есть в списке
	Interf* Get_Next(Interf* obj) {
		if (step->Next == nullptr) {
			std::cout << "Лист закончился" << std::endl;
			step = store->Next;
			return nullptr;
		}
		return (step = step->Next)->obj;
	}

	void Draw() {

		Store* tmp = store->Next;

		if (store->Next == nullptr) {
			std::cout << "Лист пуст" << std::endl;
			return;
		}

		while (1) {

			if (tmp == nullptr) break;

			tmp->obj->Get_brand();
			tmp = tmp->Next;
		}
	}

	~List() {

		while (store != nullptr && store->Next != nullptr) {
			delete store;
			store = nullptr;
			step = nullptr;
		}
	}

};
