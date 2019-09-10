#include "Heap.h"
#include "ShellSort.h"

int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };

	MinHeap<int> h(arr, 10);
	h.print();
	h.insert(0);
	h.print();
	h.insert(-1);
	h.print();
	h.insert(12);
	h.print();
	h.removeMin();
	h.print();

	const unsigned numEle = 8;
	int data[numEle] = { 1,5,7,3,8,2,6,4 };
	vector<int> testData;
	for (unsigned i = 0; i < numEle; ++i) testData.push_back(data[i]);

	ShellSort<int> test(testData, numEle);
	test.shellSort();
	test.out();
	return 0;
}
