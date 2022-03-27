#include <iostream>  // cout, cin
#include <fstream>   // document.open close
#include <string>
#include <iomanip>   // setw
#include <vector>  

using namespace std;


struct films{
	string title;
	int year;
	string rating;
};
vector<films> seenFilms; //sukuriamas tuscias vektorius


int main() {
	
	ifstream dokumentas;
  	dokumentas.open ("Filmai.txt");
  	
  	films temp; // sukuriame pagalbine struktura
  	
  	int n=0;
  	while (!dokumentas.eof()){
  		dokumentas >> temp.title;
  		dokumentas >> temp.year;
	    dokumentas >> temp.rating;
	    seenFilms.push_back(temp); // idedamas vektorius i gala
	  }
 	dokumentas.close();
 	
 	//tikriname ar gerai nusiskaitem
	
 	cout << "\nFilmai: \n";
    cout << "|-------------------|---------|-------------|\n";
    cout << setw(20) << "Pavadinimas";
    cout << setw(10) << "Metai";
    cout << setw(14) << "Ivertinimas\n";
    cout << "|-------------------|---------|-------------|\n";

 	for (int i=0; i<seenFilms.size(); i++){
 		cout << setw(20) << seenFilms[i].title;
    	cout << setw(10) << seenFilms[i].year;
    	cout << setw(14) << seenFilms[i].rating << endl;
	}
	cout << "|-------------------|---------|-------------|\n"; 	
 	 	
    return 0;
}

