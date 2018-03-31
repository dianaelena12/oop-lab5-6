#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printDoggieListMenu();

	void addDoggieToRepo();
	void deleteADoggie();
	void addDoggieToDoggieList();
	void seeAllDoggiesInRepo();
	void update();
};
