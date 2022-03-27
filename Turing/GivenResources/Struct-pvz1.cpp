#include <iostream>  // cout
#include <string>

using namespace std;

struct films{
	string title;
	int year;
};

films film1, film2;

int main() {
	
	film1 = {"Alien", 1979};
	
	film2.title = "The Raid";
	film2.year = 2012;
	
	cout << "Filmas nr. 1: " << film1.title << " " << film1.year << endl;
	cout << "Filmas nr. 2: " << film2.title << " " << film2.year << endl;
    return 0;
}
