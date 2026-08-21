#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
*/ 
int testcase = 0;
void solve(){
    int n,t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    vector<int> dp(t+1,0);
    dp[0] = 1;
    int mod = 1e9 + 7;
    sort(arr.begin(),arr.end());
    for(int i = 1 ; i <= t  ; i++){
        for(int j : arr){
            if(j > i)break;
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout << dp[t] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}