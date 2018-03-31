#pragma once
#include <iostream>
 
class Doggie
{
private:
	std::string name;
	std::string breed;
	int age;
	std::string picture;

public:
	Doggie();
	Doggie::Doggie(const std::string& name, const std::string& breed, const int& age, const std::string& picture);

	std::string getName() const { return name; }
	std::string getBreed() const { return breed; }
	std::string getPicture() const { return picture; }
	void setName(const std::string& name);
	void setBreed(const std::string& breed);
	void setAge(int age);
	int getAge() const { return age; }
	void showPhoto();
};