/* 
    Duoti du skaiciai - a ir b (a,b <255 - 1 baitas)
	Sudarykite nauja skaiciu: 
		1,2,3 bitai bus pirmo skaiciaus a 3,4,5 bitai,
	    4,5,6 bitai bus antro skaiciaus 1,2,3 bitai,
	    7,8 bitai bus visada 11.
	
	sablonas: 11bbbaaa
*/

#include <iostream>
#include <stdio.h>  // printf

int main() {

	int a = 84;     // 0101 0100
	int b = 206;    // 1100 1110
	int c;         
	int temp;
	
	c = 0b11000000;  // kauke
	
	temp = a & 0b00011100;	// 0001 0100 - pasiimame 3-4-5 bitus, isvalome nereikalingus
	temp = temp >> 2;       // 0000 0101 - pastumiame i vieta, kuria reiks ideti
	c = c | temp;			// 1100 0101 - pridedame prie kaukes
	
	temp = b & 0b00000111; 	// 0000 0110 - pasiimame 1-2-3 bitus, isvalome nereikalingus
	temp = temp << 3;  		// 0011 0000 - pastumiame i vieta, kuria reiks ideti
	c = c | temp;           // 1111 0101 - pridedame prie kaukess   
	
	printf("Pradiniai skaiciai: %d %d \n", a, b);
	printf("Atsakymas: %d ", c); //245 - 1111 0101
    return 0;
}
