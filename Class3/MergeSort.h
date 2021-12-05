//
// Created by cheung on 11/27/21.
//

#ifndef CLASS2_MERGESORT_H
#define CLASS2_MERGESORT_H

#include <iostream>
#include "InsertionSort.h"

namespace MergeSort {

    //将arr[l..mid]和arr[mid+1...r]两部分进行归并
    template<typename T>
    void __merge(T arr[], int l, int mid, int r) {
        T aux[r - l + 1];
        for (int i = l; i <= r; ++i)
            aux[i - l] = arr[i];
        int i = l, j = mid + 1;
        for (int k = l; k <= r; ++k) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }

    }

    //递归使用归并排序,对arr[l....r]的范围进行排序
    template<typename T>
    void __mergeSort(T arr[], int l, int r) {
//        if (l >= r) return;//在所有高级排序中只要递归到底部了，保证数组有序的概率是比较大的，转而使用插入排序，降低复杂度
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr, l, r);
            return;
        }
        int mid = (l + r) / 2;//l+r可能导致int类型溢出
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        if (arr[mid] > arr[mid + 1])
            //如果arr[mid]<arr[mid]，则arr整个数组就是有序的了，无需再归并了，这样可以改善数组有序情况下的归并排序，但是这种优化也无法使得算法复杂度降到O(N)
            __merge(arr, l, mid, r);
    }

    template<typename T>
    void mergeSort(T arr[], int n) {
        __mergeSort(arr, 0, n - 1);//注意边界问题,这里使用[]边界,因此传入的右边界应该是n-1
    }

    template<typename T>
    void mergeSortBU(T arr[], int n) {
        for (int sz = 1; sz <= n; sz += sz) {
            for (int i = 0; i + sz< n; i += sz + sz) {
                __merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));
            }
        }
    }

    template<typename T>
    void mergeSortBU2(T arr[], int n) {
        for (int i = 0; i < n; i+=16)
            InsertionSort::insertionSort(arr,i, min(i+15,n-1));

        for (int sz = 16; sz <= n; sz += sz) {
            for (int i = 0; i < n-sz; i += sz + sz) {
                if(arr[i+sz-1]>arr[i+sz])
                __merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));
            }
        }
    }

}

#endif //CLASS2_MERGESORT_H