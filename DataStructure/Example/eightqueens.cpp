#include <iostream>
using namespace std;

void chessrow(int row);
int chesscolomn(int row, int colomn);

int chess[8]={0};
int count=0;

void chessrow(int row)
{
    while(chess[row]=chesscolomn(row,0))
    {
        if(row<8)
            return chessrow(row+1);
        else
            row=-1;
            count++;
            cout<<"=========="<<endl;
    }   
}

int chesscolomn(int row, int colomn)
{
    if(colomn<8)
    {
        chess[row]=colomn;
        for(int i=0;i<row;i++)
        {
            if(chess[i]==chess[row])//check colomn
                {
                    cout<<"* ";
                    return chesscolomn(row,colomn+1);
                }
            if((chess[i]+row-i==chess[row])||(chess[i]-row+i==chess[row]))//check slant
                {
                    cout<<"* ";
                    return chesscolomn(row,colomn+1);
                }
            cout<<"# ";
            return colomn;
        }
    }
    else
        colomn=-1;
        cout<<endl;
    return chesscolomn(row,colomn+1);
}

int main()
{
    chessrow(0);
    cout<<"Totol:"
        <<count<<endl;
}