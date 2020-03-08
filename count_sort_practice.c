#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    A = 0,
    C = 1,
    G = 2,
    T = 3,
} Nucleotide;  // these are just the integers 0, 1, 2, 3 with fancy names!

typedef Nucleotide Codon[3];


void count_sort(Codon codons [], int index, int len)
{

    int count[4] = {0,0,0,0};
    Codon temp_codons[len];

    for(int i = 0; i < len; i++)
    {
        count[codons[i][index]] += 1;
    }


    for(int i = 1; i < 4; i++)
    {
        count[i] += count[i-1];
    }

    
    for(int i = len - 1; i >= 0; i--)
    {
        for(int j = 0; j < 3; j++)
        {
            temp_codons[--count[codons[i][index]]][j] = codons[i][j];
        }
    }


    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            codons[i][j] = temp_codons[i][j];    
        }        
    }


}

void sortCodons(Codon codons[], int num_codons)
{
    /**
     * TODO: Implement this function, with O(num_codons) worst case time complexity.
     *
     * HINTS:
     *  - How many possible codons are there? How many buckets do you need?
     *  - Are any 2 of the same type in the list different in some way? No.
     *      - That is {A, C, G} == {A, C, G}, even if they are not at the same memory location.
     *  - So, copying data is the same as recreating it elsewhere....
     *
     * NOTE: For this exercise, you can assume that:
     *  - there will only ever be 4 nucleotides
     *  - there will always be 3 nucleotides per codon.
     */

    for(int i = num_codons; i >= 0; i--)
    {
        count_sort(codons, i, num_codons);
    }

}


#ifndef __TESTING  // this compiler directive
int main()
{
    Codon test_codons[3] = {
        {A, T, G},
        {A, A, C},
        {T, A, A},
    };

    //printf("%d\n", test_codons[0][2]);

    count_sort(test_codons, 2,3);
    

    //sortCodons(test_codons, 3);  // calls your sorting code
}
#endif  // and this compiler directive