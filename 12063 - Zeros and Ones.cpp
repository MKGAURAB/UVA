#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;
int N, MOD;
vector<vector<vector<ll> > > vs (33,vector<vector<ll> >(33,vector<ll>(101,0)));
ll rec(int ones, int zeros, int mod)
{
    if(ones>N or zeros>N) return 0LL;
    if(ones==N and zeros==N) return !mod;
    ll &ret = vs[ones][zeros][mod];
    if(ret!=-1LL) return ret;
    ret = rec(ones+1,zeros,(2*mod+1)%MOD) + rec(ones,zeros+1,(2*mod)%MOD);
    return ret;
}
int main(int argc, const char *argv[])
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        cin>>N>>MOD;
        cout<<"Case "<<i<<": ";
        if((N%2)==1 or MOD==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            N/=2;
            vs.assign(N+1,vector<vector<ll> >(N+1,vector <ll>(MOD,-1LL)));
            ll res = rec(1,0,1%MOD);
            cout<<res<<endl;
        }
    }
    return 0;
}
