// constructBinarytree.cpp : 定义控制台应用程序的入口点。
// construct binary tree from preorder and inorder traverse

#include <iostream>

using namespace std;

struct binaryTreeNode
{
	int val;
	binaryTreeNode* left;
	binaryTreeNode* right;
};

binaryTreeNode* constructBinaryTreeCore(const char* preorderStart, const char* preorderEnd,
	const char* inorderStart, const char* inorderEnd)
{
	binaryTreeNode* root = new binaryTreeNode;
	root->val = preorderStart[0];
	root->left = NULL;
	root->right = NULL;

	if (preorderStart == preorderEnd){
		if (inorderStart == inorderEnd){
			return root;
		}
		else
			throw exception("invalid input");
	}

	const char* rootInorder = inorderStart;
	while ( rootInorder <= inorderEnd && *rootInorder != preorderStart[0]){
		++rootInorder;
	}

	int length = rootInorder - inorderStart;
	if (length > 0){
		root->left = constructBinaryTreeCore(preorderStart+1, preorderStart+length, 
			inorderStart, rootInorder-1);
	}
	if (length < preorderEnd - preorderStart){
		root->right = constructBinaryTreeCore(preorderStart+length+1, preorderEnd, 
			rootInorder+1, inorderEnd);
	}

	return root;
}

binaryTreeNode* constructBinaryTree(const char* preorder, const char* inorder, int N)
{
	if (preorder == NULL || inorder == NULL || N <= 0){
		return NULL;
	}

	return constructBinaryTreeCore(preorder, preorder+N-1, inorder, inorder+N-1);
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

