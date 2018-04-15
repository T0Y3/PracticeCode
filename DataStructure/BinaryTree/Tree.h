#ifndef TREE_H
#define TREE_H 
#include"Node.h"
class Tree
{
public:
	Tree();
	~Tree();
	bool addNode(int nodeIndex,int direction,Node *pNode); 	
	bool delNode(int nodeIndex,Node *pNode);  
	void Traverse();
	Node* searchNode(int nodeIndex);
private:
    Node *m_pRoot;  
};

#endif