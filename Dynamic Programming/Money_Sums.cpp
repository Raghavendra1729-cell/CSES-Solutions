#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    int sum = accumulate(arr.begin(),arr.end(),0LL);
    vector<int> dp(sum+1,0);
    dp[0] = 1;
    for(int i : arr){
        for(int j = sum ; j >= i ; j--){
            dp[j] = dp[j-i] | dp[j];
        }
    }

    int c = 0;
    for(int i : dp)if(i == 1)c++;
    c--;

    cout << c << endl;
    for(int i = 1 ; i <= sum ; i++){
        if(dp[i] == 1){
            cout << i << " ";
        }
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