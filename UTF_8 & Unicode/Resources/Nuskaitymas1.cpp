#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main ()
{
	FILE* file;
	file = fopen ("input.txt","r");
	
	FILE* output;
	output = fopen ("output.txt","w");
	
	unsigned char symbol;

	while (!feof(file)){
		symbol = fgetc(file);
		cout<< int(symbol)<< endl;
		fprintf(output,"%c", symbol);
 	}
  
  	fclose(file);  
	fclose(output);

  	return 0;
}
