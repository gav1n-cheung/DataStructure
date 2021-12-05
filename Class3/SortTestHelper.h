//
// Created by cheung on 11/26/21.
//
#include <iostream>
#include <cassert>

using namespace std;

#ifndef CLASS1_SORTTESTHELPER_H
#define CLASS1_SORTTESTHELPER_H
namespace SortTestHelper {
    //生成有n个元素的随机数组，每个元素的随机范围为[rangL,rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i)
            arr[i] = rand() % (rangeL - rangeR + 1) + rangeL;
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; ++i) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx],arr[posy]);
        }
        return arr;
    }


    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
        return;
    }

    int *copyIntArray(int arr[], int n) {
        int *arrCopy = new int[n];
        copy(arr, arr + n, arrCopy);
        return arrCopy;
    }
}


#endif //CLASS1_SORTTESTHELPER_H
