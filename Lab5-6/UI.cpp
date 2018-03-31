#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage dogs in repository." << endl;
	cout << "2 - Manage doggie list." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands:  " << endl;
	cout << "\t 1 - Add a dog." << endl;
	cout << "\t 2 - Display all dogs." << endl;
	cout << "\t 3 - Update the info of a dog" << endl;
	cout << "\t 4 - Delete a dog from repository." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printDoggieListMenu()
{
	cout << "Possible commands:  " << endl;
	cout << "\t 1 - Add a dog." << endl;
	cout << "\t 2 - See all doggies." << endl;
	cout << "\t 3 - Next." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addDoggieToRepo()
{
	cout << "Enter the name of the canine: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed of the canine: ";
	std::string breed;
	getline(cin, breed);
	int age = 0;
	cout << "Enter it's age: ";
	cin >> age;
	cin.ignore();
	cout << "Input the link containing it's photograph: ";
	std::string picture;
	getline(cin, picture);

	int r = this->ctrl.addDoggieToRepository(name, breed, age, picture);
	if (r == 0)
	{
		cout << "This dog allready exists in our database!"<<endl;
		return;
	}
	else
	{
		cout << "Successfully added informations :)"<<endl;
		return;
	}

}

void UI::deleteADoggie()
{
	cout << "Enter the name of the canine: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed of the canine: ";
	std::string breed;
	getline(cin, breed);

	this->ctrl.deleteADoggieFromRepo(name, breed);
}

void UI::seeAllDoggiesInRepo()
{
	DynamicVector<Doggie> doggies = this->ctrl.getRepo().getDoggies();
	if (doggies.getSize() == 0)
	{
		cout << "There are no doggies in the repository :(" << endl;
		return;
	}
	for (int i = 0; i < doggies.getSize(); i++)
	{
		Doggie dog = doggies[i];
		cout << dog.getName() << " - " << dog.getBreed() << " - " << dog.getAge() << endl;
	}
}

void UI::addDoggieToDoggieList()
{
	cout << "Enter the doggie's name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the doggie's breed: ";
	std::string breed;
	getline(cin, breed);
	Doggie d = this->ctrl.getRepo().findDoggieByNameAndBreed(name, breed);
	if (d.getBreed() == "" && d.getName() == "")
	{
		cout << "There is no doggy with the given data in the repository!"<<endl;
		return;
	}

	this->ctrl.addDoggieToDoggieList(d);
}

void UI::update()
{
	cout << endl;
	cout << "\t1 - Update the name" << endl;
	cout << "\t2 - Update the breed" << endl;
	cout << "\t3 - Update the age" << endl;
	cout << "\t0 - Get back." << endl;
	cout << endl;
	int command{ 0 };
	cout << "Input the command: ";
	cin >> command;
	cin.ignore();
	switch (command)
	{
	case 0:
		return;
	case 1:
	{
		cout << "Enter the doggie's name: ";
		std::string name;
		getline(cin, name);
		cout << "Enter the doggie's breed: ";
		std::string breed;
		getline(cin, breed);
		cout << "Enter the doggie's new name: ";
		std::string newname;
		getline(cin, newname);
		Doggie d = this->ctrl.getRepo().findDoggieByNameAndBreed(name, breed);
		if (d.getBreed() == "" && d.getName() == "")
		{
			cout << "There is no doggy with the given data in the repository!" << endl;
			break;
		}
		int result = this->ctrl.updateTheName(newname,name, breed);
		if (result == 0)
		{
			cout << "Fail at updating the name, check your data!" << endl;
			return;
		}
		else
			cout << "Updated successfully!" << endl;
		return;
	}
	case 2:
	{
		cout << "Enter the doggie's name: ";
		std::string name;
		getline(cin, name);
		cout << "Enter the doggie's breed: ";
		std::string breed;
		getline(cin, breed);
		cout << "Enter the doggie's new breed: ";
		std::string newbreed;
		getline(cin, newbreed);
		Doggie d = this->ctrl.getRepo().findDoggieByNameAndBreed(name, breed);
		if (d.getBreed() == "" && d.getName() == "")
		{
			cout << "There is no doggy with the given data in the repository!" << endl;
			break;
		}
		int result = this->ctrl.updateTheBreed(name, breed, newbreed);
		if (result == 0)
		{
			cout << "Fail at updating the name, check your data!" << endl;
			return;
		}
		else
			cout << "Updated successfully!" << endl;
		return;

	}
	case 3:
	{
		cout << "Enter the doggie's name: ";
		std::string name;
		getline(cin, name);
		cout << "Enter the doggie's breed: ";
		std::string breed;
		getline(cin, breed);
		cout << "Enter the doggie's age: ";
		int age;
		cin >> age;
		cin.ignore();
		Doggie d = this->ctrl.getRepo().findDoggieByNameAndBreed(name, breed);
		if (d.getBreed() == "" && d.getName() == "")
		{
			cout << "There is no doggy with the given data in the repository!" << endl;
			break;
		}
		int result = this->ctrl.updateTheAge(name, breed, age);
		if (result == 0)
		{
			cout << "Fail at updating the name, check your data!" << endl;
			return;
		}
		else
			cout << "Updated successfully!" << endl;
		return;
	}
	}
}

void UI::run()
{
	while (true)
	{
		system("cls");
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		if (command == 1)
		{
			while (true)
			{
				system("cls");
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
				{
					this->addDoggieToRepo();
					system("pause");
					break;
				}
				case 2:
				{
					this->seeAllDoggiesInRepo();
					system("pause");
					break;
				}
				case 3:
				{
					this->update();
					system("pause");
					break;
				}
				case 4:
				{
					this->deleteADoggie();
					system("pause");
					break;
				}
				}
			}
		}
		if (command == 2)
		{
			while (true)
			{
				system("cls");
				UI::printDoggieListMenu();
				int commandList{ 0 };
				cout << "Input the command: ";
				cin >> commandList;
				cin.ignore();
				if (commandList == 0)
					break;
				switch (commandList)
				{
				case 1:
				{
					this->addDoggieToDoggieList();
					system("pause");
					break;
				}
				case 2:
					system("pause");
					break;
				}
			}
		}
	}
}