#include <stdio.h> // printf

int main()
{

	int a = 11; // 1011
	int b = 5;	// 0101

	printf("a OR b = %d \n", a | b);
	printf("a AND b = %d \n", a & b);
	printf("NOT a = %d \n", ~a);
	printf("a XOR b = %d \n", a ^ b);
	printf("a >> 1 = %d \n", a >> 1);
	printf("a << 2 = %d \n", a << 2);

	return 0;
}
