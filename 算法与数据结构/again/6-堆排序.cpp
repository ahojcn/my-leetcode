// 堆排序

#include "Heap.hpp"

#include "../SortTestHelper.h"
#include "../MergeSort.hpp"
#include "../QuickSort.hpp"

using namespace SortTestHelper;

void heapSort1(int arr[], int n) {
	MaxHeap mh(n);
	for (int i = 0; i < n; ++i) {
		mh.insert(arr[i]);
	}

	for (int i = n - 1; i >= 0; --i) {
		arr[i] = mh.pop();
	}
}

void heapSort2(int arr[], int n) {
	MaxHeap mh(arr, n);
	for (int i = n - 1; i >= 0; --i) {
		arr[i] = mh.pop();
	}
}

void __shiftDown(int arr[], int n, int k) {
	while (k * 2 + 1 < n) {
		int j = k * 2 + 1;
		// 左孩子 < 右孩子
		if (j + 1 < n && arr[j] < arr[j + 1]) {
			++j;
		}
		// parent > max(left, right)
		if (arr[k] > arr[j]) break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

void heapSort3(int arr[], int n) {
	// heapify
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		__shiftDown(arr, n, i);
	}

	// sort
	for (int i = n - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

int main()
{
	int n = 1000 * 1000;
	cout << "1000k 随机数, [0, 1000k]:" << endl;
	int* arr1 = generateRandomArray(n, 0, n);
	int* arr2 = copyIntArray(arr1, n);
	int* arr3 = copyIntArray(arr1, n);
	int* arr4 = copyIntArray(arr1, n);
	int* arr5 = copyIntArray(arr1, n);
	testSort("归并排序", mergeSort, arr2, n);
	testSort("3路快排", quickSort3Ways, arr3, n);
	testSort("堆排1", heapSort1, arr1, n);
	testSort("堆排2", heapSort2, arr4, n);
	testSort("堆排3", heapSort3, arr5, n);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	cout << "1000k 近乎有序, [0, 1000k]:" << endl;
	arr1 = generateNearlyOrderedArray(n, 100);
	arr2 = copyIntArray(arr1, n);
	arr3 = copyIntArray(arr1, n);
	arr4 = copyIntArray(arr1, n);
	arr5 = copyIntArray(arr1, n);
	testSort("归并排序", mergeSort, arr2, n);
	testSort("3路快排", quickSort3Ways, arr3, n);
	testSort("堆排1", heapSort1, arr1, n);
	testSort("堆排2", heapSort2, arr4, n);
	testSort("堆排3", heapSort3, arr5, n);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	cout << "1000k 范围小, [0, 100]:" << endl;
	arr1 = generateRandomArray(n, 0, 100);
	arr2 = copyIntArray(arr1, n);
	arr3 = copyIntArray(arr1, n);
	arr4 = copyIntArray(arr1, n);
	arr5 = copyIntArray(arr1, n);
	testSort("归并排序", mergeSort, arr2, n);
	testSort("3路快排", quickSort3Ways, arr3, n);
	testSort("堆排1", heapSort1, arr1, n);
	testSort("堆排2", heapSort2, arr4, n);
	testSort("堆排3", heapSort3, arr5, n);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;

	return 0;
}