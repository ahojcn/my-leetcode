// 1. 数学方法
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
        	return 0;
        }
        if (x < 0) {
        	return -reverse(-x);
        }

        long res = 0;
        while (x > 0) {
        	int e = x % 10;
        	x /= 10;
        	res = res * 10 + e;
        }
        if (res > INT_MAX) {
        	return 0;
        }

        return res;
    }
};

// 2. 字符串翻转
class Solution {
public:
	int reverse(int x) {
		if (x == INT_MIN) {
			return 0;
		}
		if (x < 0) {
			return -reverse(-x);
		}
		long res = 0;
		string str = std::to_string(x);
		string res_str;
		for (int i = str.size() - 1; i >= 0; --i) {
			res_str.push_back(str[i]);
		}
		res = std::atoi(res_str.c_str());
		if (res > INT_MAX) {
			return 0;
		}
		return res;
	}
};
