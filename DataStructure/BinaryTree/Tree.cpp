#include<iostream>
#include"Tree.h"

using namespace std;

Tree::Tree()
{
	m_pRoot = new Node;
}


Tree::~Tree()
{  
    m_pRoot->delNode();  
}  


Node* Tree::searchNode(int nodeIndex)
{  
    return m_pRoot->searchNode(nodeIndex);  
}


bool Tree::addNode(int nodeIndex,int direction,Node *pNode){  
    Node* temp = searchNode(nodeIndex);  
    if(temp == NULL)  
        return false;  
    Node* node = new Node();  
    node->index = pNode->index;  
    node->name = pNode->name;
    node->phone = pNode->phone;
    node->pParent = temp;  
    if(node == NULL)  
        return false;  
    if(direction == 0)  
        temp->pLChild = node;  
    if(direction == 1)  
        temp->pRChild = node;  
  
    return true;  
} 


bool Tree::delNode(int nodeIndex,Node *pNode){  
    Node* temp = searchNode(nodeIndex);  
    if(temp == NULL)  
        return false;  
    if(pNode != NULL)  
        pNode->name = temp->name;
        pNode->phone = temp->phone; 
    temp->delNode();  
    return true;  
}  


void Tree::Traverse()
{
	m_pRoot->Traverse();
}