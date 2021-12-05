//
// Created by cheung on 11/28/21.
//

#ifndef CLASS2_QUICKSORT_H
#define CLASS2_QUICKSORT_H

#include <iostream>

namespace QuickSort {

    //partition实现,对arr[l....r]进行partition
    //返回p，使得arr[l...p-1]<arr[p];arr[P+1]>arr[p]
    template<typename T>
    int __partition(T arr[], int l, int r) {
        swap(arr[rand() % (r - l + 1) + l], arr[l]);
        T v = arr[l];

        int j = l;
        //arr[l+1....j]<v;arr[j+1...i)>v；需要注意的是，我们首先设j=l，则[l+1,j]这个空间一开始是不存在的，而i是我们当前正在考察的元素，不包括在区间内
        //而区间[j+1,l)由于为开区间，则也为空，这两个区间都为空，自然就满足了前面的条件
        for (int i = l + 1; i <= r; ++i) {
            if (arr[i] < v) {
                std::swap(arr[i], arr[j + 1]);
                j++;
            }
        }
        std::swap(arr[l], arr[j]);
        return j;
    }

    //快速递归实现,对arr[l....r]进行排序
    template<typename T>
    void __quickSort(T arr[], int l, int r) {
//        if (l >= r) return;
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr, l, r);
            return;
        }

        int p = __partition(arr, l, r);
        __quickSort(arr, l, p - 1);
        __quickSort(arr, p + 1, r);
    }

    //快速排序入口
    template<typename T>
    void quickSort(T arr[], int n) {
        srand(time(NULL));
        __quickSort(arr, 0, n - 1);
    }

    template<typename T>
    int __partition2(T arr[], int l, int r) {
        swap(arr[l], arr[rand() % (r - l) + l]);
        T v = arr[l];
        //arr[l+1.....i）<=v;arr(j.....r]>=v
        int i = l + 1, j = r;
        while (true) {
            while (i <= r && arr[i] < v) i++;
            while (j >= l + 1 && arr[j] > v) j--;
            if (i > j) break;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        swap(arr[j], arr[l]);
        return j;
    }


    template<typename T>
    void __quickSort2(T arr[], int l, int r) {
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr, l, r);
            return;
        }
        int p = __partition2(arr, l, r);
        __quickSort2(arr, l, p - 1);
        __quickSort2(arr, p + 1, r);
    }

    template<typename T>
    void quickSort2(T arr[], int n) {
        srand(time(NULL));
        __quickSort2(arr, 0, n - 1);
    }

    template<typename T>
    void __partition3(int arr, int l, int r) {

    }

    //三路快速排序处理 arr[l...r]
    //将arr[l...r]分为<v;--v;>v三部分
    //之后递归对<v;>v两部分继续进行三路快速排序
    template<typename T>
    void __quickSort3ways(T arr[], int l, int r) {
        if (r - l <= 15) {
            InsertionSort::insertionSort(arr, l, r);
            return;
        }
        //partition
        swap(arr[l], arr[rand() % (r - l) + l]);
        T v = arr[l];
        int lt = l;//arr[l+1...lt]<v
        int gt = r + 1;//arr[gt....r]>v
        int i = l + 1;//arr[lt+1...i)==v
        while (i < gt) {
            if (arr[i] < v) {
                swap(arr[i++], arr[++lt]);
            } else if (arr[i] > v) {
                swap(arr[i], arr[--gt]);
            } else {
                i++;
            }
        }
        swap(arr[l], arr[lt]);
        __quickSort3ways(arr, l, lt - 1);
        __quickSort3ways(arr, gt, r);
    }

    template<typename T>
    void quickSort3(T arr[], int n) {
        srand(time(NULL));
        __quickSort3ways(arr, 0, n - 1);
    }


}


#endif //CLASS2_QUICKSORT_H
