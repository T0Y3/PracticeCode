#include <iostream>
#include "Node.h"
using namespace std;

Node::Node()
{
	index = 0;
	name = "";
	phone = "";
	pLChild = NULL;
    pRChild = NULL;
}
Node* Node::searchNode(int nodeIndex){  
    if(this->index == nodeIndex)  
        return this;  
    Node *temp = NULL;  
    if(this->pLChild != NULL){  
        if(this->pLChild->index == nodeIndex)  
            return this->pLChild;  
        else{  
           temp = this->pLChild->searchNode(nodeIndex);  
           if(temp != NULL){ 
                return temp;  
           }  
  
        }  
    }  
    if(this->pRChild != NULL){  
        if(this->pRChild->index == nodeIndex)  
            return this->pRChild;  
        else{  
            temp = this->pRChild->searchNode(nodeIndex);  
            return temp;  
        }  
    }  
    return NULL;  
} 


void Node::delNode(){  
    if(this->pLChild != NULL)  
        this->pLChild->delNode();  
    if(this->pRChild != NULL)  
        this->pRChild->delNode();  
    if(this->pParent != NULL){  
        if(this->pParent->pLChild == this)  
            this->pParent->pLChild = NULL;  
        if(this->pParent->pRChild == this)  
            this->pParent->pRChild = NULL;  
    }  
    delete this;  
}  


void Node::Traverse()
{
	cout<<this->index<<" "<<this->name<<" "<<this->phone<<endl;
  
    if(this->pLChild != NULL)  
        this->pLChild->Traverse();  
  
    if(this->pRChild != NULL)  
        this->pRChild->Traverse();  
}