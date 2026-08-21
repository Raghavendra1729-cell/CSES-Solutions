#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    vector<tuple<int,int,int>> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int s,e,p;
        cin >> s >> e >> p;
        arr.push_back({e,s,p});
    }
    sort(arr.begin(),arr.end());
    vector<int> dp(n+1,0);
    for(int i = 0 ; i < n ; i++){
        auto [e,s,p] = arr[i];
        int l = 0;
        int r = i-1;
        int idx = -1;
        while(l <= r){
            int mid = l + ((r-l) >> 1);
            auto [e1,s1,p1] = arr[mid];
            if(e1 < s){
                idx = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        int ans = 0;
        if(idx != -1) ans = dp[idx+1];
        dp[i+1] = max(dp[i],ans+p); 
    }

    cout << dp[n] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}