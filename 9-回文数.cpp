// 1. 基础版本 8ms 6.1mb
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
        	return false;
        }

        long int res = 0, my_x = x;
        while (x != 0) {
        	int d = x % 10;
        	res = res * 10 + d;
        	x = x / 10;
        }
        if (res == my_x) {
        	return true;
        } else {
        	return false;
        }
    }
};

// 2. 另一个版本 20ms 5.9mb
// 因为多增加了 if 所以时间较长了
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 10 && x >= 0) {
        	return true;
        }
        if (x < 0 || x % 10 == 0) {
        	return false;
        }

        long int res = 0, my_x = x;
        while (x != 0) {
        	int d = x % 10;
        	res = res * 10 + d;
        	x = x / 10;
        }
        printf("res %d\n", res);

        return res == my_x;
    }
};

// 3. 转字符串解  28ms  6mb
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 10 && x >= 0) {
        	return true;
        }
        if (x < 0 || x % 10 == 0) {
        	return false;
        }

        std::string x_str = std::to_string(x);
        int start = 0;
        int end = x_str.size() - 1;
        while (start < end) {
        	if (x_str[start] != x_str[end]) {
        		return false;
        	}
        	start ++;
        	end --;
        }

        return true;
    }
};