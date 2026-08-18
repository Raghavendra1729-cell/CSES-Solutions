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
    deque<int> q;
    for(int i = 0 ; i < n ; i++){
        while(!q.empty() && arr[q.back()] >= arr[i]){
            q.pop_back();
        }
        if(q.empty()){
            cout << 0 << " ";
        }else{
            cout << q.back()+1 << " ";
        }
        q.push_back(i);
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