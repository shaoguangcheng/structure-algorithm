#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

using namespace std;

template <class T>
struct node
{
	node<T>* leftChild;
	node<T>* rightChild;
	node<T>* parent;

	T val;

	node(const T& val) : leftChild(NULL), rightChild(NULL), parent(NULL), val(val){}
	node(const node<T>& node_) : leftChild(node_.leftChild), rightChild(node_.rightChild), parent(node_.parent), val(node_.val){}

	node<T>& operator = (const node<T>& node_){
		if(this != &node_){
			node<T>* leftChildPtr = leftChild;
			node<T>* rightChildPtr = rightChild;
			node<T>* parentPtr = parent;

			leftChild = new node<T> (*node_.leftChild);
			rightChild = new node<T> (*node_.rightChild);
			parent = new node<T> (*node_.parent);

			delete leftChildPtr;
			delete rightChildPtr;
			delete parentPtr;
		}

		return *this;
	}
};

template <class T>
class binaryTree
{
private:
	node<T>* root;

public:
	binaryTree() : root(NULL){}
	binaryTree(const binaryTree<T>& tree){
		/**
		*	here need to be completed
		*/
	}

	~binaryTree(){
		/**
		*	here need to be completed
		*/		
	}

	binaryTree<T>& operator= (const binaryTree<T>& tree){
		/**
		*	here need to be completed
		*/
		return *this;		
	}

	int size() const(){
		/**
		*	here need to be completed
		*/
		return int(0);		
	}

	int depth() const{
		/**
		*	here need to be completed
		*/
		return int(0);
	}


	void insert(const T& val){
		node<T> *tmp = new node<T> (val);
		if(root == NULL){
			root = new node<T>(*tmp);
			delete tmp;
			return;
		}

		node<T>* parent = NULL;
		node<T>* tmpRoot = root;
		while(tmpRoot !=NULL){
			parent = tmpRoot;
			if(tmpRoot->val >= val)
				tmpRoot = tmpRoot->leftChild;
			else
				tmpRoot = tmpRoot->rightChild;
		}

		tmp->parent = parent;
		if(parent->val >= val)
			parent->leftChild  = new node<T>(*tmp);
		else
			parent->rightChild = new node<T>(*tmp);

		parent = NULL;

		delete tmp;

		return;																										
	}

	void print() const{
		print(root);
	}

	void del(const T& val){
		node<T>* tmpRoot = root;
		while((tmpRoot->val != val)&&(tmpRoot != NULL)){
			if(tmpRoot->val >= val)
				tmpRoot = tmpRoot->leftChild;
			else
				tmpRoot = tmpRoot->rightChild;
		}

		if(tmpRoot == NULL){
			cout << "no such node" << endl;
			return;
		}

		node<T>* leftMaxVal = getMax(tmpRoot->leftChild);
		node<T>* rightMinVal = getMin(tmpRoot->rightChild);

		if(tmpRoot->leftChild == NULL && tmpRoot->rightChild == NULL){
			if(tmpRoot == root)
				delete tmpRoot;
			else{
				tmpRoot->parent->leftChild = NULL;
				tmpRoot->parent->rightChild =NULL;

				delete tmpRoot;
			}	

			return;
		}

		if(tmpRoot->leftChild != NULL && tmpRoot->rightChild == NULL){
			tmpRoot->val = leftMaxVal->val;

			if(leftMaxVal->parent == tmpRoot)
				tmpRoot->leftChild = NULL;
			else
				leftMaxVal->parent->rightChild = NULL;

			delete leftMaxVal;

			return;
		}

		if(tmpRoot->rightChild != NULL){
			tmpRoot->val = rightMinVal->val;

			if(rightMinVal->parent == tmpRoot)
				tmpRoot->rightChild = NULL;
			else
				rightMinVal->parent->leftChild = NULL;

			delete rightMinVal;

			return;
		}
	}

	T getMax() const{
		return getMax(root)->val;
	}

	T getMin() const{
		return getMin(root)->val;
	}

	node<T>* toDoubleList(){
		node<T>* head = NULL, *tail = NULL;
		toDoubleList(head, tail, root);

		return head;
	}

private:
	void print(node<T>* root) const{
		if(root == NULL)
			return;

		print(root->leftChild);
		cout << root->val << endl;
		print(root->rightChild);

		return;
	}

		node<T>* getMax(node<T>* root) const{
		node<T>* parent = NULL;
		if(root == NULL)
			return NULL;

		while(root != NULL){
			parent = root;
			root = root->rightChild;
		}

		return parent;
	}

	node<T>* getMin(node<T>* root) const{
		node<T>* parent = NULL;
		if(root == NULL)
			return NULL;

		while(root != NULL){
			parent = root;
			root = root->leftChild;
		}

		return parent;
	}

	void toDoubleList(node<T>* &head, node<T>* &tail, node<T>* root){
		if(root == NULL){
			head = NULL;
			tail = NULL;
			return;
		}

		node<T>* lt = NULL, *rt = NULL;
		toDoubleList(head, lt, root->leftChild);
		toDoubleList(rt, tail, root->rightChild);

		if(lt == NULL){
			head = root;
		}
		else{
			lt->rightChild = root;
			root->leftChild = lt;
		}

		if(rt == NULL){
			tail = root;
		}
		else{
			root->rightChild = rt;
			rt->leftChild = root;
		}

		return;
	}

};

#endif