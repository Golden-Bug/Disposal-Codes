//correct program of coin changing of nptel //
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int amt=0,th=0,fh=0,h=0,f=0,tw=0,t=0,fv=0,to=0,o=0;
	
	cin >> amt;
	while (amt>=1000)
	{
	th=amt/1000;
	amt=amt%1000;

	}
	while (amt>=500)
   {
		fh=amt/500;
	amt=amt%500;

	}
	while (amt>=100)
   {
	h=amt/100;
	amt=amt%100;
}
    	while (amt>=50)
   {
	f=amt/50;
	amt=amt%50;

}
    	while (amt>=20)
   {
	tw=amt/20;
	amt=amt%20;

}
	while (amt>=10)
   {
	t=amt/10;
	amt=amt%10;
}
    	while (amt>=5)
   {
	fv=amt/5;
	amt=amt%5;

}
while (amt>=2)
   {
	to=amt/2;
	amt=amt%2;

}
while (amt>=1)
   {
	o=amt/1;
	amt=amt%1;
}
	
	if(th!=0)
{
	for(int i=1;i<=th;++i)
	cout << 1000 << " ";
}
		if(fh!=0)
 {
	for(int i=1;i<=fh;++i)
	if(fh!=0)
	cout << 500 << " ";
}
	if(h!=0)
	{
	for(int i=1;i<=h;++i)
	cout << 100 << " ";
}
	
	
	if(f!=0)
		{
	for(int i=1;i<=f;++i)
	cout << 50 << " ";
}
	
	if(tw!=0)
		{
	for(int i=1;i<=tw;++i)
	cout << 20 << " ";
}
	
		if(t!=0)
			{
	for(int i=1;i<=t;++i)
	cout << 10 << " ";
}
	
	if(fv!=0)
			{
	for(int i=1;i<=fv;++i)
	cout << 5 << " ";
}
	
		if(to!=0)
				{
	for(int i=1;i<=to;++i)
	cout << 2 << " ";
}
	
	if(o!=0)
			{
	for(int i=1;i<=o;++i)
	cout << 1 << " ";
}
	
}
