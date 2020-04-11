#include <vector>
#include <iostream>
#include "common.hpp"
using namespace std;

// 鸡尾酒排序
void sort(vector<int>& v) {
	for (size_t i = 0; i < v.size() / 2; ++i) {
		bool is_sotred = true;
		// 奇数轮，从左向右比较交换
		for (size_t j = i; j < v.size() - 1 - i; ++j) {
			if (v[j] > v[j + 1]) {
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
				is_sotred = false;
			}
		}
		if (is_sotred) {
			break;
		}

		// 偶数轮，从右向左比较交换
		is_sotred = true;
		for (size_t j = v.size() - i - 1; j > i; --j) {
			if (v[j] < v[j - 1]) {
				int tmp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = tmp;
				is_sotred = false;
			}
		}
		if (is_sotred) {
			break;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v{2,3,4,5,6,7,1,8,9,0};
	printArray(v);
	sort(v);
	printArray(v);
	
	return 0;
}