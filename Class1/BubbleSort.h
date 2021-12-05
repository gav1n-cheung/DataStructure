//
// Created by cheung on 11/26/21.
//

#ifndef CLASS1_BUBBLESORT_H
#define CLASS1_BUBBLESORT_H

#include <iostream>

namespace BubbleSort {
    template<typename T>
    void bubbleSort(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int e=arr[i];
            int j;
            for ( j = 0; j < n - i - 1; ++j) {
//                if (arr[j] > arr[j + 1]) { std::swap(arr[j], arr[j + 1]); }//像插入排序一样将交换变为赋值操作
                if (e > arr[j + 1]) arr[j]=arr[j+1];
                else {
                    arr[j]=e;
                    e=arr[j+1];
                }
            }

        }
        return;
    }

    template<typename T>
    void bubbleSort2(T arr[],int n){
        bool swapped;
        do{
            swapped= false;
            for (int i = 1; i < n; ++i) {
                if (arr[i-1]>arr[i]){
                    swap(arr[i-1],arr[i]);
                    swapped= true;
                }
            }
            n--;

        } while (swapped);
    }

    template<typename T>
    void bubbleSort3(T arr[],int n){
        int newn;
        do {
            newn=0;
            for (int i = 1; i < n; ++i) {
                if (arr[i-1]>arr[i]){
                    swap(arr[i-1],arr[i]);
                    newn=i;
                }
            }
            n=newn;
        } while (newn>0);
    }
}


#endif //CLASS1_BUBBLESORT_H
