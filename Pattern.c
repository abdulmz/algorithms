#include <stdio.h>
#include <string.h>
#define d 256

void NaiveStringMatch(char* pat, char* txt, int M, int N)
{
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M) 
            printf("Pattern found at index %d \n", i);
    }
}

void RabinKarp(char pat[], char txt[], int M, int N)
{
    int i, j;
    int p=0, t=0, h=1, q=101;
 
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;

    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
 
    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            if (t < 0)
            t = (t + q);
        }
    }
}

void KMPAlgorithm(const char* X, const char* Y, int m, int n)
{
    if (*Y == '\0' || n == 0) {
        printf("The pattern occurs with shift 0");
    }
    if (*X == '\0' || n > m) {
        printf("Pattern not found");
    }
    int next[n + 1];
 
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
 
        while (j > 0 && Y[j] != Y[i]) {
            j = next[j];
        }
 
        if (j > 0 || Y[j] == Y[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++)
    {
        if (*(X + i) == *(Y + j))
        {
            if (++j == n) {
                printf("The pattern occurs with shift %d\n", i - j + 1);
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;   
        }
    }
}
int main()
{
    int choice;
    char pattern[30], text[30], buff[100];
	printf("Enter the text: ");
    gets(buff);
    sscanf(buff, "%s", text);
    printf("\nEnter the pattern: ");
	gets(buff);
    sscanf(buff, "%s", pattern);
	
    int patlength = strlen(pattern);
    int textlength = strlen(text);

    printf("\nChoose the Algorithm to use: ");
    printf("1. NAIVE STRING MATCH\n2. RABIN-KARP ALGORITHM\n3. KMP ALGORITHM\n");  
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: NaiveStringMatch(pattern, text, patlength, textlength);
                break;
        case 2: RabinKarp(pattern, text, patlength, textlength);
                break;
        case 3: KMPAlgorithm(text, pattern, textlength, patlength);
                break;
        default : break;
    }
}


    
