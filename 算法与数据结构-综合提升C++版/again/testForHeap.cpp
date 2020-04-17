// test for Heap.hpp

#include <cmath>

#include "Heap.hpp"

int main () {
	srand(time(NULL));

	MaxHeap mh(100);
	for (int i = 0; i < 10; ++i) {
		mh.insert(rand() % 100);
	}
	mh.testPrintData();
	// mh.testPrintTree();
	for (int i = 0; i < 10; ++i) {
		cout << mh.pop() << " poped" << endl;
		mh.testPrintData();
	}

	return 0;
}