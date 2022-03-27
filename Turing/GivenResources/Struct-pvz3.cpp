#include <iostream>  // cout, cin
#include <string>
#include <iomanip>   // setw

using namespace std;

/*
========== Matyti filmai =============
*/

struct rating{
	int cinematography;
	int acting;
	int ost;
};

struct films{
	string title;
	int year;
	struct rating rate;
	bool recommend;
};

films seenFilm;

int main() {
	
	seenFilm.title="Cube";
	seenFilm.year= 1998;
	seenFilm.recommend = true;
	seenFilm.rate.cinematography = 8;
	seenFilm.rate.acting = 9;
	seenFilm.rate.ost = 8;
 	
    cout << "Pavadinimas: " << seenFilm.title << endl;
    cout << "Metai: " << seenFilm.year << endl;
    cout << "Vertinimas: \n";
    cout << "Kinematografija: " << seenFilm.rate.cinematography << endl;
    cout << "Vaidyba: " << seenFilm.rate.acting << endl;
    cout << "Garso takelis: " << seenFilm.rate.ost << endl;
    cout << "Ar rekomeduoji?: " << seenFilm.recommend << endl;
  
    return 0;
}
