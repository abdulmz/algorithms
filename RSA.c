#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int n) {
	int i;
	int m = n / 2;
	for (i = 2; i <= m; i++) {
		if (n % i == 0) {
			return 0; 
		}
	}
	return 1;
}

int getGCD(int n1, int n2) {
	int i, gcd;

	for(i = 1; i <= n1 && i <= n2; ++i) {
		if(n1 % i == 0 && n2 % i == 0)
			gcd = i;
	}

	return gcd;
}

int rsa(int a, int b, int n) {
	long long x = 1, y = a;

	while (b > 0) {
		if (b % 2 == 1)
			x = (x * y) % n;
		y = (y * y) % n; 
		b /= 2;
	}

	return x % n;
}

int main(int argc, char* argv[]) {
	int prime1, prime2;
	int n, prod;
	int data, cipher, decrypt;
	while (1) {
		printf("Enter the two prime numbers:");
        scanf("%d",&prime1);
        scanf("%d",&prime2);

        if (isPrime(prime1) && isPrime(prime2))
            break;
        else
            printf("Please Enter Prime Numbers!\n");
	}
	
	n = prime1 * prime2;
	prod = (prime1 - 1) * (prime2 - 1);

	int e = 0;
	for (e = 5; e <= 100; e++) {
		if (getGCD(prod, e) == 1)
			break;
	}
	
	int d = 0;
	for (d = e + 1; d <= 100; d++) {
		if ( ((d * e) % prod) == 1)
			break;
	}
	printf("Enter plaintext: ");
	scanf("%d", &data);

    printf("E = %d\nD = %d\n", e, d);
    
	cipher = rsa(data, e, n);
	printf("The cipher text is: %d\n", cipher);

	decrypt = rsa(cipher, d, n);
	printf("The decrypted text is: %d\n", decrypt);
	return 0;
}

