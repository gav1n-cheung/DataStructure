#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

int main() {
    int n = 50000;
    cout << "Test for Random Array,size= " << n << ", random range[0," << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr1, n);
    SortTestHelper::testSort("merge sort BU",MergeSort::mergeSortBU,arr2,n);
    SortTestHelper::testSort("Insertion Sort", InsertionSort::insertionSort, arr3, n);


    delete[]arr1;
    delete[]arr2;
    cout<<endl;

    int swapTimes=0;
    cout<<"Test for Random Nearly Ordered Array,size = "<<n<<", swap time = "<<swapTimes<<endl;
    int *arr4= SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    int *arr5= SortTestHelper::copyIntArray(arr4,n);
    int *arr6= SortTestHelper::copyIntArray(arr4,n);
    int *arr7= SortTestHelper::copyIntArray(arr4,n);

    SortTestHelper::testSort("merge sort",MergeSort::mergeSort,arr4,n);
    SortTestHelper::testSort("merge sort BU",MergeSort::mergeSortBU,arr5,n);
    SortTestHelper::testSort("merge sort BU2",MergeSort::mergeSortBU2,arr6,n);
    SortTestHelper::testSort("insertion sort",InsertionSort::insertionSort,arr7,n);
    cout<<endl;


    //如果有一百万个元素的数组，其中元素只是在[0-10)内的，则这种数组会导致未经优化的快速排序非常缓慢；
    //这是因为我们在前面的代码中没有规定e=v时的操作，而我们将=v的元素无论是放到<v的部分或者>v的部分，都会使得两部分极度的不平衡
    //
    n=1000000;
    int *arr8= SortTestHelper::generateRandomArray(n,0,10);
    int *arr9= SortTestHelper::copyIntArray(arr8,n);
    int *arr10= SortTestHelper::copyIntArray(arr8,n);
    cout << "Test for Random Array,size= " << n << ", random range[0," << 10 << "]" << endl;
    SortTestHelper::testSort("merge sort",MergeSort::mergeSort,arr8,n);
    SortTestHelper::testSort("quick sort 3 ways",QuickSort::quickSort3,arr9,n);
    SortTestHelper::testSort("quick sort",QuickSort::quickSort2,arr10,n);

    cout<<endl;
    //不经优化的快速排序会导致递归树的不平衡，很有可能不是nlogn级别的排序算法了，最差情况下高度为n，变为O(n^2)的算法，排序一个一百万打乱100元素的数组需要60s，完全不能接受
    //一个完全有序的数组，我们选择最开始的元素作为v，则右侧没有比v更小的元素了，则p=l+1,则partition得到的是[l+1,r]，仍然是前面的情况，则这个深度为n，则导致O(n^2)的复杂度
    //要解决这个问题，我们可以在选择v时候进行随机选择，这种解决方式的数学期望复杂度仍然是O(nlogn)，当然这不代表每次排序的复杂度是nlogn
    swapTimes=100;
    int *arr11= SortTestHelper::generateNearlyOrderedArray(n,100);
    int *arr12= SortTestHelper::copyIntArray(arr10,n);
    int *arr13= SortTestHelper::copyIntArray(arr10,n);
    int *arr14= SortTestHelper::copyIntArray(arr10,n);
    cout<<"Test for Random Nearly Ordered Array,size = "<<n<<", swap time = "<<swapTimes<<endl;
    SortTestHelper::testSort("merge sort",MergeSort::mergeSort,arr11,n);
//    SortTestHelper::testSort("quick sort",QuickSort::quickSort,arr12,n);
    SortTestHelper::testSort("quick sort 2",QuickSort::quickSort2,arr13,n);
    SortTestHelper::testSort("quick sort 3 ways",QuickSort::quickSort3,arr14,n);

    return 0;
}
