#ifndef NODE_H 

#define NODE_H

#include <string>
 
class Node
{
	public:
		Node();
		Node *searchNode(int nodeIndex);
		void Traverse();
		void delNode();

		int index;
		string name;
		string phone;
		Node* pLChild;
		Node* pRChild;
		Node* pParent;
};

#endif