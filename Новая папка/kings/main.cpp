#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin>>n>>x>>y;
    //int b = (n - max(x,y)) + (max(x,y)-min(x,y));
    //int w = (min(x,y) - 1) + (max(x,y)-min(x,y));
    if (x+y<n+1) {
    cout<< "White";}
    else {
    cout<< "Black";}
    return 0;
}
