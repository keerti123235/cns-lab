#include<stdio.h>
#include<string.h>
 
int main(){
    char msg[15], key[10];
    
    printf("Enter Original Message: ");
    scanf("%s",msg);
    printf("Enter Key: ");
    scanf("%s",key);

    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
    for(i = 0; i < msgLen; i++){
        if(msg[i]>=97 && msg[i]<=122)
            msg[i] = msg[i] - 'a' + 'A';
    }

    for(i = 0; i < keyLen; i++){
        if(key[i]>=97 && key[i]<=122)
            key[i] = key[i] - 'a' + 'A';
    }

    for(i = 0, j = 0; i < msgLen; i++, j++){
        if(j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    for(i = 0; i < msgLen; i++)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    encryptedMsg[i] = '\0';
 
    for(i = 0; i < msgLen; i++)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    decryptedMsg[i] = '\0';
 
    printf("Original Message: %s\n", msg);
    printf("Key: %s\n", key);
    printf("New Generated Key: %s\n", newKey);
    printf("Encrypted Message: %s\n", encryptedMsg);
    printf("Decrypted Message: %s", decryptedMsg);
 
	return 0;
} 