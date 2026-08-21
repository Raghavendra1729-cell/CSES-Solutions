#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

vector<vector<int>> dp;
int rec(int i,int j,vector<int>& A){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    if(i == j){
        return dp[i][j] = A[i];
    }
    int s1 = A[i] - rec(i+1,j,A);
    int s2 = A[j] - rec(i,j-1,A);
    return dp[i][j] = max(s1,s2);
}

/*
s1 + s2 = s;
s1 - s2 = d;
s1 = s + d/2


*/ 
void solve(){
    int n;
    cin >> n;
    dp = vector<vector<int>>(n,vector<int>(n,-1));
    vector<int> A(n);
    for(int &i : A)cin >> i;
    int d = rec(0,n-1,A);
    int s = accumulate(A.begin(),A.end(),0LL);
    
    int p1 = d + s;
    p1 = p1/2;

    cout << p1 << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}