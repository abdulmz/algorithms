#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int number)
{
    for (int i=2; i<= number/2; i++)
    {
        if (number%i == 0)
            return 0;
    }
    return 1;
}

int findGCD(int n1, int n2) {
	int i, gcd;

	for(i = 1; i <= n1 && i <= n2; ++i) {
		if(n1 % i == 0 && n2 % i == 0)
			gcd = i;
	}

	return gcd;
}

int rsa(int input, int e, int prod)
{
    ll a = 1;
    ll temp = input;
    while(e > 0)
    {
        if (e%2 == 1)
        {
            a = (a*temp)%prod;
        }    
        temp = (temp*temp) % prod;
        e = e/2;
    }
    return a % prod;
}

int main(int argc, char* argv[]) {

	int data, cipher, decrypt;
	int prime1;
    int prime2;
    while(1)
    {
        printf("Enter the two prime numbers:");
        scanf("%d",&prime1);
        scanf("%d",&prime2);

        if (isPrime(prime1) && isPrime(prime2))
            break;
        else
            printf("Please Enter Prime Numbers!\n");
    }
	
	int n = prime1*prime2;
	int phi = (prime1-1)*(prime2-1);

	int e = 0;
	for (e = 5; e <= 100; e++) {
		if (findGCD(phi, e) == 1)
			break;
	}
	
	int d = 0;
	for (d = e + 1; d <= 100; d++) {
		if ( ((d * e) % phi) == 1)
			break;
	}

    printf("Enter the number to be decrypted: ");
    scanf("%d",data);

    int ciphertext = rsa(data, e, n);
    int decypertext = rsa(ciphertext, d, n);

    printf("\nE= %d, D=%d\n",e,d);
    printf("Ciphered text= %d, Decyphered text= %d",ciphertext, decypertext);
    return 0;
}
}

