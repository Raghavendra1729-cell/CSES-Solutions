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
    vector<int> A(n);
    for(int &i : A)cin >> i;
    vector<int> B(n+1,0);
    int c = 0;
    for(int i : A){
        if(!B[i-1]){
            c++;
        }
        B[i] = 1;
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