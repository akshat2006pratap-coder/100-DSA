#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];
    printf("enter the size of the array: ");
   scanf("%d", &n);
printf("enter the elemnents in the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
printf("enter the index where you want to insert: ");
    scanf("%d", &pos);
    printf("Enter the element you wantt to insert: ");
    scanf("%d", &x);

    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = x;
    n++;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
