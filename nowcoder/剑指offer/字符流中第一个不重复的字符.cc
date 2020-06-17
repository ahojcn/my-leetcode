// https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tags=&title=&diffculty=0&judgeStatus=0&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution
{
private:
    unsigned int cnt[128];
    queue<char> q;

public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        ++cnt[ch - '\0'];
        if (cnt[ch - '\0'] == 1) {
            q.push(ch);
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!q.empty() && cnt[q.front()] >= 2) q.pop();
        if (q.empty()) return '#';
        else return q.front();
    }

    Solution()
    {
        memset(cnt, 0, sizeof(cnt));
    }

};

