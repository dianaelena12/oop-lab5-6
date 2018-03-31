#pragma once
#include "DynamicVector.h"
#include "Doggo.h"

class DoggieList
{
private:
	DynamicVector<Doggie> doggies;
	int current;

public:
	DoggieList();

	void add(const Doggie& dog);
	Doggie getCurrentDog();
	void seeDogs();
	void next();
	bool isEmpty();

};
