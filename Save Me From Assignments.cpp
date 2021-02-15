#include<bits/stdc++.h>
using namespace std;
#define ld long double
 
const ld a = 0.0000001;
ld aray[10000];
int n, k;
 
bool poss(double val)
{
    int c = 0;
    for(auto x : aray)
    {
        c += floor(x/val);
        if(c >= k)
            return true;
    }
    if(c >= k)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>aray[i];
    ld left = 0, right = 1e9, mid;
    while(left+a < right)
    {
        mid = (left+right)/2;
        if(poss(mid))
            left = mid;
        else 
            right = mid;
    }
    cout<<fixed<<setprecision(6)<<left<<"\n";
    return 0;
}