// 哈希
class Solution {
public:
    vector<int>
	twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> r;
		for (int i = 0; i < nums.size(); ++i) {
			int tmp = target - nums[i];
			if (r.find(tmp) != r.end()) {
				return {r[tmp], i};
			}

			r[nums[i]] = i;
		}
		return {};
	}
};

// 暴力
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }

        return ret;
    }
};