#ifndef __COMMON__
#define __COMMON__

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
using namespace std;

void printArray(const std::vector<int>& v) {
	cout << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << "]" << endl;
}

#endif