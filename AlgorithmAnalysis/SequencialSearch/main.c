#include <stdio.h>

int SequencialSearch(int value, int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (value == array[i])
        {
            printf("Element %d exists in position %d\n", value, i);
            return i;
        }
    }
    printf("Element doesn't exist in array!\n");
    return -1;
}

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};

    // Positive case
    SequencialSearch(5, arr, 5);

    // Negative case
    SequencialSearch(2, arr, 5);

    return 0;
}
