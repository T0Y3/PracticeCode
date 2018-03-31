#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack <double>stknum;
stack <char>stkopt;
string experssion;
char Prior[7][7] =
{ //Operator priority  
          // '+' '-'   '*'  '/'  '('  ')'  '#'    
    /*'+'*/{ '>', '>', '<', '<', '<', '>', '>' },
    /*'-'*/{ '>', '>', '<', '<', '<', '>', '>' },
    /*'*'*/{ '>', '>', '>', '>', '<', '>', '>' },
    /*'/'*/{ '>', '>', '>', '>', '<', '>', '>' },
    /*'('*/{ '<', '<', '<', '<', '<', '=', '<' },
    /*')'*/{ '>', '>', '>', '>', ' ', '>', '>' },
    /*'#'*/{ '<', '<', '<', '<', '<', '>', '=' },
};

int EvaluateExpression(string str);
void InitStack();
bool In(char ch);
double Operate(int a, char opt, int b);
char Precede(char op1, char op2);
int Optid(char op1);


int main()
{   
    int flag;
    while(1)
    {   
        
        cout << "Please enter a experssion.Example:#8+(8-2)*6#"<< endl;
        cin >> experssion;
        cout << EvaluateExpression(experssion) << endl;
        cout << "Press 1 to continue.Press 0 to exit.";
        cin >> flag;
        if(flag==0)
            break;
    }
    return 0;    
}


int EvaluateExpression(string str)
{   
    InitStack();
    char oprt;
    double a;
    double b;
    int i=1;
    stkopt.push('#');
    while(str.at(i)!='#'||stkopt.top()!='#')
    {
        if(!In(str.at(i)))
        {
            stknum.push(str.at(i)-'0');
            i++;   
        }
        else
            switch(Precede(stkopt.top(),str.at(i)))
            {
                case '<':
                    stkopt.push(str.at(i));
                    i++;
                    break;
                case '>':
                    oprt = stkopt.top();
                    stkopt.pop();
                    a = stknum.top();
                    stknum.pop();
                    b = stknum.top();
                    stknum.pop();
                    stknum.push(Operate(a, oprt, b));
                    break;
                case '=':
                    stkopt.pop();
                    i++;
                    break;
            }
    }
    return stknum.top();
}


void InitStack()
{
    while(!stkopt.empty())
    {
        stkopt.pop();
    }
    while(!stknum.empty())
    {
        stknum.pop();
    }
}


bool In(char ch)
{
    string opt = "+-*/()#";
    if(opt.find(ch)!=string::npos)
        return true;
    return false;
}

double Operate(int a, char opt, int b)
{
    switch(opt)
    {
        case '+':
            return a+b;break;
        case '-':
            return b-a;break;
        case '*':
            return a*b;break;
        case '/':
            return b/a;break;
    }
}


int Optid(char op1)
{
    switch (op1)
    {
        case'+':
            return 0;
        case'-':
            return 1;
        case'*':
            return 2;
        case'/':
            return 3;
        case'(':
            return 4;
        case')':
            return 5;
        case'#':
            return 6;
        default:
            return -123456;
    }
}


char Precede(char op1, char op2)
{
    int a, b;
    a = Optid(op1); b = Optid(op2);
    return(Prior[a][b]);
}