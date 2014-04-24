/********************************************************
*      Md. Khairullah Gaurab                            *
*      Computer Science & Engineering                   *
*      Shahjalal University of Science and Technology   *
*      20th Batch                                       *
*      gaurab.cse.sust@gmail.com                        *
*********************************************************/
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>
#include <cstdio>

#define sf scanf
#define pf printf

using namespace std;
const int SZ = 102000;

char S[SZ], P[1005];
int failure[1005], Q;

void preKMP()
{
    int i, K, len;
    len = strlen(P);
    failure[0] = K = -1;
    for(i=1; i<len; i++)
    {
        while(K>=0 and P[K+1]!=P[i]) K = failure[K+1];
        if(P[K+1]==P[i]) K += 1;
        failure[i] = K;
    }
}
bool KMP()
{
    int i, j, lens, lenp;
    lens = strlen(S);
    lenp = strlen(P);
    i = j = 0;
    preKMP();
    while(i<lens and j<lenp)
    {
        if(S[i]==P[j])
        {
            i++;
            j++;
        }
        else if(j==0) i++;
        else j = failure[j-1] + 1;
    }
    if(j==lenp) return true;
    return false;
}
int main(int argc, const char *argv[])
{
    int test;
    sf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        sf("%s",S);
        sf("%d",&Q);
        for(int j=1; j<=Q; j++)
        {
            sf("%s",P);
            if(KMP()) pf("y\n");
            else pf("n\n");
        }
    }
    return 0;
}


