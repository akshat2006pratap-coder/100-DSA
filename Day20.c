#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix = 0;
    long long count = 0;

    long long *hash = (long long*)calloc(2 * MAX + 1, sizeof(long long));
    int offset = MAX;

    hash[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(hash[prefix + offset] > 0)
            count += hash[prefix + offset];

        hash[prefix + offset]++;
    }

    printf("%lld", count);

    return 0;
}