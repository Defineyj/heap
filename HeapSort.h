#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <algorithm>

class HeapSort {
public:
	int* heapSort(int* A, int n) {
		// write code here
		//构建大根堆
		Heap(A, n);
		//依次将最顶的元素即最大的元素和最后一个元素交换，并且元素个数减一
		int temp = n;
		while (temp > 1)
		{
			std::swap(A[0], A[--temp]);
			sort(A, 0, temp);
		}
		return A;
	}
	void Heap(int *A, int n)
	{
		//这里堆顶下标从0开始
		int index = n / 2 - 1;
		for (; index >= 0; index--)
		{
			sort(A, index, n);

		}
	}
	void sort(int *A, int index, int n)
	{
		int lchild = 2 * index + 1;
		int rchild = 2 * index + 2;
		int max = index;
		if (lchild<n && A[lchild]>A[max])max = lchild;
		if (rchild<n && A[rchild]>A[max])max = rchild;
		if (max != index)
		{
			std::swap(A[max], A[index]);
			sort(A, max, n);
		}

	}
};
#endif // !HEAPSORT_H

