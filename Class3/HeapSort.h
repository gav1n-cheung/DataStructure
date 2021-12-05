//
// Created by cheung on 12/2/21.
//

#ifndef CLASS3_HEAPSORT_H
#define CLASS3_HEAPSORT_H

#include "Heap.h"

namespace HeapSort {

    template<typename T>
    void heapSort1(T arr[], int n) {

        MaxHeap<T> maxheap = MaxHeap<T>(n);
        for (int i = 0; i < n; ++i)
            maxheap.insert(arr[i]);
        for (int i = n - 1; i >= 0; i--) {
            arr[i] = maxheap.extractMax();
        }
    }

    template<typename T>
    void heapSort2(T arr[], int n) {
        MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
        for (int i = n - 1; i >= 0; i--)
            arr[i] = maxheap.extractMax();
    }

    template<typename Item>
    void __shiftDown(Item arr[],int n,int k){
        Item aux=arr[k];
        while (2 * k +1< n) {
            int j = 2 * k+1; //在此轮循环中，data[k]和data[j]交换位置
            if (j + 1 < n && arr[j + 1] > arr[j])
                j += 1;
            if (aux >= arr[j]) {
                break;
            }
            arr[k]=arr[j];
            k = j;
        }
        arr[k]=aux;

    }

    template<typename T>
    void heapSort(T arr[], int n) {

        //heapify过程，将arr构建成为了堆
        for (int i = (n - 1) / 2; i >= 0; i--)
            __shiftDown(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            __shiftDown(arr, i, 0);
        }

    }
}
#endif //CLASS3_HEAPSORT_H
