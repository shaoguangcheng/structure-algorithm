/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include <vector>
#include <stack>
#include <iostream>

using namspace std;

// inorder traverse
void inorderTraverseRecursive(TreeNode* root)
{
	if(NULL == root)
		return;
	inorderTraverseRecursive(root->left);
	cout << root->val << endl;
	inorderTraverseRecursive(root->right);
}

void inorderTraverseNonrecursive(TreeNode* root)
{
	if(NULL == root)
		return;

	stack<TreeNode*> s;
	TreeNode* tmp = root;

	while(tmp != NULL || !s.empty()){
		while(tmp != NULL){
			s.push(tmp);
			tmp = tmp->left;
		}

		tmp = s.top();
		s.pop();
		cout << tmp->val << endl;
		tmp = tmp->right;
	}
}

// preorder traverse
void preorderTraverseRecursive(TreeNode* root)
{
	if(NULL == root)
		return;

	cout << root->val << endl;
	preorderTraverseRecursive(root->left);
	preorderTraverseRecursive(root->right);
}

void preorderTraverseNonrecursive(TreeNode* root)
{
	if(NULL == root)
		return;

	stack<TreeNode*> s;
	TreeNode* tmp = root;
	while(tmp != NULL || !s.empty()){
		while(tmp != NULL){
			s.push(tmp);
			cout << tmp->val << endl;
			tmp = tmp->left;
		}

		tmp = s.top();
		s.pop();
		tmp = tmp->right;
	} 
}

// postorder traverse
void postorderTraverseRecursive(TreeNode* root)
{
	if(NULL == root)
		return;

	postorderTraverseRecursive(root->left);
	postorderTraverseRecursive(root->right);
	cout << root->val << endl;
}

void postorderTraverseNonrecursive1(TreeNode* root)
{
	if(NULL == root)
		return;

	 stack<TreeNode*> s1, s2;
	 TreeNode* tmp = NULL;

	 s1.push(root);

	 while(!s1.empty()){
	 	tmp = s1.top();
	 	s1.pop();

	 	s2.push(tmp);

	 	if(tmp->left)
	 		s1.push(tmp->left);
	 	if(tmp->right)
	 		s1.push(tmp->right);
	 }

	 while(!s2.empty()){
	 	tmp = s2.top();
	 	s2.pop();
	 	cout << tmp->val << endl;
	 }
}

void postorderTraverseNonrecursive2(TreeNode* root)
{
	if(NULL == root)
		return NULL;

	stack<TreeNode*> s;
	TreeNode* curr = root;
	TreeNode* preVisited = NULL;

	while(curr != NULL || !s.empty()){
		while(curr != NULL){
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		if(curr->right == NULL || curr->right == previsited){
			cout << curr->val << endl;
			previsited = curr;
			curr = NULL;
		}
		else
			curr = curr->right;
	}
}