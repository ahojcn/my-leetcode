#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <ctime>
#include <cassert>
#include <iostream>

using namespace std;

namespace SortTestHelper {
	// 生成 n 个元素的随机数组，每个元素的随机范围为 [range_l, range_r]
	int* generateRandomArray(int n, int range_l, int range_r) {
		assert(range_l <= range_r);

		int* arr = new int[n];
		srand(time(NULL));

		for (int i = 0; i < n; ++i) {
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
		}

		return arr;
	}

	// 生成一个近乎有序的数组
	int* generateNearlyOrderedArray(int n, int swap_times) {
		int* arr = new int[n];
		for (int i = 0; i < n; ++i) 
			arr[i] = i;

		srand(time(NULL));
		for (int i = 0; i < swap_times; ++i) {
			int x = rand() % n;
			int y = rand() % n;
			swap(arr[x], arr[y]);
		}
		return arr;
	}

	template <typename T>
	void printArray(T arr[], int n) {
	  cout << "[";
	  for (size_t i = 0; i < n; ++i) {
	    cout << arr[i] << " ";
	  }
	  cout << "]" << endl;
	}

	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) return false;
		}
		return true;
	}

	template<typename T>
	void testSort(string sort_name, void(*sort)(T[], int), T arr[], int n) {
		clock_t start_time = clock();
		sort(arr, n);
		clock_t end_time = clock();

		assert(isSorted(arr, n));
		cout << sort_name << "\t:\t" << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
	}

	int* copyIntArray(int a[], int n) {
		int* arr = new int[n];
		copy(a, a+n, arr);
		return arr;
	}
}

#endif