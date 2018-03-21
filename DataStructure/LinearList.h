#ifndef LIST_H
#define LIST_H

typedef int Elem;

//define linearlist class
class List
{
public:
	List(int size);		//Constructor function
	~List();	//Destructor function
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Elem *e);
	int LocateElem(Elem *e);
	bool PriorElem(Elem *currentElem, Elem *preElem);
	bool NextElem(Elem *currentElem, Elem *nextElem);
	void ListTraverse();
private:
	int *m_pList;	//store list address
	int m_iSize;	//list size
	int m_iLength;	//list length
};

#endif