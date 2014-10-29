/********************************************************
* Md. Khairullah Gaurab                                 *
* Computer Science & Engineering                        *
* Shahjalal University of Science and Technology        *
* 20th Batch                                            *
* gaurab.cse.sust@gmail.com                             *
*********************************************************/
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
#include <iomanip>
#include <algorithm>

using namespace std;

const int INF = 2000000000;
const int MOD = 10007;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c) for(int i=a; i<=b; i+=c)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c) for(int i=b; i>=a; i-=c)
#define REPB(i,a) for(int i=a; ;i++)
#define REPRB(i,a) for(int i=a; ; i--)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define SZ(s) ((int)s.size())
#define PI 3.141592653589793
#define VS vector<string>
#define VI vector<int>
#define VD vector<DD>
#define VL vector<Long>
#define VVL vector<VL >
#define lim 257
#define tlim (1<<((int)ceil(log2(lim))+1))
#define unq(vec) stable_sort(vec.begin(),vec.end());\
vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a) a.begin(),a.end()
#define rev(a) reverse(BE(a));
#define sorta(a) stable_sort(BE(a))
#define sortc(a) sort(BE(a),comp)

int DP[lim][lim], ARR[lim], N, ANS;

int REC(int from, int to)
{
    if(from>to) return 0;
    int &ret = DP[from][to];
    if(~ret) return ret;
    ret = INF;
    REP(i,from,to)
    {
        ret = min(ret,REC(from,i-1)+REC(i+1,to)+(ARR[to]-ARR[from-1])-(ARR[i]-ARR[i-1]));
    }
    return ret;
}
int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    //double st=clock(),en;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w+",stdout);
    while (cin>>N)
    {
        mem(DP,-1);
        ARR[0] = 0;
        REP(i,1,N)
        {
            cin>>ARR[i];
            ARR[i] += ARR[i-1];
        }
        ANS = REC(1,N);
        cout<<ANS<<"\n";
    }
    //en=clock();
    //cerr<<(double)(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}

