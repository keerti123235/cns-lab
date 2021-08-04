#include<stdio.h> 
#include<math.h> 
  

int power(int a, int b,int p) 
{   
    if (b == 1) 
        return a; 
    else 
        return ((int)(pow(a, b)) % p);
} 

void main() 
{ 
    int p, g, A, a, B, b, ka, kb;  
      
    p = 23; 
    printf("The value of P : %d\n", p);  
  
    g = 9; 
    printf("The value of G : %d\n\n", g);  
  
    a = 4; 
    printf("The private key a for Alice : %d\n", a); 
    A = power(g, a, p); 
      
    b = 3; 
    printf("The private key b for Bob : %d\n\n", b); 
    B = power(g, b, p); 
  
    
    ka = power(B, a, p); 
    kb = power(A, b, p); 
      
    printf("Secret key for the Alice is : %d\n", ka); 
    printf("Secret Key for the Bob is : %d\n", kb); 
     
} 