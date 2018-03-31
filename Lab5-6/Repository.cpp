#include "Repository.h"
#include <string>

using namespace std;

int Repository::addDoggie(const Doggie& d)
{
	Doggie dog = findDoggieByNameAndBreed(d.getName(), d.getBreed());
	if (dog.getName() != "" && dog.getBreed() != "")
		return 0;
	this->doggies.add(d);
	return 1;
}

void Repository::deleteDoggie(const std::string& name, const std::string& breed)
{
	Doggie d = findDoggieByNameAndBreed(name, breed);
	if (d.getName() == "" && d.getBreed() == "")
		return;
	for(int i=0; i< this->doggies.getSize(); i++)
		if (this->doggies[i].getName() == d.getName() && this->doggies[i].getBreed() == d.getBreed())
		{
			this->doggies.deleteE(i);
			return;
		}
}

Doggie Repository::findDoggieByNameAndBreed(const std::string& name, const std::string& breed)
{
	for (int i = 0; i < this->doggies.getSize(); i++)
	{
		Doggie d = doggies[i];
		if (d.getName() == name && d.getBreed() == breed)
			return d;
	}

	return Doggie {};
}

int Repository::updateName(const std::string& newName,const std::string& name, const std::string& breed)
{
	for (int i = 0; i < this->doggies.getSize(); i++)
	{
		Doggie d = doggies[i];
		if (d.getName() == name && d.getBreed() == breed)
		{
			doggies[i].setName(newName);
			return 1;
		}
	}
	return 0;
}
int Repository::updateBreed(const std::string& name, const std::string& breed, const std::string& newBreed)
{
	for (int i = 0; i < this->doggies.getSize(); i++)
	{
		Doggie d = doggies[i];
		if (d.getName() == name && d.getBreed() == breed)
		{
			doggies[i].setBreed(newBreed);
			return 1;
		}
	}
	return 0;
}
int Repository::updateAge(const std::string& name, const std::string& breed, int age)
{
	for (int i = 0; i < this->doggies.getSize(); i++)
	{
		Doggie d = doggies[i];
		if (d.getName() == name && d.getBreed() == breed)
		{
			doggies[i].setAge(age);
			return 1;
		}
	}
	return 0;
}