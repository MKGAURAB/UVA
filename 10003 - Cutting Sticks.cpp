#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long int LLI;
const int MAX = 53;
const int INF = (1<<28);


LLI DP[MAX][MAX];
int cutpoint[MAX], len, cuts;

LLI rec(int left, int right)
{
    if(right-left==1) return 0LL;
    LLI &ret = DP[left][right];
    if(ret!=-1LL) return ret;
    ret = INF;
    for(int i=left+1; i<right; i++) ret = min(ret,rec(left,i)+rec(i,right)+(cutpoint[right]-cutpoint[left]));
    return ret;
}

int main(int argc, const char *argv[])
{
    int i;
    while(cin>>len and len)
    {
        cin>>cuts;
        for(i=1; i<=cuts; i++)
        {
            cin>>cutpoint[i];
        }
        cutpoint[i] = len;
        memset(DP,-1LL,sizeof(DP));
        LLI res = rec(0,cuts+1);
        cout<<"The minimum cutting is "<<res<<"."<<endl;
    }
    return 0;
}
