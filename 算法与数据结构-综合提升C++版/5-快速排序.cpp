#include "SortTestHelper.h"
using namespace SortTestHelper;

template<typename T>
int __partition2(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l + 1 && arr[j] > v) j--;
        if (i > j) break;
        swap(arr[i++], arr[j--]);
    }

    swap(arr[l], arr[j]);
    return j;
}

// 返回 p, arr[l, p - 1] < arr[p]; arr[p + 1, r] > arr[p];
template<typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];

    // arr[l + 1, j] < v; arr[j + 1, i] > v;
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < v) {
            swap(arr[++j], arr[i]);
        }
    }

    swap(arr[l], arr[j]);
    return j;
}

// arr[l, r]
template<typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) return;
    srand(time(NULL));

    // T p = __partition(arr, l, r);
    T p = __partition2(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    __quickSort(arr, 0, n - 1);
}

template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {
    if (l >= r) return ;

    srand(time(NULL));
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    // partition
    int i = l + 1;
    int lt = l;
    int gt = r + 1;
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[++lt], arr[i++]);
        } else if (arr[i] > v) {
            swap(arr[i], arr[--gt]);
        } else {
            ++i;
        }
    }
    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n) {
    __quickSort3Ways(arr, 0, n - 1);
}

// 将 arr[l, mid] 和 arr[mid+1, r] 两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j-l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i-l];
            i++;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
}

// 递归使用归并排序，对 arr[l, r] 的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    if (arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

// 自顶向下进行归并过程
template<typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n-1);
}

int main() {
    int n = 100 * 1000;
    int* arr1 = generateRandomArray(n, 0, n);
    // int* arr1 = generateRandomArray(n, 0, 10);
    // int* arr1 = generateNearlyOrderedArray(n, 10);
    int* arr2 = copyIntArray(arr1, n);
    int* arr3 = copyIntArray(arr1, n);

    testSort("归并排序", mergeSort, arr1, n);
    testSort("快速排序", quickSort, arr2, n);
    testSort("3路快速排序", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}