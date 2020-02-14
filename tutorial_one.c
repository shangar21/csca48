#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// takes in 2 integers x and y and return a double

double div_x_y (int x, int y)
{
	return (double)x / (double)y;
}

//write a program that prints out the graph of sin(x) from  0 to 2pi



int main()
{
	int spaces = 52;

	for(double i = 0; i < 2*M_PI; i+= 0.25)
	{
		double y = sin(i);
		//spaces = spaces + y;
		printf();;
		for(int j = 0; j < spaces + y*10; j++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
}