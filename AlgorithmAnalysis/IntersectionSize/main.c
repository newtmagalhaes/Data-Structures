#include <stdio.h>

int IntersectionSize(int *array1, int array1Size, int *array2, int array2Size)
{
    int intersection = 0, j = 0;
    for (int i = 0; i < array1Size; i++)
    {
        j = 0;
        while (j < i && array1[i] != array1[j])
        {
            j++;
        }
        if (j >= i)
        {
            j = 1;
            while (j < array2Size && array2[j] != array1[i])
            {
                j++;
            }
            if (j < array2Size)
            {
                intersection++;
            }
        }
    }
    printf("The size of intersection is %d.\n", intersection);
    return intersection;
}

int main()
{
    int arr1[4] = {2, 3, 5, 7},
        arr2[4] = {1, 4, 5, 7};

    IntersectionSize(arr1, 4, arr2, 4);

    return 0;
}
