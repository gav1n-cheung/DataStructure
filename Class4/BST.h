//
// Created by cheung on 12/4/21.
//

#ifndef CLASS4_BST_H
#define CLASS4_BST_H
/*二分搜索树常用于查找表的实现(或称为字典数据结构)
 *提供了一种高效的动态维护数据方法
 * 二分搜索树是一棵二叉树，并且有以下性质：
 * 每个节点的键值大于左孩子
 * 每个节点的键值小于右孩子
 * 以以左右孩子为根的子树仍为二分搜索树
 * 不一定是完全二叉树
 */
#include <iostream>


template<typename Key, typename Value>
class BST {

private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count;


public:

    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() {
        //TODO:~BST()
    }

    int size() {
        return count;
    }

    bool is_empty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    void insert2(Key key, Value value) {
        insert2(root, key, value);
    }

    //查找value值,如果存在,则返回value的指针，否则返回空指针
    Value *search(Key key) {
        return search(root, key);
    }

    //查找key值是否存在
    bool contain(Key key) {
        return contain(root, key);
    }

private:
    //向以node为根的二叉搜索树中，插入节点(key,value)
    //返回插入新节点后的二叉搜索树的根
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
            if (node->key < key) node->right=insert(node->right, key, value);
            else if (node->key > key) node->left=insert(node->left, key, value);
            else node->value = value;
        return node;
        if(key==node->key) node->value=value;
        else if(key>node->key) node->right= insert(node->right,key,value);
        else node->left= insert(node->left,key,value);
        return node;


    }

    //非递归实现
    Node *insert2(Node *node, Key key, Value value) {
        while (node != NULL) {
            if (key > node->key) node = node->right;
            else if (key < node->key) node = node->left;
            else node->value = value;
            return node;
        }
        count++;
        return new Node(key, value);
    }

    Value *search(Node *node, Key key) {
        if (node == NULL)
            return NULL;
        if (key == node->key) return &(node->value);
        else if (key < node->key) return search(node->left, key);
        else return search(node->right, key);
    }

    //查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node *node, Key key) {
        if (node == NULL)
            return false;
        if (key == node->key) return true;
        else if (key < node->key) return contain(node->left, key);
        else
            return contain(node->right, key);
    }
};


#endif //CLASS4_BST_H
