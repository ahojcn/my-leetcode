// https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tags=&title=&diffculty=0&judgeStatus=0&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {

        int left = 0, right = data.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == k) {
                right = mid;
            } else if (data[mid] > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << "finally left: " << left << endl;

        int cnt = 0;
        for (int i = left; i < data.size(); ++i) {
            if (data[i] == k) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt;

    }
};