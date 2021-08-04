  #include <stdio.h>
#include<math.h>

int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}
  
int main()
{
    int count=0;
    double p = 3;
    double q = 7;
  
   
    double n = p*q;
  
    double e = 2;
    double phi = (p-1)*(q-1);
    
    while(e<phi){
    count = gcd(e,phi);
    if(count==1)
        break;
    else
        e++;
    }
    
    int k = 2; 
    double d = (1 + (k*phi))/e;
  
    
    double msg = 12;
  
    printf("Message = %lf", msg);
  
    
    double c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted Message = %lf", c);
  
    
    double m = pow(c, d);
    m = fmod(m, n);
    printf("\nOriginal Message  = %lf", m);
  
    return 0;
}