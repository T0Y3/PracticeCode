#ifndef LINEARLIST_H
#define LINEARLIST_H

typedef int Elem;

//define linearlist class
class LinearList
{
public:
	LinearList(int size);		//Constructor function
	~LinearList();	//Destructor function
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Elem *e);
	int LocateElem(Elem *e);
	bool PriorElem(Elem *currentElem, Elem *preElem);
	bool NextElem(Elem *currentElem, Elem *nextElem);
	void ListTraverse();
	bool ListInsert(int i, Elem *e);
	bool ListDelete(int i, Elem *e);
private:
	int *m_pList;	//store list address
	int m_iSize;	//list size
	int m_iLength;	//list length
};

#endif