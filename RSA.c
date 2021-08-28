#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long

int getGCD(int number1, int number2)
{
    int result;
    for (int i=1; i<=number1 && i<=number2; i++)
    {
        if (number1%i==0 && number2%i==0)
            result = i;
    }
    return result;
}

int isPrime(int number)
{
    for (int i=2; i<= number/2; i++)
    {
        if (number%i == 0)
            return 0;
    }
    return 1;
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

int gete(int prod)
{
    int result;
	for (int i = 5; i <= 100; i++) 
    {
		if (getGCD(prod, i) == 1)
        {
            result = i;
            break;
        }
	}
    return result;
}

int getd(int prod, int e)
{
    int result;
	for (int i = e+1; i <= 100; i++) 
    {
		if ( ((i*e) % prod) == 1)
        {
            result = i;
            break;
        }
	}
    return result;
}

int main(int argc, char* argv[])
{
    int prime1;
    int prime2;
    while(true)
    {
        printf("Enter the two prime numbers:");
        scanf("%d",&prime1);
        scanf("%d",&prime2);

        if ((isPrime(prime1) && isPrime(prime2))
            break;
        else
            printf("Please Enter Prime Numbers!\n");
    }

    int prod = prime1*prime2;
    int constant = (prime1-1)*(prime2-1);

    int e = gete(prod);
    int d = getd(prod, e);

    int input;
    printf("Enter the number to be decrypted: ");
    scanf("%d",input);

    int ciphertext = rsa(input, e, prod);
    int decypertext = rsa(ciphertext, d, prod);

    printf("\nE= %d, D=%d\n",e,d);
    printf("Ciphered text= %d, Decyphered text= %d",ciphertext, decypertext);
    return 0;
}
