#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

//comstructor function
LinkedList::LinkedList()
{
	m_pList = new Node;
	m_pList->data=0;
	m_pList->next=NULL;
	m_iLength=0;
}

//destructor function
LinkedList::~LinkedList()
{
	ClearList();
	delete m_pList;
	m_pList=NULL;
}


bool LinkedList::ListEmpty()
{
	if(m_iLength==0)
		return true;
	return false;
}

//
int LinkedList::ListLength()
{
	return m_iLength;
}

//
void LinkedList::ClearList()
{
	Node *currentNode = m_pList->next;
	while(currentNode!=NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next=NULL;
	m_iLength=0;
}

//0 new 1 2 3
bool LinkedList::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;
	if(newNode==NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

//0 1 2 3 new
bool LinkedList::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while(currentNode!=NULL)
	{
		currentNode = currentNode->next;
	}
	Node *newNode = new Node;
	if(newNode==NULL)
		return false;
	newNode->data = pNode->data;
	currentNode->next = newNode;
	newNode->newNode = NULL;
	m_iLength++;
	return true;
}

//0 1 2 new 3 4
bool LinkedList::ListInsert(int i, Node *pNode)
{
	if(i<0||i>m_iLength)
		return false;
	else if(i=m_iLength)
	{
		ListInsertTail(pNode);
		return true;
	}
	else if(i=1)
	{
		ListInsertHead(pNode);
		return true;
	}
	else
	{
		Node *newNode = new Node;
		newNode->data = pNode->data;
		Node *currentNode = m_pList->next;
		for(int k=0;k<i;k++)
		{
			currentNode = currentNode->next;
		}
		newNode->next = currentNode->next;
		currentNode = newNode;
		m_iLength++;
	}
}

//0 1 2 3 4 5
bool LinkedList::ListDelete(int i, Node *pNode)
{
	if(i<0||i>m_iLength)
		return false;
	Node *currentNode = m_pList;
	for(int k=0;k<i;k++)
	{
		currentNode = currentNode->next;
	}
	Node *temp = currentNode->next;
	currentNode = currentNode->next;
	temp->next = currentNode->next;
	m_iLength--;
	return true;
}


bool LinkedList::GetNode(int i, Node *pNode)
{
	if(i<0||i>m_iLength)
		return false;
	Node *currentNode = m_pList->next;
	for(int k=0;k<i;k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}


int LinkedList::LocateNode(Node *pNode)
{
	int count = 1;
	Node *currentNode = m_pList;
	while(currentNode->next!=NULL)
	{
		if(currentNode->data==pNode->data)
		{
			return count;
		}
		count++;
		currentNode = currentNode->next;
	}
	return -1;
}


void LinkedList::ListTraverse()
{
	Node *currentNode = m_pList;
	while(currentNode->!=NULL)
	{
		currentNode = currentNode->next;
		cout<<currentNode->data<<endl;
	}
}