#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.



*/


/*
sort array for efficenty and iterate on target for very target iterate on coins
dp[i] = dp[i-c] + 1;
*/ 
void solve(){
    int n,t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    sort(arr.begin(),arr.end());
    vector<int> dp(t+1,1e9);
    dp[0] = 0;
    for(int i = 1 ; i <= t ; i++){
        for(int c : arr){
            if(c > i)break;
            dp[i] = min(dp[i],dp[i-c]+1);
        }
    }
    int ans = dp[t] == 1e9 ? -1 : dp[t] ;

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