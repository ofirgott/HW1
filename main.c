#include <stdio.h>
#include "MathIsFun.h"

int main() {
	int answer, x, n, d;	
	printf("Welcome to Math Is Fun - beta version\n");
	printf("Supported operations are:\n");
	printf("1 - Power Calculation\n");
	printf("2 - Prime Check\n");
	printf("3 - Palindrome Check\n");
	printf("Please enter operation number (1/2/3): \n");
	scanf("%d", &answer);
	switch (answer) {
	case 1: /* Power calculation*/
		printf("Please enter three space separated numbers: \n");
		scanf("%d %d %d", &x, &n, &d);
		printf("res = %d\n", funPow(x, n, d));
		break;
	case 2: /*prime test*/
		printf("Please enter an integer: \n");
		scanf("%d", &x);
		if (funPrimeCheck(x)) /* x is prime*/
			printf("res = true\n");
		else
			printf("res = false\n");
		break;

	case 3: /*Palindrome test*/
		printf("Please enter an integer: \n");
		scanf("%d", &x);
		if (funPalindromeCheck(x)) /* x is Palindrome*/
			printf("res = true\n");
		else
			printf("res = false\n");
		break;
	default: /*error*/
		printf("ERROR");
		return 0;
		break;
	}
	return 0; 
}
