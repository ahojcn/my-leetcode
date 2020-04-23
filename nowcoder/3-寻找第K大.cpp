// https://www.nowcoder.com/questionTerminal/e016ad9b7f0b45048c58a9f27ba618bf

class Finder {
private:
    int quickFind(vector<int>& a, int start_index, int end_index, int k) {
    	int l = start_index;
    	int r = end_index;
    	int pivot = a[l];

    	while (l < r) {
    		while (l < r && a[r] >= pivot) r--;
    		if (l < r) a[l++] = a[r];
    		while (l < r && a[l] <= pivot) l++;
    		if (l < r) a[r--] = a[l];
    	}
    	a[l] = pivot;

    	int big_num = end_index - l;
        //如果哨兵刚好是第K大的数
        if (k - big_num - 1 == 0)
            return pivot;
        else if (k - big_num - 1 > 0) {
            //如果右侧数字个数不够K个，则从左侧找第k-big_num-1大的数
            return quickFind(a, start_index, l - 1, k - big_num - 1);
        } else {
            //如果右侧数字个数比K多，则在右侧找第K大的数
            return quickFind(a, l + 1, end_index, k);
        }
    }
    
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quickFind(a, 0, n-1, K);
    }
};
