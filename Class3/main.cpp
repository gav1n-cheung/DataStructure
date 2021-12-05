#include "Heap.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "SortTestHelper.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

/* 堆和优先队列
 * 普通队列：先进先出;后进后出
 * 优先队列：出队顺序和入队顺序无关，和优先级有关，主要处理动态问题;复杂度n*logm
 * 对于总共N个请求
 * 使用普通数组或者顺序数组，最差情况:o(n^2)
 * 使用堆:O(nlgn)
 *
 * 二叉堆是一棵完全二叉树
 * 堆中某个节点的值总是不大与其父节点的值;堆总是一颗完全二叉树（最大值 ）（除了最后一层，其他的层必须都是最大值）
 * 二叉堆可以使用数组来实现：
 * （1）某个节点的左子节点索引是该节点索引的二倍
 * （1）某个节点的右子节点索引是该节点索引的二倍+1
 * （2）某个节点的父节点索引是该节点索引/2
 *
 * 对于一棵完全二叉树，第一个不是叶子节点的节点索引是二叉树size/2
 * 将n个元素逐个插入到一个空堆中，算法复杂度为O(nlogn)
 * heapify的过程，算法复杂度是O(n)
 *
 * 如果使用数组从索引0开始存储二叉堆
 * 则parent(i)=(i-1)/2
 * left child =i/2+1;
 * right child =i/2+2;
 * 最后一个非叶子节点的索引:
 * (count-1)/2
 */

/* 排序算法总结
 * 快速排序常数项较小，一般使用快速排序
 * 排序算法的稳定性stable 稳定排序:对于相等的元素，在排序后，原来靠前的元素依然靠前
 * 相等元素的相对位置没有发生改变
 * 如果在系统级别上实现稳定性的排序,一般采用归并排序
 *
 */

/*template<typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 < n) {
        int j = 2 * k + 1; //在此轮循环中，arr[k]和arr[j]交换位置
        if (j + 1 < n && arr[j + 1] > arr[j])
            j += 1;
        if (arr[k] >= arr[j]) {
            break;
        }
        swap(arr[j], arr[k]);
        k = j;
    }
}*/

//通过自定义函数来保证排序算法的稳定性
//bool operator<(const Student& otherStudent){
//    return score!= otherStudent.score: score>otherStudent.score ? name>otherStudent.name;
//}


template<class Item>
class IndexMaxHeap {
public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity + 1];//由于最大堆数组从1开始，因此需要容量+1来容纳所有元素
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; i++) {
            reverse[i] = 0;//由于索引是从1开始的,因此index[0]没有意义
        }
        count = 0;
        this->capacity = capacity;
    }

    IndexMaxHeap(Item arr[], int n) {
        data = new Item[n + 1];
        capacity = n;
        for (int i = 0; i < n; ++i)
            data[i + 1] < arr[i];
        count = n;
        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    int size() {
        return count;
    }

    bool is_empty() {
        return count == 0;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    //传入的i对用户而言,是从0索引的
    void insert(int i, Item item) {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);

        i += 1;
        data[i] = item;
        indexes[count++] = i;
        reverse[i] = count;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        int ret = data[indexes[1]];
        swap(indexes[1], indexes[count--]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count + 1]] = 0;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex() {
        assert(count > 0);
        Item ret = data[indexes[1]] - 1;
        swap(indexes[1], indexes[count--]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count + 1]] = 0;
        shiftDown(1);
        return ret;
    }

    bool contain(int i) {
        assert(i + 1 > 0 && i + 1 <= capacity);
        return reverse[i + 1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i + 1];
    }

    void change(int i, Item newItem) {
        //索引在[1,count]中,但是指向的元素是有可能不存在的,则需要做一个判断
        assert(contain(i));
        i++;
        data[i] = newItem;
        //找到indexes[j]=i,j表示data[i]在堆中的位置,之后在shiftUp[j]并且shiftDown[j]
        //使用暴力查找复杂度O(n)
        /* 为解决这个问题,使用反向查找,添加一个数组reverse[i] 表示索引i在indexes(堆)中的位置
         *
         * indexes[i]=j
         * reverse[j]=i
         *
         * indexes[reverse[i]] = i
         * reverse[indexes[i]] = i
         */
//        for (int j = 1; j <= count; ++j) {
//            if (indexes[j]==i) {
//                shiftUp(i);
//                shiftDown(i);
//                return;
//            }
//        }
        //使用反向查找之后,时间复杂度为O(nlogn)
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

private:
    Item *data;
    int *indexes;
    int *reverse;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k]] > data[indexes[k / 2]]) {
            swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k; //在此轮循环中，data[k]和data[j]交换位置
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                j += 1;
            if (data[indexes[k]] >= data[indexes[j]]) {
                break;
            }
            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }

    }

};


int main() {
    int n = 1000000;
/*    MaxHeap<int> maxheap = MaxHeap<int>(100);
//    std::cout << maxheap.size() << std::endl;
    srand(time(NULL));
    for (int i = 0; i < 50; ++i)
        maxheap.insert(rand() % 100);
    maxheap.testPrint();
    while (!maxheap.is_empty()) {
        cout << maxheap.extractMax() << " ";
    }
    cout << endl;*/
    cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int *arr6 = SortTestHelper::copyIntArray(arr1, n);
    int *arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", QuickSort::quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", QuickSort::quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", QuickSort::quickSort3, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort::heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", HeapSort::heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", HeapSort::heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout << endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", QuickSort::quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 Ways", QuickSort::quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", QuickSort::quickSort3, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort::heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", HeapSort::heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", HeapSort::heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;

    cout << endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);
    arr7 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr1, n);
    // 这种情况下, 普通的QuickSort退化为O(n^2)的算法, 不做测试
    //SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
//    SortTestHelper::testSort("Quick Sort 2 Ways", QuickSort::quickSort, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", QuickSort::quickSort3, arr4, n);
    SortTestHelper::testSort("Heap Sort 1", HeapSort::heapSort1, arr5, n);
    SortTestHelper::testSort("Heap Sort 2", HeapSort::heapSort2, arr6, n);
    SortTestHelper::testSort("Heap Sort 3", HeapSort::heapSort, arr7, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;


    return 0;
}
