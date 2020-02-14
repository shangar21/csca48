#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/* 3 ways to save a space in memory:
	1. declare a variable
	2. function parameters
	3. return value
*/

void swap_values(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

char *mystrcpy(char *dest, char *src)
{
	for(int i = 0; i < strlen(src); i++)
	{
		*(dest + i) = *(src + i);
	}

	*(dest + strlen(dest)) = '\0';
	return dest;

}

void myswap(char s1[1024], char s2[1024])
{
	char swap[1024];
	for(int i = 0; s1[i]; i++)
	{
		swap[i] = s1[i];
	}
	for(int i = 0; s2[i]; i++)
	{
		s1[i] = s2[i];
	}
	for(int i = 0; swap[i]; i++)
	{
		s2[i] = swap[i];
	}

}

int main()
{
	char *src = "hjell";
	for (int i = 0; i < 5; i++)
	{
		printf("%c\n", *(src + i));
	}
}