#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Node.h"
//define SingleLinkedList class
class LinkedList
{
public:
	LinkedList();		//Constructor function
	~LinkedList();	//Destructor function
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetNode(int i, Node *pNode);
	int LocateNode(Node *pNode);
	bool PriorNode(Node *pCurrentNode, Node *pPreNode);
	bool NextNode(Node *pCurrentNode, Node *pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node *pNode);
	bool ListDelete(int i, Node *pNode);
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);
private:
	int *m_pList;	//store list address
	int m_iLength;	//list length
};

#endif