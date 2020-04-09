// 40ms 9.1mb
// 构造 map 上花费了一些时间
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {
        	{'I', 1},
        	{'V', 5},
        	{'X', 10},
        	{'L', 50},
        	{'C', 100},
        	{'D', 500},
        	{'M', 1000},
        };

        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
        	if (m[s[i]] < m[s[i + 1]]) {
        		ret = ret - m[s[i]];
        	} else {
        		ret = ret + m[s[i]];
        	}
        }

        return ret;
    }
};

// 网上的解法 4ms 5.6mb
#define nI 1  //直接用define I 1，好像会有歧义
#define nV 5 
#define nX 10
#define nL 50
#define nC 100
#define nD 500
#define nM 1000

int romanToInt(char* s) 
{ 
    int num = 0, flag = 0;   /*立一个flag，是因为之前我在后面会用三个if，一个else，其实我的初衷是三个if有其中任何一个满足都不要再执行else了
	                         但是如果没有flag的话，意思是第三个if如果不成立便会跳去else，比如IV，第一个if满足，然后第三个if不满足，else这时候
							 就会出来执行，很不爽*/
    while(*s != NULL)
    {
        if(*s == 'I' && (*(s + 1) == 'V' || *(s + 1) == 'X'))     //接下来的这三个if都有特殊含义，所以flag=1，普通情况属于flag=0
        {
			flag = 1;
            switch(*(s + 1))
            {
                case 'V':num += (nV - nI); s+=2; break;
                case 'X':num += (nX - nI); s+=2; break;
            }
        }
        if(*s == 'X' && (*(s + 1) == 'L' || *(s + 1) == 'C'))
        {
			flag = 1;
            switch(*(s + 1))
            {
                case 'L':num += (nL - nX); s+=2; break;
                case 'C':num += (nC - nX); s+=2; break;
            }
        }
        if(*s == 'C' && (*(s + 1) == 'D' || *(s + 1) == 'M'))
        {
			flag = 1;
            switch(*(s + 1))
            {
                case 'D':num += (nD - nC); s+=2; break;
                case 'M':num += (nM - nC); s+=2; break;
            }
        }
        if(flag == 0)   //本来这里是else的，改为if(flag == 0)
        {
            switch(*s)
            {
                case 'I':num += nI; s += 1; break;
                case 'V':num += nV; s += 1; break;
                case 'X':num += nX; s += 1; break;
                case 'L':num += nL; s += 1; break;
                case 'C':num += nC; s += 1; break;
                case 'D':num += nD; s += 1; break;
                case 'M':num += nM; s += 1; break;
            }
        }
		flag = 0;  //最后置回普通状态
    }
    return num;
}