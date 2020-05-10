# https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/

class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()  # 去除首位空格
        res = []
        i = j = len(s) - 1
        while i >= 0:
            while i >= 0 and s[i] != ' ':
                i = i - 1
            res.append(s[i + 1: j + 1])
            while s[i] == ' ':
                i = i - 1
            j = i
        return ' '.join(res)