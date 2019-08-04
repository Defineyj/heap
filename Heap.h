#pragma once
#include <iostream>
#define DefaultSize  10

template <typename T>
class MinHeap
{
public:
	MinHeap(int sz = DefaultSize);
	MinHeap(T arr[], const int n);
	~MinHeap() { delete[] heap; }
	bool isEmpty() const { return currentSize == 0; }
	bool isFull() const { return currentSize == maxHeapSize; }
	void print();

	void makeEmpty() { currentSize = 0; }	
	bool insert(const T& x);
	bool removeMin();
private:
	T *heap, *Defaultheap;
	
	static const int a;
	int currentSize;
	int maxHeapSize;
	void getDefaultHeap();
	void shiftDown(int start, int m);
	void shiftUp(int start);
};


template <typename T>
const int MinHeap<T>::a = 1;

template<class T>
MinHeap<T>::MinHeap(int sz)
{
	maxHeapSize = (sz < DefaultSize) ? DefaultSize : sz;
	heap = new(std::nothrow) T[maxHeapSize];
	if (!heap)
	{
		std::cerr << "err\n" << std::endl;
		exit(1);
	}

	currentSize = 0;

}

template<class T>
MinHeap<T>::MinHeap(T arr[], const int n)
{
	maxHeapSize = (n < DefaultSize) ? DefaultSize : n;
	heap = new(std::nothrow) T[maxHeapSize];
	if (!heap)
	{
		std::cerr << "err\n" << std::endl;
		exit(1);
	}

	currentSize = n;

	for (int i = 0; i < n; ++i)
		heap[i] = arr[i];	

	print();

	int currentPos = (currentSize - 2) / 2;
	while (currentPos >= 0)
	{
		shiftDown(currentPos, currentSize - 1);
		--currentPos;
	}

	getDefaultHeap();
}

//堆的下滑调整算法，从节点start到m为止，从上到下比较，如果子女小于父节点，
//关键码上浮，据需向下层比教，将局部子树调整为最小堆
template<class T>
void MinHeap<T>::shiftDown(int start, int m)
{
	int i = start;//i为当前子树根结点
	int j = 2 * i + 1;//j为当前子树的i的左孩子
	T temp = heap[i];//保存根节点的值
	while (j <= m)
	{
		//j指向两个孩子中最小的那个
		if (j < m && heap[j + 1] < heap[j])
			++j;

		if (temp <= heap[j])
			break;//如果两个孩子中最小的那个大于父节点，则不做交换		
		else
		{
			heap[i] = heap[j];//否则，交换父节点和子节点
			i = j;//继续向下比较，当前的子节点作为下一次的父节点
			j = 2 * i + 1;
		}
		
	
	}
	heap[i] = temp;
}

//新节点从最后插入，所以要从下向上比较，从start开始，一直到0
template<typename T>
void MinHeap<T>::shiftUp(int start)
{
	int j = start;//j为子节点
	int i = (j - 1) / 2;//i为父节点
	T temp = heap[j];
	while (j > 0)
	{
		if (heap[i] < temp)
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (j - 1) / 2;
		}
		heap[j] = temp;//因为父节点大于子节点，所以之前父节点的值赋给现在子节点，之前子节点的值也要赋值给现在的父节点
	}
}

template<typename T>
bool MinHeap<T>::insert(const T& x)
{
	if (currentSize == maxHeapSize)
	{
		/*std::cerr << "err" << std::endl;
		return false;*/
		//堆大小不够，重新分配
		//这里写的可能有点啰嗦
		delete[] heap;
		++maxHeapSize;
		heap = new(std::nothrow) T[maxHeapSize];
		for (int i = 0; i < maxHeapSize - 1; ++i)
		{
			heap[i] = Defaultheap[i];
		}
		memcpy(heap, Defaultheap, (maxHeapSize - 1) * sizeof(T));
	}
	heap[currentSize] = x;
	shiftUp(currentSize);
	++currentSize;

	getDefaultHeap();
	return true;
}

template<typename T>
bool MinHeap<T>::removeMin()
{
	if (!currentSize)
	{
		std::cerr << "err" << std::endl;
		return false;
	}
	heap[0] = heap[currentSize - 1];
	--currentSize;
	shiftDown(0, currentSize - 1);
	--maxHeapSize;
	return true;
}

template <typename T>
void MinHeap<T>::print()
{
	for (int i = 0; i < maxHeapSize; ++i)
		std::cout << heap[i] << '\t';
	std::cout << std::endl;
}

template <typename T>
void MinHeap<T>::getDefaultHeap()
{
	Defaultheap = new(std::nothrow) T[maxHeapSize];

	memcpy(Defaultheap, heap, maxHeapSize * sizeof(T));
	
}

