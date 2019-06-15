#include<bits/stdc++.h>
using namespace std;
 

int countSteps(int x, int y)
{
    
    if (x%y == 0)
        return x/y;
 
    
    return x/y + countSteps(y, x%y);
}
 

int main()
{
   int x ,y;
   cin >> x;
   cin >> y;
   cout << countSteps(x, y);
   return 0;
}

