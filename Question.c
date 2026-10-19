#include <stdio.h>
int main()
{
    int a[100], n, key;
    int low, high, mid;
    int comparisons = 0;
    int position = -1;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);

    printf("Enter employee IDs in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        comparisons++;

        if (a[mid] == key)
        {
            position = mid + 1;
            break;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (position != -1)
    {
        printf("Employee ID found at position %d\n", position);
    }
    else
    {
        printf("Employee ID not found\n");
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
