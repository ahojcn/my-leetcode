// O(n^2)

#include "SortTestHelper.h"

template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

// 插入排序优化
template<typename T>
void insertSort2(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

template<typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {

        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int n = 10 * 1000;
    // int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int* arr2 = SortTestHelper::copyIntArray(arr, n);
    int* arr3 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("插入排序", insertSort, arr, n);
    SortTestHelper::testSort("插入排序优化版", insertSort2, arr2, n);
    SortTestHelper::testSort("选择排序", selectSort, arr3, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    return 0;
}
