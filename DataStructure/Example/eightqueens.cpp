#include<iostream>
#include<cmath>
bool check(int chess[]);
int main(){
	int i,j;
	int *p;
	int chess[8]={1,1,1,1,1,1,1,1};
	p=chess;
	while()
}

bool check(int chess[])
{
	int i,j;
	for(i=0;i<8;i++)
		for(j=8;j<0;j--)
			if(chess[i]%8==chess[j]%8)//check colomn
				return false;
			else if(chess[i]==chess[j])
			else if(chess[i]>chess[j])//check slant
			{
				if((chess[i]-abs(chess[i]%8-chess[j]%8)+abs(chess[i]-chess[j]))==chess[j]||(chess[i]-abs(chess[i]%8-chess[j]%8)-abs(chess[i]-chess[j]))==chess[j])
					return false;
			}
			else if(chess[i]<chess[j])
			{
				if((chess[i]+abs(chess[i]%8-chess[j]%8)+abs(chess[i]-chess[j]))==chess[j]||(chess[i]+abs(chess[i]%8-chess[j]%8)-abs(chess[i]-chess[j]))==chess[j])
					return false;
			}
	return true;
}
