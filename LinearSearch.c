#include<stdio.h>
int main()
{
    int a[10], i, item;
    printf("\nEnter 5 elements of an array:\n");
    for (i=0; i<=4; i++)
        scanf("%d", &a[i]);
    printf("\nEnter item to search: ");
    scanf("%d", &item);
    for (i=0; i<=5; i++)
        if (item == a[i])
        {
            printf("\nItem found at location %d\t", i+1);
            break;
        }
    if (i > 5)
        printf("\nItem does not exist.");
    return 0;
}