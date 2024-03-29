#include<stdio.h>
#include<stdlib.h>

#define n = 1024

/*
How good are Linked-Lists (lnln):
	when do we use them?

data added to collection in random order
	queries are also randomly ordered

How quickly can I find a movie?

chance if movie is last on list: 1/10,000,000

on average:
	not too unlucky and not too lucky:
		N/2 (N = number of entries)

Binary search very fast:
	start from middle and move towards the thing you are searching for

Run time:
	machine dependant					X
	also implementation dependent		X

Big O notation complexity:
	Given : 
		a data structure
		a problem
		an algorithm
	Want to be able to know how much work each of the above takes
	Somebody has to tell us what we are counting
	idea of an estimate in terms of N (size of collection)
	
	searching a linked list:
		Sequential, Unsorted:
			Average complexity: O(N/2). Worst case O(N), best case O(1).
		Binary, sorted:
			Worst case O(log_2(N)) 
				because we are going by half each time

Previously on A48
	the truth is revealed



*/


int main()
{

}

/*

O(N^2 + 2N) run time

*/

void multiply_accumulate(float input[n], float output[n])
{
	for(int i = 0; i < n; i++)
	{
		output[i] = 0;
		for(int j = 0; j < n; j++)
		{
			output[i] = output[i] + input[i]*input[j];
		}
	}
}

typedef struct binary_int_tree_struct
{
	int num;
	struct binary_int_tree_struct  *left;
	struct binary_int_tree_struct  *right;

}binary_int;