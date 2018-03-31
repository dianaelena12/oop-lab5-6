#include "Doggo.h"
#include <Windows.h>
#include <shellapi.h>

Doggie::Doggie(): name(""), breed(""), age(0), picture("") {}

Doggie::Doggie(const std::string& name, const std::string& breed, const int& age, const std::string& picture)
{
	this->name = name;
	this->breed = breed;
	this->age = age;
	this->picture = picture;
}

void Doggie::setName(const std::string& name)
{
	this->name = name;
}

void Doggie::setBreed(const std::string& breed)
{
	this->breed = breed;
}

void Doggie::setAge(int age)
{
	this->age = age;
}

void Doggie::showPhoto()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPicture().c_str(), NULL, SW_SHOWMAXIMIZED);
}