#include <iostream>
#include <vector>

using namespace std;

void adjustDown(vector<int>& arr, int parent_index, int len) {
	int root = arr[parent_index];
	int child_index = 2 * parent_index + 1;
	while (child_index < len) {
		// 如果有右孩子，right < left
		if (child_index + 1 < len && arr[child_index + 1] < arr[child_index]) {
			++child_index;
		}

		// 如果 父 < left && 父 < right
		if (root <= arr[child_index]) {
			break;
		}

		arr[parent_index] = arr[child_index];
		parent_index = child_index;
		child_index = 2 * child_index + 1;
	}

	arr[parent_index] = root;
}

// 构建堆
void buildHeap(vector<int>& arr) {
	// 从最后一个非叶子节点开始，依次做下沉调整
	for (int i = (arr.size() - 2) / 2; i >= 0; --i) {
		adjustDown(arr, i, arr.size());
	}
}

void printArr(const vector<int>& arr) {
  cout << "[";
  for (size_t i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v{9,10,8,7,6,5,4,3,2,1};
	printArr(v);
	buildHeap(v);
	printArr(v);
	return 0;
}
