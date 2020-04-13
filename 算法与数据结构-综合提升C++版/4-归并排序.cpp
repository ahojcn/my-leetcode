#include "SortTestHelper.h"

// 将 arr[l, mid] 和 arr[mid+1, r] 两部分进行合并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j-l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i-l];
            i++;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
}

// 优化2 辅助插入排序
template<typename T>
void __insertSort(T arr[], int l, int r) {
    for (int i = l+1; i <= r; i++) {
        T e = arr[i];
        int j = i;
        for (; j > l && arr[j - 1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
    return;
}

// 递归使用归并排序，对 arr[l, r] 的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) return;
    // 优化2
    // if (r-l <= 15) {
    //     __insertSort(arr, l, r);
    //     return;
    // }

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    if (arr[mid] > arr[mid+1])  // 优化1
        __merge(arr, l, mid, r);
}

// 自顶向下进行归并过程
template<typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n-1);
}

// 自底向上归并过程
// 因为没有使用 arr[] 取数组元素，可以在 nlogn 进行归并排序
template<typename T>
void mergeSortBU(T arr[], int n) {
    for ( int sz = 1; sz <= n; sz+=sz ) {
        for ( int i = 0; i + sz < n; i+=sz+sz ) {
            // 对 arr[i, i+sz-1] 和 arr[i+sz, i+2*sz-1] 进行归并
            __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}

template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

int main() {
    int n = 100 * 1000;
    // int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr1 = SortTestHelper::generateNearlyOrderedArray(n, 0);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    // int* arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("归并排序", mergeSort, arr1, n);
    SortTestHelper::testSort("插入排序", insertSort, arr2, n);
    // SortTestHelper::testSort("归并排序BU", mergeSortBU, arr3, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}