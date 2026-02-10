#include <stdio.h>
#include <stdlib.h>

int comp = 0, swap = 0;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            comp++;
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                swap++;
            }
        }
}

int main() {
    int n, ch;
    printf("Enter N: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 1;

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\nChoose sorting (1-Bubble): ");
    scanf("%d", &ch);

    bubbleSort(a, n);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\nComparisons: %d\nSwaps: %d\n", comp, swap);
    return 0;
}
