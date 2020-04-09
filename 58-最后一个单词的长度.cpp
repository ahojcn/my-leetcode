// 从后向前遍历
// 注意 "aaa " 的情况
// 注意 "     " 的情况
// end 去除 ' '，找到从右向左第一个不是空格的部分/字符串头
// 当 end 为字符串头时候，字符串为 "   "，start == end == 0，所以结果为 0
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return end - start;
    }
};