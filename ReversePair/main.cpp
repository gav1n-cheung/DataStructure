#include <iostream>
#include "SortTestHelper.h"

template<typename T>
long long __merge(T arr, int l, int mid, int r) {
    int *aux = new int[r - l + 1];
    for (int i = l; i <= r; ++i) {
        aux[i - l] = arr[i];
    }
    long long res = 0;
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] <= aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
            res += (long long) (mid - i + 1);
        }
    }
    delete[] aux;
    return res;
}


template<typename T>
long long __inversionCount(T arr[], int l, int r) {
    if (l >= r) return 0;
    int mid = (r - l) / 2 + l;
    long long res1 = __inversionCount(arr, l, mid);
    long long res2 = __inversionCount(arr, mid + 1, r);
    return res1 + res2 + __merge(arr, l, mid, r);
}


template<typename T>
long long inversionCount(T arr[], int n) {
    return __inversionCount(arr, 0, n - 1);
}

int main() {
    int n = 1000000;
    std::cout << "Test Inversion Count for Ordered Array, n = " << n << " :" << std::endl;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n,0);
    cout << inversionCount(arr, n) << endl << endl;

    std::cout << "Test Inversion Count for Random Array, n = " << n << " :" << std::endl;
    arr= SortTestHelper::generateRandomArray(n,0,n);
    cout << inversionCount(arr, n) << endl << endl;

    std::cout << "Test Inversion Count for Inversed Array, n = " << n << " :" << std::endl;
    arr= SortTestHelper::generateInversedArray(n);
    cout<<inversionCount(arr,n)<<endl;
    delete[] arr;
    return 0;
}
