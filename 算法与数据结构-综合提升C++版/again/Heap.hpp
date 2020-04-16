#include <cassert>
#include <iostream>

using namespace std;

class MaxHeap {
public:
	// 初始化一个空堆
	MaxHeap(const int cap) {
		m_data = new int[cap];
		m_cnt = 0;
		m_cap = cap;
	}

	// TODO : 使用 arr 初始化一个大堆
	MaxHeap(const int* arr, const int cap) {
	}

	~MaxHeap() {
		delete[] m_data;
		m_cap = 0;
		m_cnt = 0;
	}

	int size() { return m_cnt; }

	// 插入一个元素，并将大堆调整到正常
	void insert(const int item) {
		assert(m_cnt + 1 <= m_cap);
		m_data[++m_cnt] = item;
		__shiftUp(m_cnt);
	}

	// TEST : 打印 m_data
	void testPrintData() {
		cout << "m_cap: " << m_cap << ", ";
		cout << "m_cnt: " << m_cnt << ", ";
		cout << "m_data: [ ";
		for (int i = 0; i < m_cnt; ++i) {
			cout << m_data[i] << " ";
		}
		cout << "]" << endl;
	}

	// TEST : 以树状打印整个堆结构
    void testPrintTree(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        // if( typeid(Item) != typeid(int) ){
        //     cout <<"This print function can only work for int item";
        //     return;
        // }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 0 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( m_data[i] >= 0 && m_data[i] < 100 );
            cout<<m_data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 0;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(m_cnt-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( m_data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
	void __shiftUp(int k) {
		testPrintTree();
		cout << "==============" << endl;
		int parent_index = (k - 1) / 2;
		while (k > 0 && m_data[k] > m_data[parent_index]) {
			swap(m_data[k], m_data[parent_index]);
			k = parent_index;
			parent_index = (k - 1) / 2;
		}
	}

	void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

private:
	int* m_data;
	int m_cnt;  // 有效元素个数
	int m_cap;  // 总容量
};