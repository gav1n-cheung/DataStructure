//
// Created by cheung on 12/4/21.
//

#ifndef CLASS4_BINARYSEARCH_H
#define CLASS4_BINARYSEARCH_H

#include <iostream>
/*二分查找
 * 对于有序数列，才能使用二分查找法
 * O(logn)
 */

//如果在数组中找到target，则返回向应的索引index
template<typename T>
int binarySearch(T arr[], int n, T target) {
    //在arr[l...r]之中查找target
    int l = 0, r = n - 1;
    while (l <= r) {
//        int mid=(l+r)/2;  //这种获取mid的方法有可能会导致溢出
        int mid = l + (r - l) / 2;  //使用这种方式不会产生溢出
        if (arr[mid] == target)
            return mid;
        //在arr[l...mid-1]之中查找target
        if (target < arr[mid])
            r = mid - 1;//由于这里我们定义的是闭区间，则需要将mid-1作为闭区间的右边界，mid不在搜索范围内，但mid-1在
        else //target >arr[mid+1] 在arr[mid+1...r]之中查找target
            l = mid + 1;
    }
    return -1;
}

//右侧开区间的实现
template<typename T>
int binarySearch2(T arr[], int n, int target) {
    //在[l....r)之间查找target
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
            //在[l,mid)中查找target
        else if (arr[mid] > target)
            r = mid;
            //在[mid+1,r)中查找target
        else
            l = mid + 1;
    }
}

//递归实现,相对于迭代性能较差
template<typename T>
int binarySearch3(T arr[], int l, int r, int target) {
    if(l>r)     return -1;
    int mid = l + (r - l) / 2;
    if (target == arr[mid])
        return mid;
    else if (target < arr[mid])
        binarySearch3(arr, l, mid - 1, target);
    else
        binarySearch3(arr, mid + 1, r, target);
}


#endif //CLASS4_BINARYSEARCH_H
