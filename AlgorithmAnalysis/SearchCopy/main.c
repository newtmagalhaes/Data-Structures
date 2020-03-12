#include <stdio.h>

int hasCopy(int *array, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[i] == array[j])
            {
                printf("Element %d of position %d at position %d!\n", array[i], i, j);
                return 1;
            }
        }
    }
    printf("All the elements are single!\n");
    return 0;
}

int main()
{
    int arr[5] = {1, 3, 5, 7, 3};

    hasCopy(arr, 5);

    return 0;
}
