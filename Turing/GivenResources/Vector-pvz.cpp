#include <iostream>  
#include <vector> // !!!

using namespace std;

int main()
{
  vector<int> Skaiciai;

  Skaiciai.push_back(13);     // 13
  Skaiciai.push_back(27);     // 13 27
  Skaiciai.insert(Skaiciai.begin(), 8);      // 8 13 27
  Skaiciai.push_back(1);      // 8 13 27 1

  // Vektoriaus elementu skaicius
  cout << "Vektoriaus elementu skaicius - " << Skaiciai.size() << endl;

  // Vektoriaus isvedimas
  for(int i = 0; i < Skaiciai.size(); i++){
  	cout << Skaiciai[i] << " ";
  }
  cout << endl;
 
 // Elementu trynimas -     8 13 27 1 
 Skaiciai.pop_back();    // 8 13 27
 Skaiciai.erase(Skaiciai.begin()+1);      // 8 27
  
 
  // Vektoriaus isvedimas
  for(int i = 0; i < Skaiciai.size(); i++){
  	cout << Skaiciai[i] << " ";
  } 
  
 return 0;
}

