//
// Created by cheung on 11/26/21.
//

#ifndef CLASS1_INSERTIONSORT_H
#define CLASS1_INSERTIONSORT_H

#include <iostream>

namespace InsertionSort {
    template<typename T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; ++i) {
            //寻找元素arr[i]合适的插入位置
/*            for (int j = i; j > 0; j--) {
                if(arr[j]<arr[j-1]) std::swap(arr[j],arr[j-1]);
                else break;//只要arr[i]>arr[i-1]就可以保证已经遍历的数组是有序的了,因为这个条件在前面的i都必然成立
            }*/
            //更简洁的实现
            T e = arr[i];
            int j; //j保存元素e应该插入的位置
            for (j = i; j > 0 && (arr[j - 1] > e); j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    template<typename T>
    void insertionSort(T arr[], int l, int r) {
        for (int i = l + 1; i <= r; ++i) {
            T e = arr[i];
            int j;
            for (j = i; j > l && arr[j - 1] > e; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
        return;
    }
}


#endif //CLASS1_INSERTIONSORT_H
