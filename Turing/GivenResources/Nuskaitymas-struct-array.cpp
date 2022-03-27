#include <iostream>  // cout, cin
#include <fstream>   // document.open close
#include <string>
#include <iomanip>   // setw

using namespace std;


struct films{
	string title;
	int year;
	string rating;
};
films seenFilms[100]; //statinis  masyvas


int main() {
	
	ifstream dokumentas;
  	dokumentas.open ("Filmai.txt");
  	
  	int n=0;
  	while (!dokumentas.eof()){
  		dokumentas >> seenFilms[n].title;
  		dokumentas >> seenFilms[n].year;
	    dokumentas >> seenFilms[n].rating;
	    n++;
	  }
 	dokumentas.close();
 	
 	//tikriname ar gerai nusiskaitem
	
 	cout << "\nFilmai: \n";
    cout << "|-------------------|---------|-------------|\n";
    cout << setw(20) << "Pavadinimas";
    cout << setw(10) << "Metai";
    cout << setw(14) << "Ivertinimas\n";
    cout << "|-------------------|---------|-------------|\n";

 	for (int i=0; i<n; i++){
 		cout << setw(20) << seenFilms[i].title;
    	cout << setw(10) << seenFilms[i].year;
    	cout << setw(14) << seenFilms[i].rating << endl;
	}
	cout << "|-------------------|---------|-------------|\n"; 	
 	 	
    return 0;
}

