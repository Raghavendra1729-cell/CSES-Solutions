#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 1;
void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    if(a+b > n){
        cout << "NO" << endl;
        return;
    }

    if(a == 0 && b == 0){
        cout << "YES" << endl;
        for(int i = 1 ; i <= n ; i++)cout << i << " ";
        cout << endl;
        for(int i = 1 ; i <= n ; i++)cout << i << " ";
        cout << endl;
        return;
    }

    if(a == 0 || b == 0){
        cout << "NO" << endl;
        return;
    }


    vector<pair<int,int>> ans;
    for(int i = 2 ; i <= b ; i++){
        ans.push_back({i-1,i});
    }

    if(a != 1){
        for(int i = b+2 ; i <= a + b  ; i++){
            ans.push_back({i,i-1});
        }
    }

    ans.push_back({b,a+b});
    ans.push_back({b+1,1});

    for(int i = a+b+1 ; i <= n ; i++){
        ans.push_back({i,i});
    }


    cout << "YES" << endl;
    for(auto &i : ans){
        cout << i.first << " ";
    }
    cout << endl;

    for(auto &i : ans){
        cout << i.second << " ";
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