#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
    4
    5 -65 -67 -67


    0 5 -60 
*/ 
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    vector<int> pre;
    pre.push_back(0LL);
    map<int,int> M;
    M[0]++;
    long long c = 0;
    int ans = 0LL;
    for(int i : arr){
        c += i;
        ans += M[((c % n) + n) % n];
        M[((c % n) + n) % n]++;
    }
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}