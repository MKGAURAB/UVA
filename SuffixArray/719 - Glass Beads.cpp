/*
 * 719 - Glass Beads.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: ddxofy
 */
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
#define lim 20005
#define unq(vec) stable_sort(vec.begin(),vec.end());\
vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    stable_sort(BE(a))
#define sortc(a)    sort(BE(a),comp)

struct SA {
	const static int maxn = lim;

	int n, m;
	int sa[maxn];       //, sa[i] = j, i from 1 to n, j from 0 to n-1
	int rank[maxn];     //, rank[i] = j, i from 0 to n-1, j from 1 to n
	int hei[maxn];      //hei[i] = LCP(suffix(sa[i-1], sa[i])
	int wa[maxn], wb[maxn], wv[maxn], wt[maxn];

	int cmp(int *r, int a, int b, int l) {
		return r[a] == r[b] && r[a + l] == r[b + l];
	}

	//r[], from 0 to n-1
	void build_sa(int *r, int n, int m) {
		r[n] = 0;
		this->n = n;
		++n;

		int i, j, p, *t, *x = wa, *y = wb;
		for (i = 0; i < m; i++)
			wt[i] = 0;
		for (i = 0; i < n; i++)
			wt[x[i] = r[i]]++;
		for (i = 1; i < m; i++)
			wt[i] += wt[i - 1];
		for (i = n - 1; i >= 0; i--)
			sa[--wt[x[i]]] = i;

		for (j = 1, p = 1; p < n; j *= 2, m = p) {
			for (p = 0, i = n - j; i < n; i++)
				y[p++] = i;
			for (i = 0; i < n; i++)
				if (sa[i] >= j)
					y[p++] = sa[i] - j;

			for (i = 0; i < n; i++)
				wv[i] = x[y[i]];
			for (i = 0; i < m; i++)
				wt[i] = 0;
			for (i = 0; i < n; i++)
				wt[wv[i]]++;
			for (i = 1; i < m; i++)
				wt[i] += wt[i - 1];
			for (i = n - 1; i >= 0; i--)
				sa[--wt[wv[i]]] = y[i];

			for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
				x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
		return;
	}

	void calhei(int *r) {
		int i, j, k = 0;
		for (i = 1; i <= n; i++)
			rank[sa[i]] = i;
		for (i = 0; i < n; hei[rank[i++]] = k)
			for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++)
				;
		return;
	}
} OBJ;

int inp[lim];
char cinp[lim];


int main(int argc, const char **argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test, len, llen;
	cin>>test;
	REP(i,1,test)
	{
		cin>>cinp;
		len = llen = strlen(cinp);
		REP(j,0,(len-1)) inp[j] = cinp[j];
		REP(j,0,(len-1)) inp[llen++] = cinp[j];
		inp[llen] = 0;
		OBJ.build_sa(inp,llen,125);
		OBJ.calhei(inp);
		int RES = -1;
		REP(j,1,llen)
		{
			if(OBJ.sa[j]<=len)
			{
				if(RES==-1) RES = OBJ.sa[j];
				else if(OBJ.hei[j]>=len) RES = OBJ.sa[j];
				else break;
			}
		}
		cout<<RES+1<<"\n";
	}
	return 0;
}

