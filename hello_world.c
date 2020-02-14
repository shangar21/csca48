/*

Hello World!
Welcome to programming in C :)

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{

	 for(int i=1; i<=sqrt(100); i++)
	 {
	 	if(i*i <= 100)
	 	{
	 		printf("%d = %d * %d \n", i*i,i,i );
	 	}
	 }

	return 0;

}

