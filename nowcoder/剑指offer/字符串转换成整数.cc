class Solution {
public:
    int StrToInt(string str) {

        if (str.empty()) return 0;

        int result = 0;
        int flag = 1;
        for (int i = 0; i < str.size(); ++i) {

            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + (str[i] - '0');
            } else if (str[i] == '-' || str[i] == '+') {
                if (str[i] == '-') {
                    flag = -1;
                }
            } else {
                return 0;
            }
        }

        return result * flag;
    }
};