#include<stdio.h>
#include<string.h>

void railfence(char msg[],int key,int len)
{
	int i,j,k=-1,row = 0,col = 0;
	char railmatrix[key][len],m[key][len];
	
	for(i=0;i<key;i++)
	{
		for(j=0;j<len;j++)
		{
			railmatrix[i][j] = ' ';
		}
	}
	
	for(i=0;i<len;i++)
	{
		railmatrix[row][col++] = msg[i];
		
		if(row == 0 || row == key-1)
		{
			k=k*-1;
		}
		
		row+=k;
	}
	
	printf("\nThe encrypted text is:\n");
	for(i=0;i<key;i++)
	{
		for(j=0;j<len;j++)
		{
			if(railmatrix[i][j] != ' ')
				printf("%c",railmatrix[i][j]);
		}
	}
	
	printf("\nThe decrypted text is:\n");
	row=col=0;
	k=-1;
	
	for(i=0;i<len;i++)
	{
		printf("%c",railmatrix[row][col++]);
		
		if(row == 0|| row == key-1)
			k=k*-1;
		
		row+=k;
	}
}


int main()
{
	char message[100];
	int key,len;
	
	printf("\nEnter the message:");
	gets(message);
	
	printf("\nEnter the key value:");
	scanf("%d",&key);
	
	len = strlen(message);
	
	
	railfence(message,key,len);
	
}