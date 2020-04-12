#include "SortTestHelper.h"

void sort1(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sort2(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool is_order = true;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                is_order = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (is_order) {
            break;
        }
    }
}

void sort3(int arr[], int n) {
    int sort_end = n - 1;
    int last_exchange = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool is_order = true;
        for (int j = 0; j < sort_end; ++j) {
            if (arr[j] > arr[j + 1]) {
                is_order = false;
                last_exchange = j;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (is_order) {
            break;
        }
        sort_end = last_exchange;
    }
}

int main() {
    int n = 10 * 1000;
    // int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr1 = SortTestHelper::generateNearlyOrderedArray(n, 1);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("冒泡排序", sort1, arr1, n);
    SortTestHelper::testSort("冒泡排序优化1", sort2, arr2, n);
    SortTestHelper::testSort("冒泡排序优化2", sort3, arr3, n);

    return 0;
}
