// String class nptel -C++ //
#include<stdio.h>
#include<iostream>
using namespace std;

string replace(string ch)
{
	string fixed;
	int length=ch.size();
	int x=0;
	while(x!=length)
	{
		string letter = ch.substr(x, 1);
		if(letter==" ")
		{
			letter="IIT";
		}
		 fixed = fixed + letter;
		x++;		
	}
	return fixed;
}
int main()
{
	int length,count=0,i=0;
	string ch;
	getline (cin, ch);
	if (std::isdigit(ch[i]))
	{
		
		 cout << "YES" << endl;
		 cout << ch << endl;
	}
	else
	{
	 cout << "NO" << endl;
    string result=replace(ch);
    cout << result << endl;
  }
    return 0;
}
