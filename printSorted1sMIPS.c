#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef false
#define false 0
#endif // false
#ifndef true
#define true 1
#endif // true

#define n 120   // size of array

//  count number of Ones in a given number
int countOnes (int num) // O(1)
{
    int count = 0;
    while (num != 0) 
    {
        num &= (num - 1);
        count++;
    }
    return count;
}

// sort both arrays using insertion sort
void doubleInsertionSort(int arr1[], int arr2[], int size) // O(n^2) worst case
{
    // insertion sort for sorting the arr2 - higher priority array
    for (int i = 1; i < size; i++) 
    {
        // use 2 keys because we need to sort both arrays simultaneously
        int key1 = arr2[i];
        int key2 = arr1[i];

        int j = i - 1;
        while (j >= 0 && arr2[j] > key1) 
        {
            arr2[j+1] = arr2[j];
            arr1[j+1] = arr1[j];
            j--;
        }
        arr2[j+1] = key1;
        arr1[j+1] = key2;
    }

    // insertion sort for sorting arr1 - lower priority array
    for (int i = 0; i < size; i++) 
    {
        int currentCount = arr2[i];
        int value = arr1[i];

        int j = i - 1;
        while (j >= 0 && value < arr1[j] && arr2[j] == currentCount) 
        {
            arr1[j+1] = arr1[j];
            j--;
        }
        arr1[j+1] = value;
    }
}


int main()
{
    int ints[n];
    int counts[n];

    // Generate the random numbers, place in ints[]
    // store to counts[i] the number of their set bits (synced)
    srand(time(0));
    int i;
    for (i = 0; i < n; i++) {
        ints[i] = rand() * 8652 / 4321 ;
        counts[i] = countOnes(ints[i]);
    }

    doubleInsertionSort(ints, counts, n);

    // print sorted arrays: [number]:[countOfOnes]
    for (i = 0; i < n; i++) {
        printf("%d|%d\n", ints[i], counts[i]);
    }

    return 0;
}
