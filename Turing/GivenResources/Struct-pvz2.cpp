#include <iostream>  // cout, cin
#include <string>
#include <iomanip>   // setw

using namespace std;

/*
========== Matyti filmai =============
*/

struct films{
	string title;
	int year;
	int rating;
	bool recommend;
} seenFilms[10];


int main() {
	int n;
	
	cout << "-----------------------------\n";
 	cout << "   Matytu filmu saras \n";
 	cout << "-----------------------------\n";
 	cout << "Kiek filmu matete? (n<11) \n";
 	cin >> n;
 	
 	for (int i=0; i<n; i++){
 		cout <<"\n-----------------------------\n";
 		cout <<"Iveskite " << i+1 << " filmo informacija \n";
 		cout <<"-----------------------------\n";
 		cout << "Pavadinimas: ";
 	    cin  >> seenFilms[i].title;
 	    cout << "metai: ";
 	    cin  >> seenFilms[i].year;
 	    cout << "ivertinimas: ";
 	    cin  >> seenFilms[i].rating;
 	    cout << "ar rekomenduojamas? (1/0): ";
 	    cin  >> seenFilms[i].recommend;
	 }
	
	
 	// PATIKRINIMAS
    cout << "\n Filmai: \n";
    cout << "|---------------|---------|-------------|---------|\n";
    cout << setw(16) << "Pavadinimas";
    cout << setw(10) << "Metai";
    cout << setw(14) << "Ivertinimas";
    cout << setw(10) << "Geras?\n";
    cout << "|---------------|---------|-------------|---------|\n";

 	for (int i=0; i<n; i++){
 		cout << setw(16) << seenFilms[i].title;
    	cout << setw(10) << seenFilms[i].year;
    	cout << setw(14) << seenFilms[i].rating;
    	cout << setw(10) << seenFilms[i].recommend << endl;
	}
	cout << "|---------------|---------|-------------|---------|\n";
    return 0;
}
