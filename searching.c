#include <stdio.h>
int main() 
{
    int arr[10] = {11, 17, 18, 20, 26, 28, 45, 57, 58, 90};
    int mid, lower = 0, upper = 9, num, flag = 1, x;
    int i, n;
    printf("Searching Techniques");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter the choice: ");
    scanf("%d", &x);

    switch (x) 
    {
        case 1: 
            printf("Enter the number to be searched: ");
            scanf("%d", &n);
            flag = 1; // reset flag
            for (i = 0; i < 10; i++) 
            {
                if (arr[i] == n) 
                {
                    printf("The number is at position %d (index %d)\n", i + 1, i);
                    flag = 0;
                    break;
                }
            }
            if (flag)
                printf("The number is not present\n");
            break;

        case 2: 
            printf("Enter the element to be searched: ");
            scanf("%d", &num);
            flag = 1; // reset flag
            while (lower <= upper) 
            {
                mid = (lower + upper) / 2;

                if (arr[mid] == num) 
                {
                    printf("The number is at position %d (index %d)\n", mid + 1, mid);
                    flag = 0;
                    break;
                }
                else if (arr[mid] > num)
                    upper = mid - 1;
                else
                    lower = mid + 1;
            }

            if (flag)
                printf("The number is not present\n");
            break;

        default:
            printf("Wrong choice\n");
    }

    return 0;
}
 
