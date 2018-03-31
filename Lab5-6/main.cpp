#include "UI.h"
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void testOperator()
{
	DynamicVector<int> v{ 5 };
	v = v + 3;
	v.add(2);
	v.add(4);
	v = 6 + v;
	assert(v.getSize() == 4);
	assert(v[0] == 3);
	assert(v[2] == 4);
}

int main()
{
	system("color 09");
	testOperator();

	Repository repo{};

	Doggie d1{ "Ralf", "Saint Bernand", 3, "https://cdn.shopify.com/s/files/1/1133/5028/files/st-bernard-dog-alps.jpg?v=1488930943" };
	Doggie d2{ "Buddy", "Corgi", 1, "https://upload.wikimedia.org/wikipedia/commons/thumb/2/2b/WelshCorgi.jpeg/220px-WelshCorgi.jpeg" };
	Doggie d3{ "Martin", "Corgi", 2, "http://www.pawculture.com/uploads/versions/murray-corgi-butts---x----557-556x---.jpg" };
	Doggie d4{ "Bobby", "Chihuahua", 4, "https://www.puppiesclub.com/wp-content/uploads/2017/06/chihuahua-puppy-funny-face-5.jpg" };
	Doggie d5{ "Sebastian", "The hedgehog", 2, "https://assets.change.org/photos/6/qi/uw/qSqiuWpIeJeDCZW-1600x900-noPad.jpg?1520990123" };
	int r=repo.addDoggie(d1);
	repo.addDoggie(d2);
	repo.addDoggie(d3);
	repo.addDoggie(d4);
	repo.addDoggie(d5);

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}