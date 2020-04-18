#include "../SortTestHelper.h"

using namespace SortTestHelper;

template <typename T>
void __merge(T arr[], int l, int mid, int r) {
	T aux[r - l + 1];
	for (int i = l; i <= r; ++i) {
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (aux[i - l] < aux[j - l]) {
			arr[k++] = aux[i - l];
			i++;
		} else {
			arr[k++] = aux[j - l];
			j++;
		}
	}
	while (i <= mid) {
		arr[k++] = aux[i - l];
		i++;
	}
	while (j <= r) {
		arr[k++] = aux[j - l];
		j++;
	}
}

template <typename T>
void __mergeSort(T arr[], int l, int r) {
	if (l >= r) return;

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	// __merge(arr, l, mid, r);
	if (arr[mid] > arr[mid + 1]) {
		__merge(arr, l, mid, r);
	}
}

template <typename T>
void mergeSort(T arr[], int n) {
	__mergeSort(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
	int n = 100 * 1000;
	int* arr1 = generateRandomArray(n, 0, n);
	testSort("归并排序", mergeSort, arr1, n);
	
	return 0;
}