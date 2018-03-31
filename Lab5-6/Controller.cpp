#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

int Controller::addDoggieToRepository(const std::string& name, const std::string& breed, int age, const std::string& picture)
{
	Doggie d{ name, breed, age, picture };
	return this->repo.addDoggie(d);
}

void Controller::addDoggieToDoggieList(const Doggie& dog)
{
	this->doggieList.add(dog);
}

void Controller::deleteADoggieFromRepo(const std::string& name, const std::string& breed)
{
	this->repo.deleteDoggie(name, breed);
}

void Controller::showTheDoggie()
{
	this->doggieList.seeDogs();
}

void Controller::nextDoggieInDoggieList()
{
	this->doggieList.next();
}

int Controller::updateTheName(const std::string& newName,const std::string& name, const std::string& breed)
{
	return this->repo.updateName(newName,name, breed);
}

int Controller::updateTheBreed(const std::string& name, const std::string& breed, const std::string& newBreed)
{
	return this->repo.updateBreed(name, breed, newBreed);
}

int Controller::updateTheAge(const std::string& name, const std::string& breed, int age)
{
	return this->repo.updateAge(name, breed, age);
}