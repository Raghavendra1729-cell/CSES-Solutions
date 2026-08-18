#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
/*
0 1 2 3 4 5 6 7 8
    1 1     1 
*/ 
int testcase = 0;
void solve(){
    int n,x;
    cin >> n >> x;
    set<pair<int,int>> s;
    multiset<int> len;
    s.insert({0,n});
    len.insert(n);
    while(x--){
        int t;
        cin >> t;
        auto it = s.upper_bound({t,-1});
        it--;
        auto temp = *it;
        s.erase(it);

        int curr_length = temp.second-temp.first;
        auto it_l = len.find(curr_length);
        if(it_l != len.end())len.erase(it_l);

        s.insert({temp.first,t});
        s.insert({t,temp.second});
        len.insert(t-temp.first);
        len.insert(temp.second-t);

        cout << *len.rbegin() << " ";
    }
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}