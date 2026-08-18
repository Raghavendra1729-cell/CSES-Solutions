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
    vector<pair<int,int>> p;
    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end(),[&](pair<int,int>& A,pair<int,int>& B){
        return A.second < B.second;
    });

    int e = 0;
    int c = 0;
    for(auto &i : p){
        if(i.first >= e){
            c++;
            e = i.second;
        }
    }
    cout << c << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}