// https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&&tqId=11201&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
	int Add(int num1, int num2) {
		while (num2 != 0) {
			int tmp = num1 ^ num2;
			num2 = (num1 & num2) << 1;
			num1 = tmp;
		}
		return num1;
	}
};