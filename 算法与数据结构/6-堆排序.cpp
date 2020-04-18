#include "Heap.hpp"
#include "QuickSort.hpp"
#include "MergeSort.hpp"
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

template <typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap(n);
    for (int i = 0; i < n; ++i) {
        maxheap.insert(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxheap.extractMax();
    }
}

template <typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxheap.extractMax();
    }
}

template <typename T>
void __shiftDown(T arr, int n, int k) {
    while (2*k+1 < n) {
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j]) {
            j = j + 1;
        }
        if (arr[k] >= arr[j]) {
            break;
        }

        swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void heapSort(T arr[], int n) {
    // heapify
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
        __shiftDown(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

int main() {
    int n = 1000 * 1000;
    cout << "1000k, [0,1000k], 随机数" << endl;
    int* arr1 = generateRandomArray(n, 0, n);
    int* arr2 = copyIntArray(arr1, n);
    int* arr3 = copyIntArray(arr1, n);
    int* arr4 = copyIntArray(arr1, n);
    int* arr5 = copyIntArray(arr1, n);
    int* arr6 = copyIntArray(arr1, n);

    testSort("归并排序", mergeSort, arr1, n);
    testSort("双路快排", quickSort, arr2, n);
    testSort("三路快排", quickSort3Ways, arr3, n);
    testSort("堆排序1", heapSort1, arr4, n);
    testSort("堆排序2", heapSort2, arr5, n);
    testSort("堆排序3", heapSort, arr6, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout << "1000k, [0, 1000k], 接近有序" << endl;
    arr1 = generateNearlyOrderedArray(n, 100);
    arr2 = copyIntArray(arr1, n);
    arr3 = copyIntArray(arr1, n);
    arr4 = copyIntArray(arr1, n);
    arr5 = copyIntArray(arr1, n);
    arr6 = copyIntArray(arr1, n);
    testSort("归并排序", mergeSort, arr1, n);
    testSort("双路快排", quickSort, arr2, n);
    testSort("三路快排", quickSort3Ways, arr3, n);
    testSort("堆排序1", heapSort1, arr4, n);
    testSort("堆排序2", heapSort2, arr5, n);
    testSort("堆排序3", heapSort, arr6, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    cout << "1000k, [0, 10], 大量相同元素" << endl;
    arr1 = generateRandomArray(n, 0, 10);
    arr2 = copyIntArray(arr1, n);
    arr3 = copyIntArray(arr1, n);
    arr4 = copyIntArray(arr1, n);
    arr5 = copyIntArray(arr1, n);
    arr6 = copyIntArray(arr1, n);
    testSort("归并排序", mergeSort, arr1, n);
    testSort("双路快排", quickSort, arr2, n);
    testSort("三路快排", quickSort3Ways, arr3, n);
    testSort("堆排序1", heapSort1, arr4, n);
    testSort("堆排序2", heapSort2, arr5, n);
    testSort("堆排序3", heapSort, arr6, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    return 0;
}