#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

int dp[20][2][11][2];
int rec(string& s,int i,int tight,int prev,int l){
    if(i == (int)s.size()){
        return 1;
    }
    if(dp[i][tight][prev+1][l] != -1)return dp[i][tight][prev+1][l];
    int m = tight ? s[i]-'0' : 9;
    int c = 0;
    for(int d = 0 ; d <= m ; d++){
        if(d == prev)continue;
        int curr_tight = tight && (d == m); 
        int curr_l = l && (d == 0);
        int curr_prev = curr_l ? -1 : d;
        c += rec(s,i+1,curr_tight,curr_prev,curr_l);
    }
    return dp[i][tight][prev+1][l] = c;
}
void solve(){
    int l,r;
    cin >> l >> r;
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j <= 1 ; j++){
            for(int k = 0 ; k < 11 ; k++){
                for(int a = 0 ; a <= 1 ; a++){
                    dp[i][j][k][a] = -1;
                }
            }
        }
    }

    int ans1 = 0;
    if(l != 0){
        string s = to_string(l-1);
        ans1 = rec(s,0,1,-1,1);
    }
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j <= 1 ; j++){
            for(int k = 0 ; k < 11 ; k++){
                for(int a = 0 ; a <= 1 ; a++){
                    dp[i][j][k][a] = -1;
                }
            }
        }
    }
    string t = to_string(r);
    int ans2 = rec(t,0,1,-1,1);
    int ans = ans2-ans1;
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