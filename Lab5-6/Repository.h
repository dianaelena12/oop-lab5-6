#pragma once
#include "Doggo.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<Doggie> doggies;

public:

	Repository() {}

	int addDoggie(const Doggie& d);
	void deleteDoggie(const std::string& name, const std::string& breed);
	int updateName(const std::string& newName,const std::string& name, const std::string& breed);
	int updateBreed(const std::string& name, const std::string& breed, const std::string& newBreed);
	int updateAge(const std::string& name, const std::string& breed, int age);

	Doggie findDoggieByNameAndBreed(const std::string& name, const std::string& breed);
	DynamicVector<Doggie> getDoggies() const { return doggies; }
};