#include <stdlib.h>
#include <stdio.h>

typedef struct dynarray
{
	int *array;
	int size;

}dynarray;

void init_dynarray(dynarray *da, int size)
{
	//get memory for array
	//update the size info
	da -> size = size;
	da -> array = (int *)calloc(size, sizeof(int));

	if(da -> array == NULL)
	{
		printf("Error 404: Memory not found");
		da -> size = 0;
		return;
	}
	else
	{
		printf("Got an array of size: %d, at memory address %p\n", da -> size, da ->array);
	}

}



int main()
{
	//pointer = (pointer type *)calloc(#elements, size);
	// int *new_array;
	//new_array = (int *)calloc(200, sizeof(int)); 
	//use this so that the size can be set by a variable rather than a fixed value
	//scanf("%d", &x);
	//my_array  = (int *)calloc(x, sizeof(int));


	//implement a dynamic array - user sets initial size
	//when I try to add more entries than array holds, double the size of the array

	dynarray my_array;
	init_dynarray(&my_array, 10);

	for(int i = 0; i < my_array.size; i++)
	{
		*(my_array.array + i) = i*i;
		printf("entry %d contains %d\n", i,*(my_array.array + i));
	}

	free(my_array.array);
	return 0;
}