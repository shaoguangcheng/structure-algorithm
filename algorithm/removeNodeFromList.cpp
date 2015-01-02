#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};

void removeNodeFromList(Node** head, Node* deletedNode)
{
	if(head == NULL || deletedNode == NULL)
		return;

	if(deletedNode->next != NULL){
		Node* pNext = deletedNode->next;
		deletedNode->val = pNext->val;
		deletedNode->next = pNext->next;

		delete pNext;

		pNext = NULL;
	}
	else if(*head == deletedNode){
		delete deletedNode;

		*head = NULL;
		deletedNode = NULL;
	}
	else{
		Node* pNext = *head;

		while(pNext->next != deletedNode)
			pNext = pNext->next;

		pNext->next = NULL;
		delete deletedNode;
		deletedNode = NULL;
	}
}