#include "Heap.h"

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
	return 0;
}