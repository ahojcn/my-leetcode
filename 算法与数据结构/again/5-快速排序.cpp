#include "../SortTestHelper.h"

using namespace SortTestHelper;

template <typename T>
int __partition1(T arr[], int l, int r) {
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T pivot = arr[l];

	// int i = l + 1, j = l;
	// while (i <= r) {
	// 	if (arr[i] < pivot) {
	// 		swap(arr[++j], arr[i]);
	// 	}
	// 	++i;
	// }

	// 双路快排
	int i = l + 1, j = r;
	while (true) {
		while (i <= r && arr[i] < pivot) i++;
		while (j >= l + 1 && arr[j] > pivot) j--;
		if (i > j) break;
		swap(arr[i++], arr[j--]);
	}

	swap(arr[l], arr[j]);
	return j;
}

template <typename T>
void __quickSort1(T arr[], int l, int r) {
	if (l >= r) return ;
	srand(time(NULL));

	T pivot_index = __partition1(arr, l, r);
	__quickSort1(arr, l, pivot_index - 1);
	__quickSort1(arr, pivot_index + 1, r);
}

template <typename T>
void quickSort1(T arr[], int n) {
	__quickSort1(arr, 0, n - 1);
}

// 三路快排
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {
	if (l >= r) return;
	srand(time(NULL));

	// partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T pivot = arr[l];
	int i = l + 1;
	int lt = l, gt = r + 1;
	while (i < gt) {
		if (arr[i] < pivot) {
			swap(arr[++lt], arr[i++]);
		} else if (arr[i] > pivot) {
			swap(arr[--gt], arr[i]);
		} else {
			++i;
		}
	}
	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {
	__quickSort3Ways(arr, 0, n - 1);
}


int main() {
	int n = 1000 * 1000;
	int* arr1 = generateRandomArray(n, 0, 5);
	// int* arr1 = generateNearlyOrderedArray(n, 1);
	// testSort("快速排序", quickSort1, arr1, n);
	testSort("快速排序", quickSort3Ways, arr1, n);

	return 0;
}