// 1. 双指针 O(m + n)
// 遍历 haystack 的每一个字符作为开头
// 0 ms	6.9 MB
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }

        size_t i = 0, j = 0;
        int ret = -1;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                if (ret == -1) {
                    ret = i;
                }
                ++i; ++j;
            } else {
                if (ret != -1) {
                    j = 0;
                	// 回溯
                    i = ret + 1;
                    ret = -1;
                } else {
                    ++i;
                }
            }
        }
        // i-ret 如果不和 needle.size() 相等，则不存在
        if ((i - ret) != needle.size()) {
            ret = -1;
        }

        return ret;
    }
};

// 2. 利用 map
// 将 haystack 拆分成长度为 needle.size() 的字符串，作为 key 存到 map 中，index 存为第二个参数
// 12 ms	8 MB
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }

        map<string, size_t> m;
        for (size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
            string key = haystack.substr(i, needle.size());
            // 如果没有这个 key 才添加到 map 中（也就是说只返回第一次出现的位置）
            if (m.find(key) == m.end()) {
                m[key] = i;
            }
        }

        if (m.find(needle) != m.end()) {
            return m[needle];
        }
        return -1;
    }
};

// 3. KMP
// 还没学会 TODO

