#include "MathIsFun.h"

/*
 * Calculates the largest integer less or equal than the square root of x.
 * funSqrt(10) = 3
 * funSqrt(16) = 4
 * @param x - An integer for which the function applies
 * @return the value of |_sqrt(x)_|, if x is negative then the function
 * returns -1.
 */
/*int funSqrt(int x); // ==> Declaration is always in the beginning of the file.*/
int funPow(int x, int n, int d) {
	int half_mod;
	if (x < 0)
		x = x + d;
	if (n == 0)
		return 1;
	else if (n % 2 == 0) { /* n is even */
		half_mod = funPow(x, n / 2, d);
		return ((half_mod * half_mod) % d); /* a*b % d = (((a%d) * (b%d))%d) */
	} else { /* n is odd */
		return ((funPow(x, n - 1, d) * (x % d))%d); /* (x^n * x) % d = (((x^n % d) * (x % d)) % d) */
	}

}

int funSqrt(int x) {
	int start = 0, mid, end = x;
	if (x < 0) 	/* if x is negative then we return -1 */
		return -1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (((mid * mid) <= x) && (x <= ((mid + 1) * (mid + 1)))) /*we found the requested root - it's mid or excactly mid+1 */
			if ((mid + 1) * (mid + 1) == x)
				return mid + 1;
			else
				return mid;
		else if ((mid * mid) > x) 		/*we go to the left side - we'll search the root between 0 to mid-1 */
			end = mid-1;
		else					 /*we go to the right side - we'll search the root between mid+1 to end */
			start = mid+1;
	}
	return 0; /* shouldn't be here */
}

bool funPrimeCheck(int x) {
	int i, sqrt = funSqrt(x);
	if (x < 0)
		return -1;
	for (i = 2; i <= sqrt; i++)
		/*for (i=2; i<=funSqrt(x); i++) - isn't good because we evaluate every time the function*/
		if (x % i == 0)
			return false;
	return true;
}

bool funPalindromeCheck(int x) {
	/* We build the reverse number from the original number*/
	/*and then we will check if the original number equals to the reverse number*/

	int num = x, reverse_num = 0;
	if (x < 0) /*negative numbers are not palindromes*/
		return false;
	while (num > 0) {
		reverse_num = (reverse_num * 10) + (num % 10);
		num = num / 10;
	}
	if (x == reverse_num)
		return true;
	else
		return false;
}
