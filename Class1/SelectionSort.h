//
// Created by cheung on 11/26/21.
//

#ifndef CLASS1_SELECTIONSORT_H
#define CLASS1_SELECTIONSORT_H
#include <iostream>

namespace SelectionSort{

    template<typename T>
    void selectionSort(T arr[],int n){
        for (int i = 0; i < n; ++i) {
            int minIndex=i;
            for (int j = i; j < n; ++j) {
                if(arr[j]<arr[minIndex]) minIndex=j;
            }
            std::swap(arr[i],arr[minIndex]);
        }
    }
}






#endif //CLASS1_SELECTIONSORT_H
