// https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc

#include <iostream>
#include <string>

using namespace std;

// 判断是否为回文
bool isHuiWen(string str) {
	int l = 0, r = str.length() - 1;
	while (l <= r) {
		if (str[l] != str[r]) {
			// cout << "!!!" << str[l] << ", " << str[r] << endl;
			return false;
		}
		l++; r--;
	}
	return true;
}

int main() {
	string sa, sb;
	while (cin >> sa >> sb) {
		int count = 0;
		string tmp = sa;  // 保存 sa
		for (int i = 0; i < sa.length() + 1; ++i) {
			sa.insert(i, sb);
			if (isHuiWen(sa)) {
				count++;
			}
			sa = tmp;  // 恢复 sa
		}

		cout << count << endl;
	}

	return 0;
}