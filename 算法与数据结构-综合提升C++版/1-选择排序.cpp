// O(n^2)

#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
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
void sort1(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 10 * 1000;
    // int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr1 = SortTestHelper::generateNearlyOrderedArray(n, 1);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("选择排序", selectSort, arr1, n);
    // SortTestHelper::testSort("冒泡排序", sort1, arr, n);
    SortTestHelper::testSort("冒泡排序优化版", sort3, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}