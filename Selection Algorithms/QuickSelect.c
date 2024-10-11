#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            Swap(&arr[i], &arr[j]);
            i++;
        }
    }
    Swap(&arr[i], &arr[r]);
    return i;
}

int KthLargest(int *arr, int l, int r, int k) {
    if (l <= r) {
        int p = Partition(arr, l, r);
        if (p == k) {
            return arr[k];
        } else if (k<p) {
            return KthLargest(arr, l, p - 1, k);
        } else {
            return KthLargest(arr, p + 1, r, k);
        }
    }
    return -1;
}

int main() {
    int arr[] = {4,1,2,5,7,0,1};
    int k = 3;
    int len = sizeof(arr) / sizeof(arr[0]);
    int kthlar = KthLargest(arr, 0, len - 1, len-k);
    printf("%d\n", kthlar);
    return 0;
}

