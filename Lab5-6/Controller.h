#pragma once
#include "DoggieList.h"
#include "Repository.h"

class Controller
{
private:
	Repository repo;
	DoggieList doggieList;

public:
	Controller(const Repository& r) : repo(r) {}
	Repository getRepo() const { return repo; }
	DoggieList getDoggieList() const { return doggieList; }

	int addDoggieToRepository(const std::string& name, const std::string& breed, int age, const std::string& picture);
	void deleteADoggieFromRepo(const std::string& name, const std::string& breed);

	void addDoggieToDoggieList(const Doggie& dog);

	void showTheDoggie();
	void nextDoggieInDoggieList();

	int updateTheName(const std::string& newName ,const std::string& name, const std::string& breed);
	int updateTheBreed(const std::string& name, const std::string& breed, const std::string& newBreed);
	int updateTheAge(const std::string& name, const std::string& breed, int age);
};
