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
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <utility>

using namespace std;
string pat, mpat;
int plen, mplen;

void computeLPSArray(int *LPS) {
    int i, len;
    LPS[0] = len = 0;
    i = 1;
    while(i<plen) {
        if(pat[i]==pat[len]) {
            len++;
            LPS[i] = len;
            i++;
        } else {
            if(len!=0) {
                len = LPS[len-1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
int KMP() {
    int i, j;
    mplen = mpat.length();
    int *LPS = (int *)malloc(sizeof(int)*plen);
    computeLPSArray(LPS);
    i=j=0;
    while(i<mplen) {
        if(mpat[i]==pat[j]) {
            i++;
            j++;
            continue;
        }
        if(j==plen) {
            ;
        } else if(mpat[i]!=pat[j]) {
            if(j!=0) j = LPS[j-1];
            else i++;
        }
    }
    free(LPS);
    return j;
}

int main(int argc, const char *argv[]) {
    while(cin>>mpat) {
        mplen = mpat.length();
        pat.clear();
        pat = mpat;
        reverse(pat.begin(),pat.end());
        plen = pat.length();
        int ret = KMP();
        cout<<mpat;
        for(int i=ret; i<plen; i++) cout<<pat[i];
        cout<<"\n";
    }
    return 0;
}



