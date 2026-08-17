#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
void solve(){
    string s;
    cin >> s;
    vector<int> A(26,0);
    for(char i : s)A[i-'A']++;
    int c = 0;
    for(int i : A){
        if(i&1)c++;
    }
    if(c > 1){
        cout << "NO SOLUTION" << endl;
        return;
    }

    string temp = "";
    string temp2 = "";
    for(int i = 0 ; i < 26 ; i++){
        if(A[i]&1){
            string t(A[i],'A'+i);
            temp2 += t;
        }else{
            string t(A[i]/2,'A'+i);
            temp += t;
        }
    }
    string ans = temp;
    ans += temp2;
    reverse(temp.begin(),temp.end());
    ans += temp;
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