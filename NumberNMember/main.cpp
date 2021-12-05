#include <iostream>
#include <time.h>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include <ctime>

template<typename T>
int __partition(T arr[], int l, int r) {

    int p = rand() % (r - l + 1) + l;
    swap(arr[l], arr[p]);

    int j = l; //[l+1...j] < p ; [lt+1..i) > p
    for (int i = l + 1; i <= r; i++)
        if (arr[i] < arr[l])
            swap(arr[i], arr[++j]);

    swap(arr[l], arr[j]);

    return j;
}


template<typename T>
int __quickSort(T arr[], int l, int r, int target) {
    if (l == r) {
        return arr[l];
    }

//    if(r-l<=15){
//        InsertionSort::insertionSort(arr,l,r);
//    }
/*    int p=__partition(arr,l,r);
    std::swap(arr[l],arr[rand()%(r-l+1)+l]);
    //[l.....lt]<v;[lt+1....gt-1]==v;[gt....r]>v;
    int v=arr[l];
    int lt=l;
    int gt=r+1;
    int i=l+1;
    //[l...lt]<v;[lt+1.....i)==v;[gt....r]>v
    while(i<gt){
        if (arr[i]<v) std::swap(arr[i++],arr[++lt]);
        else if(arr[i]>v) std::swap(arr[i],arr[--gt]);
        else i++;
    }
    std::swap(arr[l],arr[lt]);*/
    int p = __partition(arr, l, r);
    if (p < target) return __quickSort(arr, p + 1, r, target);
    else if (p > target) return __quickSort(arr, l, p - 1, target);
    else return arr[p];
}

template<typename T>
T quickSort(T arr[], int n, int target) {
    srand(time(NULL));
    return __quickSort(arr, 0, n - 1, target);
}

template<typename T>
T quickSort2(T arr[], int n, int target) {
    QuickSort::quickSort3(arr, n);
    cout << arr[target] << endl;
}

int main() {
    srand(time(NULL));
/*    int *arr = new int[10];
    int *arr1 = SortTestHelper::copyIntArray(arr,10);
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + rand() % 10;
    }
    for (int i = 0; i < 10; ++i) {
        swap(arr[0], arr[rand() % 10]);
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    cout<<"helloworld"<<endl;
    int n = 10000000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    clock_t startTime = clock();
    int res = quickSort(arr, n, 5);
    cout << res << endl;
    clock_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
    startTime = clock();
    quickSort2(arr2, n, 5);
    endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
    delete[]arr;
    delete[]arr2;
    return 0;
}
