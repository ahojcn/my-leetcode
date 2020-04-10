#include <vector>
#include <iostream>
using namespace std;

void printArray(const std::vector<int>& v) {
	cout << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << "]" << endl;
}

// 1. 基础的冒泡排序
void sort1(std::vector<int>& v) {
	for (size_t i = 0; i < v.size() - 1; ++i) {
		for (size_t j = 0; j < v.size() - 1 - i; ++j) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

// 2. 优化冒泡排序
// 因为经过某次排序后，可能就已经有序了，所以如果已经有序(本次没有元素交换)就退出
void sort2(vector<int>& v) {
	for (size_t i = 0; i < v.size() - 1; ++i) {
		bool is_sort = true;
		for (size_t j = 0; j < v.size() - 1 - i; ++j) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
				is_sort = false;
			}
		}
		if (is_sort) {
			break;
		}
	}
}

// 3. 优化冒泡排序
// 对于排序区间的确定，对于以上两种方式，排序的区间都是 [0, size-i-1]
// 如果 3210789，3和0交换后最终的排序区间就应该是3的下标
// 记录每一轮最后一次交换的下标
void sort3(vector<int>& v) {
	size_t sz = v.size();
	size_t sort_end = sz - 1;
	size_t last_change = 0;
	for (size_t i = 0; i < sz - 1; ++i) {
		bool is_sort = true;
		for (size_t j = 0; j < sort_end; ++j) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;

				is_sort = false;
				last_change = j; // 更新为最后一次交换的位置
			}
		}
		sort_end = last_change;
		if (is_sort) {
			break;
		}
	}
}


int main(int argc, char const *argv[])
{
	std::vector<int> v{3,2,1,9,7,4,5,6,8,0};  // c++11
	printArray(v);
	// sort1(v);
	// sort2(v);
	sort3(v);
	printArray(v);

	return 0;
}