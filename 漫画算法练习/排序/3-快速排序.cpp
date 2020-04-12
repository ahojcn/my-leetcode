#include "common.hpp"

// 1. 双边循环法
int partition1(vector<int>& v, int start_index, int end_index) {
	// 取第一个位置作为基准元素
	int pivot = v[start_index];
	int left = start_index, right = end_index;

	while (left != right) {
		// 控制 right 指针比较并左移
		while (left < right && v[right] > pivot) {
			right--;
		}
		// 控制 left 指针比较并左移
		while (left < right && v[left] <= pivot) {
			left++;
		}
		// 交换 left 和 right 指向的元素
		if (left < right) {
			int t = v[left];
			v[left] = v[right];
			v[right] = t;
		}
	}

	v[start_index] = v[left];
	v[left] = pivot;
	return left;
}

// 2. 单边循环法
int partition2(vector<int>& v, int start_index, int end_index) {
	int pivot = v[start_index];
	int mark = start_index;
	for (int i = start_index + 1; i <= end_index; ++i) {
		if (v[i] < pivot) {
			mark++;
			int t = v[mark];
			v[mark] = v[i];
			v[i] = t;
		}
	}

	v[start_index] = v[mark];
	v[mark] = pivot;
	return mark;
}

void quick_sort(vector<int>& v, int start_index, int end_index) {
	if (start_index >= end_index) {
		return;
	}
	// int pivot_index = partition1(v, start_index, end_index);
	int pivot_index = partition2(v, start_index, end_index);
	quick_sort(v, start_index, pivot_index - 1);
	quick_sort(v, pivot_index + 1, end_index);
}

// 3. 递归 -> 非递归
void
quick_sort_stack(vector<int>& v, int start_index, int end_index) {
	// map: start_index, end_index
	stack<map<string, int>> s;
	map<string, int> m1;
	m1["start_index"] = start_index;
	m1["end_index"] = end_index;
	s.push(m1);

	while (!s.empty()) {
		// 得到起止下标
		map<string, int> m = s.top();
		s.pop();
		// 得到基准元素位置
		int pivot_index = partition1(v, m["start_index"], m["end_index"]);
		// 根据基准元素分成两部分，把每一部分的起止下标入栈
		if (m["start_index"] < pivot_index - 1) {
			map<string, int> l_m;
			l_m["start_index"] = m["start_index"];
			l_m["end_index"] = pivot_index - 1;
			s.push(l_m);
		}
		if (pivot_index + 1 < m["end_index"]) {
			map<string, int> r_m;
			r_m["start_index"] = pivot_index + 1;
			r_m["end_index"] = m["end_index"];
			s.push(r_m);
		}
	}
}


/*** 再次练习 ***/
int 
partition1_again(vector<int>& arr, int start_index, int end_index) {
	int pivot = arr[start_index];
	int left = start_index;
	int right = end_index;
	while (left != right) {
		while (left < right && arr[right] > pivot) right--;
		while (left < right && arr[left] <= pivot) left++;
		if (left < right) {
			int t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
		}
	}

	arr[start_index] = arr[left];
	arr[left] = pivot;
	return left;
}
int
partition2_again(vector<int>& arr, int start_index, int end_index) {
	int pivot = arr[start_index];
	int mark = start_index;
	for (int i = start_index + 1; i <= end_index; ++i) {
		if (pivot >= arr[i]) {
			mark++;
			int t = arr[i];
			arr[i] = arr[mark];
			arr[mark] = t;
		}
	}
	arr[start_index] = arr[mark];
	arr[mark] = pivot;
	return mark;
}
void
quick_sort_again(vector<int>& arr, int start_index, int end_index) {
	if (start_index >= end_index) {
		return ;
	}
	// int pivot_index = partition1_again(arr, start_index, end_index);
	int pivot_index = partition2_again(arr, start_index, end_index);
	quick_sort_again(arr, start_index, pivot_index - 1);
	quick_sort_again(arr, pivot_index + 1, end_index);
}

int main(int argc, char const *argv[]) {
	std::vector<int> v{9,8,7,6,5,4,3,2,1,0};
	printArray(v);
	// quick_sort(v, 0, v.size() - 1);
	// quick_sort_again(v, 0, v.size() - 1);
	quick_sort_stack(v, 0, v.size() - 1);
	printArray(v);
	return 0;
}




















