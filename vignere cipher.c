#include<stdio.h>
#include<string.h>
 
int main(){
    char msg[20];
    char key[20];
    printf("Enter the Message");
    scanf("%s",msg);
    printf("Enter the key");
    scanf("%s",key);
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    for(i=0,j=0;i<strlen(msg);i++) //convets msg to upper case
    {
      if(msg[i]!=' ')
     {
        msg[j]=toupper(msg[i]);   
       j++;
     }
 }
 msg[j]='\0';
 printf("Entered message is : %s \n",msg); 

    for(i=0,j=0;i<strlen(key);i++) // convets key to upper case   
    {
     if(key[i]!=' ')
     {
      key[j]=toupper(key[i]);   
      j++;
     }
  }
 key[j]='\0';

  printf("Entered key is : %s \n",key); 

 
    for(i = 0, j = 0; i < msgLen; ++i, ++j){  //msg equals the key length
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    char table[26][26];
    for(int i = 0; i < 26; i++){                        //creation of table
        for(int j = 0; j < 26; j++){
            table[i][j] = ('A' + ((i + j) % 26));
        }
    }

    printf("The table is ")
    for(int i = 0; i < 26; i++){                        //creation of table
        for(int j = 0; j < 26; j++){
            printf("%s",table[i][j]);
        }
    }
 
 
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
 
    encryptedMsg[i] = '\0';
 
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i] = '\0';
 
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
	return 0;
}