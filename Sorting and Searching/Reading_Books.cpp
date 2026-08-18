#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

/*
3
8 3 2
3 2 8
*/ 
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i:arr)cin >> i;
    sort(arr.begin(),arr.end());
    int s = 0LL;
    for(int i = 0 ; i < n-1 ; i++)s += arr[i];
    int ans = max(arr[n-1],s) + arr[n-1];
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