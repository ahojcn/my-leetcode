#include "../SortTestHelper.h"

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

using namespace SortTestHelper;

int main(int argc, char const *argv[])
{
	int n = 100 * 1000;
	int* arr1 = generateRandomArray(n, 0, n);
	testSort("选择排序", selectSort, arr1, n);

	delete[] arr1;
	
	return 0;
}