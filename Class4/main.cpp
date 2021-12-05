#include <iostream>
#include "BinarySearch.h"
#include <time.h>
#include <assert.h>
#include "FileOps.h"
#include "BST.h"
#include "SequenceST.h"
#include <vector>
int main() {
/*    int n = 1000000;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
        a[i] = i;

    clock_t start = clock();

    for (int i = 0; i < 2 * n; ++i) {
        int v = binarySearch(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v = -1);
    }
    clock_t end = clock();
    std::cout << "Binary Search (with out Recursion):" << double(end - start) / CLOCKS_PER_SEC << std::endl;

    start = clock();
    for (int i = 0; i < 2 * n; ++i) {
        int v = binarySearch3(a, 0, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v = -1);
    }
    end = clock();
    std::cout << "Binary Search (with Recursion):" << double(end - start) / CLOCKS_PER_SEC << std::endl;

    start = clock();
    for (int i = 0; i < 2 * n; ++i) {
        int v = binarySearch2(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v = -1);
    }
    end = clock();
    std::cout << "Binary Search (with Recursion):" << double(end - start) / CLOCKS_PER_SEC << std::endl;*/
    string filename = "bible.txt";
    vector<string> words;
    if (FileOps::readFile(filename, words)) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if (bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }

    return 0;
}
