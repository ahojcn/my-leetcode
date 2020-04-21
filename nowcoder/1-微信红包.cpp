// https://www.nowcoder.com/questionTerminal/fbcf95ed620f42a88be24eb2cd57ec54?toCommentId=87162

// 1. 如果一个数出现次数超过一半了，排序过后，必然排在中间
// 再遍历，计算这个数出现的次数
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int mid = gifts[n / 2];
        size_t count = 0;
        for (size_t i = 0; i < gifts.size(); ++i) {
            if (gifts[i] == mid) ++count;
        }
        
        return count >= (n/2) ? mid : 0;
    }
};

// 2. 先找到出现次数最多的那个数，计算这个数出现的次数
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(gifts.size()<n) return 0;
        if(gifts.size()==0) return 0;
        int count=0,temp;
        for(int i=0;i<n;i++) {
            if(count==0) {
                temp=gifts[i];
                count=1;
            } else {
                if(temp==gifts[i])
                    count++;
                else
                    count--;
            }
        }

        int size=0;
        for(int i=0;i<n;i++) {
            if(temp==gifts[i])
                size++;
        }
        return (size>n/2)?temp:0;
    }
};
