#include <stdio.h>
#include<math.h>

int main()

{

  char str_message[500], ch;

  int i, key,num,num1,e;

  printf("Enter a message :"); 

  scanf("%s",str_message);

  printf("Enter the key: ");

  scanf("%d", &key);

  for(i = 0; str_message[i] != '\0'; i++){

    ch = str_message[i];

    if(ch >= 'a' && ch <= 'z'){

      ch = ch + key;

      if(ch > 'z'){

        ch = ch - 'z' + 'a' - 1;

      }

      str_message[i] = ch;

    }

    else if(ch >= 'A' && ch <= 'Z'){

      ch = ch + key;

      if(ch > 'Z'){

        ch = ch - 'Z' + 'A' - 1;

      }
      
      if(num >= 0 && num <=9){
      
      for(i=3;i>=0;i--)

        {

            num1=(num)/(pow(10,i));

            num1=(num1+7)%10;

            e=(10*e)+num1;
            

        }
      }
      str_message[i] = ch;

    }
    

  }

 printf("Encrypted message: %s%d\n", str_message,e);
 
 for(i = 0; str_message[i] != '\0'; i++){

    ch = str_message[i];

    if(ch >= 'a' && ch <= 'z'){

      ch = ch - key;

      if(ch < 'a'){

        ch = ch + 'z' - 'a' + 1;

      }

      str_message[i] = ch;

    }
else if(ch >= 'A' && ch <= 'Z'){

      ch = ch - key;

      if(ch < 'A'){

        ch = ch + 'Z' - 'A' + 1;

      }

      str_message[i] = ch;

    }

  }

  printf("Decrypted message: %s\n", str_message);


}
