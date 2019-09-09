#include <iostream>
#include <algorithm>

using namespace std;



long factorial(int x)
{
    int res=1;

    for(int i=1; i<=x; i++)
        res*= i;

    return res;
}

int main()
{
    long a,b;
    cin>>a >> b;

    cout << factorial( min(a,b) );
}