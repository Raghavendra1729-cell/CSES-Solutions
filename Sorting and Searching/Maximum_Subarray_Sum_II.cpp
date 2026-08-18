#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
4 5 
0 1 2 3 4 5 6 7 8 9 
*/
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;


    vector<int> pre;
    pre.push_back(0LL);
    for(int i : arr){
        pre.push_back(pre.back()+i);
    }


    deque<pair<int,int>> mini;
    int m = LLONG_MIN;

    for(int i = a ; i < n+1 ; i++){
        while(!mini.empty() && mini.back().first >= pre[i-a])mini.pop_back();
        mini.push_back({pre[i-a],i-a});
        while(!mini.empty() && mini.front().second < i-b)mini.pop_front();
        m = max(m,pre[i]-mini.front().first);
    }

    cout << m << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}