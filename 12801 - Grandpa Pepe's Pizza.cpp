// Md. Khairullah Gaurab
// CSE, SUST 20th Batch
// gaurab.cse.sust@gmail.com

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 2000000000;
const int MOD = 10007;

typedef long long Long;
typedef double DD;

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define SZ(s) ((int)s.size())
#define PI 3.141592653589793
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<DD>
#define VLL         vector<Long>
#define lim 100005
#define unq(vec) stable_sort(vec.begin(),vec.end());\
vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    stable_sort(BE(a))
#define sortc(a)    sort(BE(a),comp)


int olive[2*lim], N, C;
bool done[lim];

int main(int argc, const char **argv)
{
    int tmp;
    while(sf("%d %d",&N, &C)==2)
    {
        mem(olive,0);
        mem(done,false);
        REP(i,1,C)
        {
            sf("%d",&tmp);
            olive[tmp+1] = 1;
        }
        REP(i,1,N)
        {
            olive[i+N] = olive[i];
        }
        REP(i,1,2*N)
        {
            olive[i] += olive[i-1];
        }
        tmp = (N/C);
        bool Y = false, flag;
        REP(i,1,2*N)
        {
            if(done[i]) continue;
            flag = true;
            int cnt = 0;
            for(int j=i; j<=(2*N)-tmp; j+=(tmp))
            {
                if(olive[j+(tmp)]-olive[j]!=1)
                {
                    flag = false;
                }
                done[j] = true;
                cnt++;
                if(j+(tmp)==i+N) break;
            }
            if(flag and cnt==C)
            {
                Y = true;
                break;
            }
        }
        if(Y) pf("S\n");
        else pf("N\n");
    }
    return 0;
}
