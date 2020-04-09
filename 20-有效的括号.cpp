// 使用 stack  4ms, 6.4mb
class Solution {
public:
    bool isValid(string s) {
        if (s == "") {
            return true;
        }

        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '(':
                    st.push(')');
                    break;
                case '{':
                    st.push('}');
                    break;
                case '[':
                    st.push(']');
                    break;
                default:
                    if (st.empty() || s[i] != st.top()) {
                        return false;
                    } else {
                        st.pop();
                    }
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

// python  60 ms	12 MB
// class Solution:
//     def isValid(self, s):
//         while '{}' in s or '()' in s or '[]' in s:
//             s = s.replace('{}', '')
//             s = s.replace('[]', '')
//             s = s.replace('()', '')
//         return s == ''