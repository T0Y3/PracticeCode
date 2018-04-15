#include<iostream>
#include"Tree.h"

using namespace std;

void addContact();
void deleteContact();
int  findContact();
void modifyContact();
void showContact();


int indexNode = 0;
int childside=0;
Tree *tree= new Tree();

int main()
{
	int choice;
	while(1)
	{
		cout<<"1.Add Contact"<<endl;
		cout<<"2.Delete Contact"<<endl;
		cout<<"3.Find Contact"<<endl;
		cout<<"4.Modify Contact"<<endl;
		cout<<"5.Show Contact"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Please enter a choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				addContact();break;
			case 2:
				deleteContact();break;
			case 3:
				findContact();break;
			case 4:
				modifyContact();break;
			case 5:
				showContact();break;
			case 6:
				delete tree;return 0;
			default:
				cout<<"Something Error!!!";
		}
	}
}

void addContact()
{
	string strname;
	string strphone;
	cout<<"Please enter a name"<<endl;
	cin>>strname;
	cout<<endl<<"Please enter a phone number"<<endl;
	cin>>strphone;
	Node *nodeadd = new Node();
	nodeadd->name = strname;
	nodeadd->phone = strphone;
	nodeadd->index = indexNode;
	tree->addNode(indexNode,childside,nodeadd);
	cout<<"Success!!"<<endl;

	if(childside==1)
		childside=0;
	else
		childside=1;
	indexNode++;
}


void deleteContact()
{
	cout<<"Please enter the number of Contact";
	int indexNode;
	Node *currNode = new Node;
	cin>>indexNode;
	tree->delNode(indexNode,currNode);
	cout<<"Delete the contact: "
	<<currNode->index
	<<" "
	<<currNode->name
	<<" "
	<<currNode->phone
	<<endl;
	delete currNode;
	cout<<"Success!!"<<endl;
}


int findContact()
{
	cout<<"Please the name"<<endl;
	string strfind;
	cin>>strfind;
	for(int i=0;i<indexNode;i++)
		if(tree->searchNode(i)->name==strfind)
			{
				cout<<"I find it :"
				<<tree->searchNode(i)->index
				<<" "
				<<tree->searchNode(i)->name
				<<" "
				<<tree->searchNode(i)->phone
				<<endl;
				return i;
			}

	return -1;
}


void modifyContact()
{
	cout<<"Enter the number of the contact"<<endl;
	int nodeNum;
	string nameMod;
	string phoneMod;
	cin>>nodeNum;
	Node* temp = new Node;
	temp = tree->searchNode(nodeNum);
	cout<<"Enter the new name"<<endl;
	temp->name = nameMod;
	cout<<"Enter the new phone"<<endl;
	temp->phone = phoneMod;
	cout<<"Success!!!"<<endl;
}

void showContact()
{
	tree->Traverse();
}
