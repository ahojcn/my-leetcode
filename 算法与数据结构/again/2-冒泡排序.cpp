#include "../SortTestHelper.h"

using namespace SortTestHelper;

template <typename T>
void bubbleSort1(T arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <typename T>
void bubbleSort2(T arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		bool is_ordered = true;
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				is_ordered = false;
			}
		}
		if (is_ordered) {
			break;
		}
	}
}

template <typename T>
void bubbleSort3(T arr[], int n) {
	int end_index = n - 1;
	int last_exchange = 0;

	for (int i = 0; i < n - 1; ++i) {
		bool is_ordered = true;
		for (int j = 0; j < end_index; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				is_ordered = false;
				last_exchange = j;
			}
		}
		if (is_ordered) {
			break;
		}
		end_index = last_exchange;
	}

}

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

int main() {
	int n = 10 * 1000;
	cout << "random array, [0, 10k]:" << endl;
	int* arr1 = generateRandomArray(n, 0, n);
	int* arr2 = copyIntArray(arr1, n);
	int* arr3 = copyIntArray(arr1, n);
	int* arr4 = copyIntArray(arr1, n);
	testSort("选择排序", selectSort, arr1, n);
	testSort("冒泡排序1", bubbleSort1, arr2, n);
	testSort("冒泡排序2", bubbleSort2, arr3, n);
	testSort("冒泡排序3", bubbleSort3, arr4, n);

	cout << "nearly ordered array, [0, 10k]:" << endl;
	int* arr5 = generateNearlyOrderedArray(n, 1);
	int* arr6 = copyIntArray(arr5, n);
	int* arr7 = copyIntArray(arr5, n);
	int* arr8 = copyIntArray(arr5, n);
	testSort("选择排序", selectSort, arr5, n);
	testSort("冒泡排序1", bubbleSort1, arr6, n);
	testSort("冒泡排序2", bubbleSort2, arr7, n);
	testSort("冒泡排序3", bubbleSort3, arr8, n);

    cout << "random array, [0, 10]:" << endl;
	int* arr9 = generateRandomArray(n, 0, 10);
	int* arr10 = copyIntArray(arr9, n);
	int* arr11 = copyIntArray(arr9, n);
	int* arr12 = copyIntArray(arr9, n);
	testSort("选择排序", selectSort, arr9, n);
	testSort("冒泡排序1", bubbleSort1, arr10, n);
	testSort("冒泡排序2", bubbleSort2, arr11, n);
	testSort("冒泡排序3", bubbleSort3, arr12, n);


	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;
	delete[] arr11;
	delete[] arr12;

	return 0;
}