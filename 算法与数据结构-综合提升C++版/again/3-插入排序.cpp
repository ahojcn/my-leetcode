#include "../SortTestHelper.h"

using namespace SortTestHelper;

template <typename T>
void insertSort1(T arr[], int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

template <typename T>
void insertSort2(T arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int j;
		T e = arr[i];
		for (j = i; j > 0; --j) {
			if (arr[j - 1] > e) {
				arr[j] = arr[j - 1];
			} else {
				break;
			}
		}
		arr[j] = e;
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

int main(int argc, char const *argv[])
{
	int n = 10 * 1000;
    int* arr1 = generateRandomArray(n, 0, n);
    // int* arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int* arr2 = copyIntArray(arr1, n);
    int* arr3 = copyIntArray(arr1, n);
    int* arr4 = copyIntArray(arr1, n);

    testSort("插入排序", insertSort1, arr1, n);
    testSort("插入排序优化", insertSort2, arr4, n);
    testSort("选择排序", selectSort, arr2, n);
    testSort("冒泡排序", bubbleSort3, arr3, n);
	
	return 0;
}