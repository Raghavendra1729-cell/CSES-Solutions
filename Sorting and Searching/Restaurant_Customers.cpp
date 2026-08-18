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
    vector<int> A(n),B(n);
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        cin >> B[i];
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int i = 0;
    int j = 0;
    int c = 0;
    int m = 0;
    while(i < n && j < n){
        if(A[i] <= B[j]){
            c++;
            i++;
            m = max(m,c);
        }
        if(A[i] >= B[j]){
            c--;
            j++;
            m = max(m,c);
        }
    }
    cout << m << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}