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


void codon_cpy(Codon source, Codon dest)
{
    for(int i = 0; i < 3; i++)
    {
        dest[i] = source[i];
    }
}



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

        codon_cpy(codons[i], temp_codons[--count[codons[i][index]]]);
    }

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            codons[i][j] = temp_codons[i][j];
        }       
    }


}

/**
 * Sort the codons array in place, in ascending order.
 *
 * EX: sort_codons({{A, A, C}, {A, A, A}}, 2) => {{A, A, A}, {A, A, C}}
 *
 * NOTE: The codons should be sorted based on their own value,
 *          NOT the value of their associated amino acids.
 *
 * REQ:
 *  - The "codons" array points to an array of codons with exactly num_codons in it
 *  - Each codon contains exactly 3 Nucleotides
 *  - Each nucleotide can only take on a value in the set {A, C, G, T}
 *
 * INPUT:
 *  - codons: An array of codons, likely unsorted
 *  - num_codons: The number of codons that are in the array
 *
 * OUTPUT:
 *  - codons: The same array of codons, now sorted
 */
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


    for(int i = num_codons - 1; i >= 0; i--)
    {
        count_sort(codons, i, num_codons);
    }

}

/**
 * Prints the amino acid coded for by each codon. This just makes them more readable.
 *
 * EX: printCodon({A, T, G}) => Methionine
 *
 * INPUT:
 *  - codons: A codon whose associated amino acid is to be printed
 *
 * OUTPUT:
 *  - To the terminal: The amino acid associated with the given codon
 */
void printCodon(Codon codon)
{  // Ignore this whole implementation if you like.
    switch (codon[0])
    {
    case A:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tLysine");
                break;
            case C:
                printf("\tAsparganine");
                break;
            case G:
                printf("\tLysine");
                break;
            case T:
                printf("\tAsparganine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tThreonine");
            break;
        case G:
            switch (codon[2])
            {
            case A:
                printf("\tArginine");
                break;
            case C:
                printf("\tSerine");
                break;
            case G:
                printf("\tArginine");
                break;
            case T:
                printf("\tSerine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case T:
            switch (codon[2])
            {
            case A:
                printf("\tIsoleucine");
                break;
            case C:
                printf("\tIsoleucine");
                break;
            case G:
                printf("\tMethionine");
                break;
            case T:
                printf("\tIsoleucine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    case C:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tGlutamine");
                break;
            case C:
                printf("\tHistidine");
                break;
            case G:
                printf("\tGlutamine");
                break;
            case T:
                printf("\tHistidine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tProline");
            break;
        case G:
            printf("\tArginine");
            break;
        case T:
            printf("\tLeucine");
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    case G:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tGlutamic Acid");
                break;
            case C:
                printf("\tAspartic Acid");
                break;
            case G:
                printf("\tGlutamic Acid");
                break;
            case T:
                printf("\tAspartic Acid");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tAlanine");
            break;
        case G:
            printf("\tGlycine");
            break;
        case T:
            printf("\tValine");
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    case T:
        switch (codon[1])
        {
        case A:
            switch (codon[2])
            {
            case A:
                printf("\tSTOP");
                break;
            case C:
                printf("\tTyrosine");
                break;
            case G:
                printf("\tSTOP");
                break;
            case T:
                printf("\tTyrosine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case C:
            printf("\tSerine");
            break;
        case G:
            switch (codon[2])
            {
            case A:
                printf("\tSTOP");
                break;
            case C:
                printf("\tCysteine");
                break;
            case G:
                printf("\tTryptophan");
                break;
            case T:
                printf("\tCysteine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        case T:
            switch (codon[2])
            {
            case A:
                printf("\tLeucine");
                break;
            case C:
                printf("\tPhenylalanine");
                break;
            case G:
                printf("\tLeucine");
                break;
            case T:
                printf("\tPhenylalanine");
                break;
            default:
                printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
                exit(1);
            }
            break;
        default:
            printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
            exit(1);
        }
        break;
    default:
        printf("\nERROR:\nInvalid nucleotide in codon: %d\n", codon[1]);
        exit(1);
    }
}

/**
 * Prints the amino acids associated with each codon in the given array.
 *
 * REQ:
 *  - The "codons" array points to an array of codons with exactly num_codons in it
 *  - Each codon contains exactly 3 Nucleotides
 *  - Each nucleotide can only take on a value in the set {A, C, G, T}
 *
 * INPUT:
 *  - codons: An array of codons
 *  - num_codons: The number of codons that are in the array
 *
 * OUTPUT:
 *  - To the terminal: The amino acids associated with each codon in the list, in order.
 */
void printCodons(Codon codons[], int num_codons)
{
    for (int index = 0; index < num_codons; index++) printCodon(codons[index]);
    printf("\n");
}

// We NEED this compiler directive to test your code with our own main(). Don't break it.
#ifndef __TESTING  // this compiler directive
int main()
{
    Codon test_codons[3] = {
        {A, T, G},
        {A, A, C},
        {T, A, A},
    };

    printf("Before sorting:\n");
    printCodons(test_codons, 3);

    sortCodons(test_codons, 3);  // calls your sorting code


    printf("After sorting:\n");
    // Now should print:
    //     Asparganine    Glutamic Acid    STOP
    printCodons(test_codons, 3);
}
#endif  // and this compiler directive