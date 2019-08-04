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

//�ѵ��»������㷨���ӽڵ�start��mΪֹ�����ϵ��±Ƚϣ������ŮС�ڸ��ڵ㣬
//�ؼ����ϸ����������²�Ƚ̣����ֲ���������Ϊ��С��
template<class T>
void MinHeap<T>::shiftDown(int start, int m)
{
	int i = start;//iΪ��ǰ���������
	int j = 2 * i + 1;//jΪ��ǰ������i������
	T temp = heap[i];//������ڵ��ֵ
	while (j <= m)
	{
		//jָ��������������С���Ǹ�
		if (j < m && heap[j + 1] < heap[j])
			++j;

		if (temp <= heap[j])
			break;//���������������С���Ǹ����ڸ��ڵ㣬��������		
		else
		{
			heap[i] = heap[j];//���򣬽������ڵ���ӽڵ�
			i = j;//�������±Ƚϣ���ǰ���ӽڵ���Ϊ��һ�εĸ��ڵ�
			j = 2 * i + 1;
		}
		
	
	}
	heap[i] = temp;
}

//�½ڵ�������룬����Ҫ�������ϱȽϣ���start��ʼ��һֱ��0
template<typename T>
void MinHeap<T>::shiftUp(int start)
{
	int j = start;//jΪ�ӽڵ�
	int i = (j - 1) / 2;//iΪ���ڵ�
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
		heap[j] = temp;//��Ϊ���ڵ�����ӽڵ㣬����֮ǰ���ڵ��ֵ���������ӽڵ㣬֮ǰ�ӽڵ��ֵҲҪ��ֵ�����ڵĸ��ڵ�
	}
}

template<typename T>
bool MinHeap<T>::insert(const T& x)
{
	if (currentSize == maxHeapSize)
	{
		/*std::cerr << "err" << std::endl;
		return false;*/
		//�Ѵ�С���������·���
		//����д�Ŀ����еㆪ��
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

