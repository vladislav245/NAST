#include<iostream>
#include<cstring>
#include<clocale>


class Interf {
public:
	virtual void Input() = 0;
	virtual void Output() const = 0;
	virtual ~Interf() { };
};

class Comp : public Interf {
public:
	Comp();
	Comp(std::string brand) { this->brand = brand; };
	virtual void Input();
	virtual void Output() const;

	virtual ~Comp() { };

	std::string brand;
private:
	int memorySize;
};

class Derived1 : public Comp {
public:
	Derived1();
	Derived1(std::string brand) : Comp(brand) { };
	virtual void Input();
	virtual void Output() const;
	virtual ~Derived1() { };
private:
	int screenSize;
};

class Derived2 : public Comp {
public:
	Derived2();
	Derived2(std::string brand) : Comp(brand) { };
	virtual void Input();
	virtual void Output() const;
	virtual ~Derived2() { };
private:
	int weight;
};

class Derived3 : public Derived2 {
public:
	Derived3();
	Derived3(std::string brand) : Derived2(brand) { };
	virtual void Input();
	virtual void Output() const;


	bool operator <= (std::string str);
	bool operator <= (Comp& obj);

	void operator -= (std::string str);
	void operator -= (Comp& obj);
	virtual ~Derived3() { };
private:
	int batteryCapacity;
};
