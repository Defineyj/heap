#include "Heap.h"
#include "ShellSort.h"
#include "HeapSort.h"

template <typename T>
void shaftdown(vector<T> &num, int index, int size)
{
	int i = index;
	int j = index * 2 + 1;
	T temp = num[index];

	while (j < size)
	{
		if (j<size - 2 && num[j]<num[j + 1])
			++j;
		if (temp < num[j])
		{
			std::swap(num[j], num[i]);
			i = j;
			j = i * 2 + 1;
		}
		else
			break;
	}
}
template <class T>
void createheap(vector<T> &num,int size)
{
	/*if (num.empty()) return;

	int size = num.size();*/
	int index = size / 2 - 1;

	while (index >= 0)
	{
		shaftdown(num, index, size);
		--index;
	}
}

template <typename T>
vector<T> hs(vector<T> &num)
{
	int size = num.size();
	vector<T> res(num);
	createheap(num,size);
	for (int i = size - 1; i >=0; --i)
	{
		std::swap(num[i], num[0]);
		res[i] = num[i];
		createheap(num, i);
	}
	return res;
}

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
	auto hh = hs(testData);
	ShellSort<int> test(testData, numEle);
	test.shellSort();
	test.out();

	int A[] = { 1,5,7,3,8,2,6,4 };
	HeapSort* H = new HeapSort();
	auto a = H->heapSort(A, sizeof(A) / sizeof(A[0]));
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
		cout << A[i] << ' ';
	cout << endl;
	return 0;
}
