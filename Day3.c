#include <stdio.h>

int main() {
    int n, k, comparisons = 0;

    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    int found = 0;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    printf("Number of comparisons: %d", comparisons);

    return 0;
}
