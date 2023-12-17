#pragma once

#include<iostream>
#include<cstring>
#include<clocale>
#include <fstream>
#include <map>

class Interf {
public:
	virtual void Input() = 0;
	virtual void Output() const = 0;
	virtual void Get_brand() const = 0;
	virtual void Serialize(std::fstream& f) = 0;
	virtual void Deserialize(std::fstream& f) = 0;
	virtual ~Interf() { };
};

class Comp : public Interf {
public:
	Comp();
	Comp(std::string brand) { this->brand = brand; };
	virtual void Input();
	virtual void Output() const;
	virtual void Get_brand() const { std::cout << brand << std::endl; };

	virtual void Serialize(std::fstream& f);
	virtual void Deserialize(std::fstream& f);

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

	virtual void Serialize(std::fstream& f);
	virtual void Deserialize(std::fstream& f);

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

	virtual void Serialize(std::fstream& f);
	virtual void Deserialize(std::fstream& f);

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

	virtual void Serialize(std::fstream& f);
	virtual void Deserialize(std::fstream& f);


	bool operator <= (std::string str);
	bool operator <= (Comp& obj);

	void operator -= (std::string str);
	void operator -= (Comp& obj);
	virtual ~Derived3() { };
private:
	int batteryCapacity;
};





class abstractFooCreator
{
public:
	virtual Interf* create() const = 0;
};


template <class C>
class fooCreator : public abstractFooCreator
{
public:
	virtual Interf* create() const { return new C(); }
};


class FooFactory
{
protected:
	typedef std::map<std::string, abstractFooCreator*> FactoryMap;
	FactoryMap _factory;


public:

	FooFactory() { };

	virtual ~FooFactory() { };


	template <class C>
	void add(const std::string& id)
	{
		typename FactoryMap::iterator it = _factory.find(id);

		if (it == _factory.end())
			_factory[id] = new fooCreator<C>();
	}


	Interf* create(const std::string& id)
	{

		typename FactoryMap::iterator it = _factory.find(id);

		if (it != _factory.end())
			return it->second->create();

		return 0;
	}

	bool find_id(const std::string& id) {

		typename FactoryMap::iterator it = _factory.find(id);

		if (it != _factory.end())
			return 1;

		return 0;
	}
};
