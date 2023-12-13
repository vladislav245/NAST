#include<iostream>
#include<cstring>
#include<clocale>

class Comp {
public:
	Comp();
	Comp(std::string brand) { this->brand = brand; };
	void Input();
	void Output() const;
	
	std::string brand;
private:
	int memorySize;
};

class Derived1 : public Comp {
public:
	Derived1();
	Derived1(std::string brand) : Comp(brand) { };
	void Input();
	void Output() const;

private:
	int screenSize;
};

class Derived2 : public Comp {
public:
	Derived2();
	Derived2(std::string brand) : Comp(brand) { };
	void Input();
	void Output() const;

private:
	int weight;
};

class Derived3 : public Derived2 {
public:
	Derived3();
	Derived3(std::string brand) : Derived2(brand) { };
	void Input();
	void Output() const;


	bool operator <= (std::string str);
	bool operator <= (Comp& obj);

	void operator -= (std::string str);
	void operator -= (Comp& obj);

private:
	int batteryCapacity;
};
