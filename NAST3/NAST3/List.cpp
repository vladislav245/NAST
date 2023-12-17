#pragma once

#include "Comp.h"

class List {

public:

	class Store {
	public:
		Interf* obj;
		Store* Next;
		Store* Back;

		//����������� ��� ����������
		Store() {
			obj = nullptr;
			Next = nullptr;
			Back = nullptr;
		}

		//����������� � ����������
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

	
	Store* store; //��������� ����� ������
	Store* step;  //���������� ��� ������� GetNext (������ �������� �� �����)


	//����������� ��� ����������
	List() {
		store = new Store;
	}


	//��������� ������ �� ������� �������
	void InsertAt(Interf* obj, int ind) {

		//��������� �� ������ ����������
		Store* ptr = store->Next;

		if (ind < 0) {
			std::cout << "������ �� ����� ���� ������ 0" << std::endl;
		}

		//���� ������� 1-�� ������
		if (ind == 0) {

			Store* tmp = new Store(obj);
			tmp->Next = ptr;
			tmp->Back = nullptr;

			if(ptr != nullptr && ptr->Back != nullptr) ptr->Back = tmp;

			store->Next = tmp;
			return;
		}

		//�����
		while (ind - 1 > 0) {
			if (ptr == nullptr) {
				std::cout << "������ ������ ��������� ������ �����" << std::endl;
				return; // ������� �� �������
			}

			ptr = ptr->Next;
			ind--;
		}

		if (ptr == nullptr) {
			std::cout << "������ ������ ��������� ������ �����" << std::endl;
			return; // ������� �� �������
		}

		Store* tmp = new Store(obj);

		//��������� ���� ��������
		if (ptr->Next != nullptr) {
			ptr->Next->Back = tmp;
		}
		tmp->Next = ptr->Next;
		tmp->Back = ptr;
		ptr->Next = tmp;

		//��� ��������� � ������
		step = store->Next;
	}

	//������� ������
	void DeleteAt(int ind) {

		if (ind < 0) {
			std::cout << "������ �� ����� ���� ������ 0" << std::endl;
		}

		if (store->Next == nullptr) {
			std::cout << "���� ����" << std::endl;
			return;
		}

		Store* ptr = store->Next;

		//���� ������� 1-�� ������
		if (ind == 0) {
			delete store->Next->obj;
			if(ptr->Next != nullptr) store->Next = ptr->Next;
			ptr->Back = nullptr;
			if(ptr->Next != nullptr) ptr->Next->Back = nullptr;
			
			return;
		}
		
		//�����
		while (ind - 1 > 0) {
			if (ptr->Next != nullptr) {
				std::cout << "������ ������ ��������� ������ �����" << std::endl;
				return; // ������� �� �������
			}

			ptr = ptr->Next;
			ind--;
		}

		if (ptr == nullptr || ptr->Next == nullptr) {
			std::cout << "������ ������ ��������� ������ �����" << std::endl;
			return; // ������� �� �������
		}

		//������� ������
		delete ptr->Next->obj;

		if (ptr->Next->Next != nullptr) {
			ptr->Next->Next->Back = ptr;
		}
		ptr->Next = ptr->Next->Next;
	}

	//������� ������ ������
	Interf* Get_First() {
		return step->obj;
	}

	//������� ��������� ������ ����� ����������, ���� �� ���� � ������
	Interf* Get_Next(Interf* obj) {
		if (step->Next == nullptr) {
			std::cout << "���� ����������" << std::endl;
			step = store->Next;
			return nullptr;
		}
		return (step = step->Next)->obj;
	}

	void Draw() {

		Store* tmp = store->Next;

		if (store->Next == nullptr) {
			std::cout << "���� ����" << std::endl;
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
