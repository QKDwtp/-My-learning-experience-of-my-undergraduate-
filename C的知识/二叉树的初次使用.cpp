#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char value) : val(value), left(nullptr), right(nullptr) {}
};

// 创建二叉树的递归函数
TreeNode* createTree(unordered_map<char, pair<char, char>>& treeMap, char root) {
	if (root == '*') {
		return nullptr;
	}
	TreeNode* node = new TreeNode(root);
	if (treeMap.find(root) != treeMap.end()) {
		node->left = createTree(treeMap, treeMap[root].first);
		node->right = createTree(treeMap, treeMap[root].second);
	}
	return node;
}

// 前序遍历二叉树的递归函数
void preorderTraversal(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->val;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// 释放二叉树内存的递归函数
void deleteTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	int n;
	cin >> n;
	unordered_map<char, pair<char, char>> treeMap;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		char node = s[0];
		char left = s[1];
		char right = s[2];
		treeMap[node] = make_pair(left, right);
	}
	char root = treeMap.begin()->first;
	TreeNode* rootPtr = createTree(treeMap, root);
	preorderTraversal(rootPtr);
	deleteTree(rootPtr);
	return 0;
}

