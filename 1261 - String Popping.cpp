#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


bool rec(bool val, string str)
{
    if(str.length()==0) return true;
    vector<pair<int, int> > pos;
    int tmp = 1, cnt = 1, tmpp = 0;
    while(tmp<=str.length())
    {
        if(str[tmpp]==str[tmp]) cnt++;
        else
		{
            if(cnt>=2) pos.push_back(make_pair(tmpp,tmp-1));
            tmpp = tmp;
            cnt = 1;
        }
        tmp++;
    }
    for(int j=0; j<pos.size(); j++)
    {
        string tmp= str;
        tmp.erase(tmp.begin()+pos[j].first,tmp.begin()+pos[j].second+1);
        val = (val | rec(val,tmp));
        if(val) return val;
    }
    return false;
}

int main()
{
    int test, len;
    string str;
    cin>>test;
    for (int i=1; i<=test; ++i)
    {
        cin>>str;
        len = str.length();
        bool res = rec(false,str);
        if(res) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
