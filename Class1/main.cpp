#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
/* 排序算法
 * O(n^2)的排序算法--基础
 */

/* 选择排序
 * 选择剩下元素中的最小值依次排序
 * 复杂度O(n^2)
 */
/* 插入排序
 * 和选择排序最大的区别就是可以提前结束循环
 * 复杂度O(n^2)
 * 但是如果排序的数组是有序的,复杂度会大大下降,如果完全有序,则复杂度降为O(n^2)
 */
/* 冒泡排序
 *
 */



int main() {
    int n = 10000000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n,0);
    int *arr2= SortTestHelper::copyIntArray(arr,n);
    int *arr3= SortTestHelper::copyIntArray(arr,n);
    int *arr4= SortTestHelper::copyIntArray(arr,n);
//    SortTestHelper::testSort("Selection Sort",SelectionSort::selectionSort,arr,n);
    SortTestHelper::testSort("Insertion Sort",InsertionSort::insertionSort,arr2,n);
    SortTestHelper::testSort("Bubble Sort",BubbleSort::bubbleSort2,arr3,n);
    SortTestHelper::testSort("Bubble Sort",BubbleSort::bubbleSort3,arr4,n);

/*
    SortTestHelper::printArray(arr, n);
    selectionSort(arr,n);
    SortTestHelper::printArray(arr, n);
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(a, 10);
    SortTestHelper::printArray(a, 10);

    float b[4] = {4.4f, 3.3f, 2.2f, 1.1f};
    selectionSort(a, 4);
    for (int i = 0; i < 4; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
//    SortTestHelper::printArray(a,4);

    Student student[4] = {{"D", 90},
                          {"C", 100},
                          {"B", 95},
                          {"A", 95}};
    selectionSort(student, 4);
    for (int i = 0; i < 4; ++i) {
        cout << student[i];
    }
    cout << endl;
*/
    delete[] arr;
    delete[] arr2;
    return 0;
}
