#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i; 
char msg[100]; 
int prime(long int); 
void ce(); 
long int cd(long int); 
void encrypt(); 
void decrypt(); 

int main() 
{
        
    do {
        printf("\nENTER FIRST PRIME NUMBER \n"); 
        scanf("%ld", &p); 
        flag = prime(p); 
        if (flag == 0 || p < 11) 
        { 
            printf("\nWRONG INPUT. Enter a prime number greater than or equal to 11.\n"); 
        }
    } while(flag == 0 || p < 11);

    do {
        printf("\nENTER ANOTHER PRIME NUMBER \n"); 
        scanf("%ld", &q); 
        flag = prime(q); 
        if (flag == 0 || p == q || q < 11) 
        { 
            printf("\nWRONG INPUT. Enter a distinct prime number greater than or equal to 11.\n"); 
        }
    } while(flag == 0 || p == q || q < 11);

    printf("\nENTER MESSAGE (lowercase letters only)\n"); 
    fflush(stdin); 
    scanf("%s", msg); 

    for (i = 0; msg[i] != '\0'; i++) 
        m[i] = msg[i]; 
    n = p * q; 
    t = (p - 1) * (q - 1); 
    ce(); 

    printf("\nPOSSIBLE VALUES OF e AND d ARE\n"); 
    for (i = 0; i < j - 1; i++) 
        printf("\n%ld\t%ld", e[i], d[i]); 

    encrypt(); 
    decrypt(); 

    getch(); 
    return 0; 
}

int prime(long int pr) 
{ 
    int i; 
    j = sqrt(pr); 
    for (i = 2; i <= j; i++) 
    { 
        if (pr % i == 0) 
            return 0; 
    } 
    return 1; 
} 

void ce() 
{ 
    int k; 
    k = 0; 
    for (i = 2; i < t; i++) 
    { 
        if (t % i == 0) 
            continue; 
        flag = prime(i); 
        if (flag == 1 && i != p && i != q) 
        { 
            e[k] = i; 
            flag = cd(e[k]); 
            if (flag > 0) 
            { 
                d[k] = flag; 
                k++; 
            } 
            if (k == 99) 
                break; 
        } 
    } 
} 

long int cd(long int x) 
{ 
    long int k = 1; 
    while (1) 
    { 
        k = k + t; 
        if (k % x == 0) 
            return (k / x); 
    } 
} 

void encrypt() 
{ 
    long int pt, ct, key = e[0], k, len; 
    i = 0; 
    len = strlen(msg); 
    printf("\nTHE ENCRYPTED MESSAGE IS\n"); 
    while (i != len) 
    { 
        pt = m[i]; 
        pt = pt - 96; // Convert 'a' to 'z' into range 1 to 26
        k = 1; 
        for (j = 0; j < key; j++) 
        { 
            k = k * pt; 
            k = k % n; 
        } 
        temp[i] = k; 
        ct = k + 96; 
        en[i] = ct; 
        printf("%c", en[i]); // Output encrypted character
        i++; 
    } 
    en[i] = -1; 
}

void decrypt() 
{ 
    long int pt, ct, key = d[0], k; 
    i = 0; 
    printf("\nTHE DECRYPTED MESSAGE IS\n"); 
    while (en[i] != -1) 
    { 
        ct = temp[i]; 
        k = 1; 
        for (j = 0; j < key; j++) 
        { 
            k = k * ct; 
            k = k % n; 
        } 
        pt = k + 96; // Convert back from range 1-26 to 'a'-'z'
        m[i] = pt; 
        printf("%c", m[i]); // Output decrypted character
        i++; 
    } 
    m[i] = -1; 
}
