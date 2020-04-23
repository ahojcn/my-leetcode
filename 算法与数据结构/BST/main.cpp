#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

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
            this->left = this->right = nullptr;
        }

        Node(Node* node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int count;

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() {
        __destroy(root);
    }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

    void insert(Key key, Value value) {
        root = __insert(root, key, value);
    }

    bool contain(Key key) {
        return __contain(root, key);
    }

    // 返回值应该是什么？
    //  Key?
    //  Value? 缺点：查找不到的话，返回怎么做？抛出异常？
    //  Node*? 如果是这样 Node 就不应该是 private 的，这样对于数据的封装不太好。
    //  Value* 查找失败返回 null
    Value* search(Key key) {
        return __search(root, key);
    }

    // 前序遍历
    void preOrder() {
        __preOrder(root);
    }
    // 中序遍历
    void inOrder() {
        __inOrder(root);
    }
    // 后序遍历
    void postOrder() {
        __postOrder(root);
    }

    // 层序遍历
    void levelOrder() {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->key << endl;
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    Key minimum() {
        assert(count != 0);

        Node* min_node = __minimum(root);
        return min_node->key;
    }

    Key maximum() {
        assert(count != 0);

        Node* max_node = __maximum(root);
        return max_node->key;
    }

    void removeMin() {
        if (root == nullptr) return;

        root = __removeMin(root);
    }

    void removeMax() {
        if (root == nullptr) return;

        root = __removeMax(root);
    }

    void remove(Key key) {
        __remove(root, key);
    }

private:
    Node* __remove(Node *node, Key key) {
        if (node == nullptr) return nullptr;

        if (key < node->key) {
            node->left = __remove(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = __remove(node->right, key);
            return node;
        } else {
            if (node->left == nullptr) {
                Node* right_node = node->right;
                delete node;
                count--;
                return right_node;
            }
            if (node->right == nullptr) {
                Node* left_node = node->left;
                delete node;
                count--;
                return left_node;
            }

            Node *successor = new Node(minimum(node->right));
            count++;

            successor->right = __removeMin(node->right);
            successor->left = node->left;

            delete node;
            count--;

            return successor;
        }
    }

    Node* __removeMin(Node* node) {
        if (node->left == nullptr) {
            Node* right_node = node->right;
            delete node;
            count--;
            return right_node;
        }

        node->left = __removeMin(node->left);
        return node;
    }

    Node* __removeMax(Node *node) {
        if (node->right == nullptr) {
            Node* left_node = node->left;
            delete node;
            count --;
            return left_node;
        }

        node->right = __removeMin(node->right);
        return node;
    }

    Node* __minimum(Node* node) {
        if (node->left == nullptr)
            return node;

        return __minimum(node->left);
    }

    Node* __maximum(Node* node) {
        if (node->right == nullptr)
            return node;

        return __minimum(node->right);
    }

    void __preOrder(Node *node) {
        if (node == nullptr) return;

        cout << node->key << endl;
        __preOrder(node->left);
        __preOrder(node->right);
    }

    void __inOrder(Node *node) {
        if (node == nullptr) return;

        __preOrder(node->left);
        cout << node->key << endl;
        __preOrder(node->right);
    }

    void __postOrder(Node *node) {
        if (node == nullptr) return;

        __preOrder(node->left);
        __preOrder(node->right);
        cout << node->key << endl;
    }

    // 销毁二叉树
    void __destroy(Node* node) {
        if (node == nullptr) return;

        __destroy(node->left);
        __destroy(node->right);
        delete node;
        count--;
    }

    // 向以 node 为根的二叉搜索树中插入 key 和 value
    // 返回插入新节点后的二叉搜索树的根
    Node* __insert(Node* node, Key key, Value value) {

        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = __insert(node->left, key, value);
        else
            node->right = __insert(node->right, key, value);

        return node;
    }

    // 查看以 node 为根的二叉搜索树中是否包含键值为 key 的节点
    bool __contain(Node *node, Key key) {

        if (node == nullptr) return false;

        if (node->key == key)
            return true;
        else if (key < node->key)
            return __contain(node->left, key);
        else
            return __contain(node->right, key);
    }

    // 查找以 node 为根的二叉搜索树中是否包含 key 节点，返回指向对于 value 的指针
    Value* __search(Node* node, Key key) {

        if (node == nullptr) return nullptr;

        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return __search(node->left, key);
        else
            return __search(node->right, key);
    }
};

int main() {
    return 0;
}