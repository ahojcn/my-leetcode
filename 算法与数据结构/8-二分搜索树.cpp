// 二分搜索树
#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

template <typename Key, typename Value>
class BST
{
private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key k, Value v) {
			key = key;
			value = v;
			left = NULL;
			right = NULL;
		}
		Node(Node* node) {
			key = node->key;
			value = node->value;
			left = node->left;
			right = node->right;
		}
	};

	Node* root;
	int count;

public:
	BST() {
		root = NULL;
		count = 0;
	}
	~BST() {
		__destory(root);
	}

	int size() { return count; }
	bool isEmpty() { return count == 0; }

	void insert(Key key, Value value) {
		root = __insert(root, key, value);
	}

	// 二叉树中是否包含 k
	bool contain(Key k) {
		return __contain(root, k);
	}

	// 返回值值得考虑一下：返回 Node Key 还是 Value? Value*?
	Value* search(Key k) {
		return __search(root, k);
	}

	// 前序遍历 时间复杂度O(n)
	void preOrder() {
		__preOrder(root);
	}

	// 中序遍历 时间复杂度O(n)
	void inOrder() {
		__inOrder(root);
	}

	// 后序遍历 时间复杂度O(n)
	void postOrder() {
		__postOrder(root);
	}

	// 层序遍历 时间复杂度O(n)
	void levelOrder() {
		if (root == NULL) return;

		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			Node* node = q.front();
			q.pop();

			cout << node->key << endl;
			if (!node->left) {
				q.push(node->left);
			}
			if (!node->right) {
				q.push(node->right);
			}
		}
	}

	// 寻找最小值 O(logn)
	Key minimum() {
		assert( count != 0 );

		Node* min_node = __minimum(root);
		return min_node->key;
	}

	// 寻找最大值 O(logn)
	Key maximum() {
		assert( count != 0 );

		Node* max_node = __maximum(root);
		return max_node->key;
	}

	// 删除最小值 O(logn)
	void removeMin() {
		if (root != NULL) {
			root = __removeMin(root);
		}
	}

	// 删除最大值 O(logn)
	void removeMax() {
		if (root != NULL) {
			root = __removeMax(root);
		}
	}

	// 删除键为 key 的节点 O(logn)
	void remove(Key key) {
		root = __remove(root, key);
	}

private:
	Node* __insert(Node* root, Key key, Value value) {
		if (root == NULL) {
			count++;
			return new Node(key, value);
		}

		if (key == root->key) {
			node->value = value;
		} else if (key < root->key) {
			root->left = __insert(root->left, key, value);
		} else {
			root->right = __insert(root->right, key, value);
		}
	}

	bool __contain(Node* root, Key k) {
		if (root == NULL) return false;

		if (k == root->key) {
			return true;
		} else if (k < root->key) {
			return __contain(root->left, k);
		} else {
			return __contain(root->right, k);
		}
	}

	Value* __search(Node* root, Key key) {
		if (root == NULL) return NULL;

		if (key == root->key) {
			return &(root->value);
		} else if (key < root->key) {
			return __search(root->left, key);
		} else {
			return __search(root->right, key);
		}
	}

	void __preOrder(Node* root) {
		if (root != NULL) {
			cout << root->key << endl;
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void __inOrder(Node* root) {
		if (root != NULL) {
			preOrder(root->left);
			cout << root->key << endl;
			preOrder(root->right);
		}
	}

	void __postOrder(Node* root) {
		if (root != NULL) {
			preOrder(root->left);
			preOrder(root->right);
			cout << root->key << endl;
		}
	}

	void __destory(Node* root) {
		if (root != NULL) {
			__destory(root->left);
			__destory(root->right);

			delete root;
			count--;
		}
	}

	Node* __minimum(Node* node) {
		if (node->left == NULL) return node;

		return __minimum(node->left);
	}
	Node* __maximum(Node* node) {
		if (node->right == NULL) return node;

		return __minimum(node->right);
	}

	Node* __removeMin(Node* node) {
		if (node->left == NULL) {
			Node* right_node = node->right;
			delete node;
			count--;
			return right_node;
		}

		node->left = __removeMin(node->left);
		return node;
	}
	Node* __removeMax(Node* node) {
		if (node->right == NULL) {
			Node* left_node = node->left;
			delete node;
			count--;
			return left_node;
		}

		node->right = __removeMax(node->right);
		return node;
	}

	// hubbard deletion !!!
	Node* __remove(Node* node, Key key) {
		if (node == NULL) return NULL;

		if (key < node->key) {
			node->left = __remove(node->left, key);
			return node;
		} else if (key > node->key) {
			node->right = __remove(node->right, key);
			return node;
		} else {  // key == node->key
			if (node->left == NULL) {
				Node* right_node = node->right;
				delete node;
				count --;
				return right_node;
			}
			if (node->right == NULL) {
				Node* left_node = node->left;
				delete node;
				count --;
				return left_node;
			}

			// node->left != NULL && node->right != NULL
			Node* successor = new Node(minimum(node->right));
			count++;

			successor->right = removeMin(node->right);
			successor->left = node->left;
			delete node;
			count--;
			return successor;
		}
	}
};


// TEST
int main(int argc, char const *argv[])
{
	
	return 0;
}





