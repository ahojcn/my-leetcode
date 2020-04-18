#pragma once

// 双路快排
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