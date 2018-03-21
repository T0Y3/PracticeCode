#include "LinearList.h"
#include <iostream>
using namespace std;

//Constructor
LinearList::List(int size)
{
	m_iSize = size;
	m_pList = new int[m_iSize]; //apply for a section of address space
	m_ilength = 0;				
}

//Destrcutor
LinearList::~list() 
{
	delete []m_pList;
	m_pList = NULL;
}

//The essence is the ilength equals to zero
void LinearList::ClearList()
{
	m_ilength=0;
}

//check if the ilength=0
bool LinearList::ListEmpty()
{
	if(m_ilength==0)
		return true;
	else
		return false;
	//return m_ilength==0?true:false;
}

//return the real length
int LinearList::ListLength()
{
	return m_ilength;
}

//Get the specify element.
//iSize is applyed elems(a little much)
//iLength is real elems
bool LinearList::GetElem(int i, Elem *e)
{
	if(i<0||i>m_iSize)	//iSize or iLength? Maybe both is ok.XD
	{
		return false;
	}
	else
	{
		*e = m_pList[i];
		return true;
	}
}

//m_pList[i]==*e
//"return" execute when the first "return" 
//Locate the first Elem in this LinearList
int LinearList::LocateElem(Elem *e)
{
	for(int i=0;i<m_ilength;i++)
	{
		if(m_pList[i]==*e)
			return i;
	}
	return -1;
}

//get the one before the specify elem
bool LinearList::PriorElem(Elem *currentElem, Elem *preElem)
{
	int temp = LocateElem(currentElem);
	if(temp==-1)
	{
		return false;
	}
	else if(temp==0)	//checkif it is the first elem
	{
		return false;
	}
	//if(temp==-1||temp==0){return false;}
	else
	{
		*preElem = m_pList[temp-1];
		return true;
	}
}

//get the one after the specify elem
bool LinearList::NextElem(Elem *currentElem, Elem *nextElem)
{
	int temp = LocateElem(currentElem);
	if(temp==-1)
	{
		return false;
	}
	else if(temp==m_ilength-1)
	{
		return false;
	}
	//if(temp==-1||temp==m_ilength-1){return false;}
	else
	{
		*nextElem = m_pList[temp+1];
		return true;
	}
}

//traverse the linearlist
void LinearList::ListTraverse()
{
	for(int i=0;i<m_ilength;i++)
	{
		cout<<m_pList[i]<<endl;
	}
}