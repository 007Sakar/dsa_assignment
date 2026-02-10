#include <stdio.h>

void heapifyMin(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        int t = a[i]; a[i] = a[smallest]; a[smallest] = t;
        heapifyMin(a, n, smallest);
    }
}

void heapifyMax(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        int t = a[i]; a[i] = a[largest]; a[largest] = t;
        heapifyMax(a, n, largest);
    }
}

int main() {
    int a[] = {4, 10, 3, 5, 1};
    int n = 5;

    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(a, n, i);

    printf("Min Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(a, n, i);

    printf("\nMax Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
