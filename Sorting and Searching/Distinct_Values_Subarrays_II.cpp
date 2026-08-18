#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
5 2
1 2 3 1 1

1 
2 21
3 32 
1 13 
1 11 113


*/
void solve(){
    int n,k;
    cin >> n >> k;

    unordered_map<int,int> m;
    vector<int> arr(n);
    for(int &i : arr)cin >> i;
    
    int c = 0;
    int ans = 0;
    int i = 0;
    for(int j = 0 ; j < n ; j++){
        c++;
        m[arr[j]]++;
        while((int)(m.size()) > k){
            c--;
            m[arr[i]]--;
            if(m[arr[i]] == 0)m.erase(arr[i]);
            i++;
        }
        ans += c;
    }
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