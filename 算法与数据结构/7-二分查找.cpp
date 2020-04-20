#include <iostream>

using namespace std;

// 找到返回对应的 index
// 没找到返回 -1
template <typename T>
int binarySearch(T arr[], int n, T target) {

	// 在 arr[l, r] 中查找 target
	int l = 0, r = n - 1;
	while (l <= r) {
		// mid = (l + r) / 2;
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) return mid;

		if (target < arr[mid]) {
			// 在 arr[l, mid-1] 查找 target
			r = mid - 1;
		} else {
			// 在 arr[mid+1, r] 查找 target
			l = mid + 1;
		}
	}
	return -1;
}

// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){

    if( l > r )
        return -1;

    //int mid = (l+r)/2;
    // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
    int mid = l + (r-l)/2;

    if( arr[mid] == target )
        return mid;
    else if( arr[mid] > target )
        return __binarySearch2(arr, l, mid-1, target);
    else
        return __binarySearch2(arr, mid+1, r, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target){

    return __binarySearch2( arr , 0 , n-1, target);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}