#include "DoggieList.h"

DoggieList::DoggieList()
{
	this->current = 0;
}

void DoggieList::add(const Doggie& dog)
{
	this->doggies.add(dog);
}

Doggie DoggieList::getCurrentDog()
{
	if (this->current == this->doggies.getSize())
		this->current = 0;
	return this->doggies[this->current];
}

void DoggieList::seeDogs()
{
	if (this->doggies.getSize() == 0)
		return;
	this->current = 0;
	Doggie currentDoggie = this->getCurrentDog();
	currentDoggie.showPhoto();
}

void DoggieList::next()
{
	if (this->doggies.getSize() == 0)
		return;
	this->current++;
	Doggie currentDoggie = this->getCurrentDog();
	currentDoggie.showPhoto();
}

bool DoggieList::isEmpty()
{
	return this->doggies.getSize() == 0;
}