#include <iostream>
using namespace std;

int chess[8];
int count=0;

bool check(int row, int colomn)//check if it is vaild
{
	for(int i=0;i<row;i++)
	{
		if(chess[i]==colomn
			||chess[i]+row-i==colomn
			||chess[i]-row+i==colomn)
			return false;
	}
	return true;
}

void chessprint(int row)//print chess
{
	if(row==8)
	{
		for(int i=0;i<8;i++)
		{
			cout<<chess[i];
		}
		cout<<endl;
		count++;
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			if(check(row,i))
			{
				chess[row]=i;
				chessprint(row+1);
			}
		}
	}
}

int main()
{
    chessprint(0);
    cout<<"Totol:"
        <<count<<endl;
}