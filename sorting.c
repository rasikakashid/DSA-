#include <stdio.h>
int main() 
{
    int arr[10] = {11, 14, 16, 70, 26, 67, 32, 78, 79, 34};
    int i, j, min, temp, num, choose;
    printf("Enter how many elements (max 10): ");
    scanf("%d", &num);
    if (num <= 0 || num > 10) 
    {
        printf("Invalid number of elements.\n");
        return 1;
    }
    printf("\nSorting techniques:");
    printf("\n1. Bubble Sort");
    printf("\n2. Selection Sort");
    printf("\n3. Insertion Sort");
    printf("\nEnter your choice (1, 2, or 3): ");
    scanf("%d", &choose);
    switch (choose) 
    {
        case 1: 
            for (i = 0; i < num - 1; i++) 
            {
                for (j = 0; j < num - 1 - i; j++) 
                {
                    if (arr[j] > arr[j + 1]) 
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            break;
        case 2: 
            for (i = 0; i < num - 1; i++) {
                min = i;
                for (j = i + 1; j < num; j++) {
                    if (arr[j] < arr[min]) {
                        min = j;
                    }
                }
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
            break;
        case 3: 
            for (i = 1; i < num; i++) 
            {
                temp = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > temp) 
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = temp;
            }
            break;
        default:
            printf("Wrong choice!\n");
            return 1;
    }
    printf("\nSorted elements: ");
    for (i = 0; i < num; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
} 
