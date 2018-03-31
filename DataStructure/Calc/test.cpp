#include<iostream>
#include<string>

using namespace std;
void test(string str);

int main()
{
	string s;
	cin >> s;
	test(s);
}

void test(string str)
{
	cout<<str.at(0);
}