#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <algorithm>

class HeapSort {
public:
	int* heapSort(int* A, int n) {
		// write code here
		//���������
		Heap(A, n);
		//���ν����Ԫ�ؼ�����Ԫ�غ����һ��Ԫ�ؽ���������Ԫ�ظ�����һ
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
		//����Ѷ��±��0��ʼ
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

