#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

int mod = 1e9 + 7;
long long bin_pow(int a,int b){
    if(b == 0)return 1;
    long long res = 1LL;
    while(b > 0){
        if(b&1)res = (res *1LL* a) % mod;
        a = (a *1LL* a) % mod;
        b = b >> 1;
    }
    return res;
}
/*
1 2 3 4 5
1 1 1 1 1
  1 2 3 4
    1 3 6
      1 4
        1
this is binaoial exponetntional sum of them = 2^n

wromg


1 1 2 3 4 5 

when i am at A[i] remove those frequency from the result like i ma usng it now
so divide freq+1 now add it to result now add frequency and multipley with frequeucy+1 later;

lets dry run this on 1 2 1 3

curr = 0;
curr += 1 * 1;

curr += 1 * 2;

curr res = 2 * 2;
res /= 2;
curr += 2;

res *= 3;
res became = 6 now

now i iwll divide with freq_1 which is 6

total would be 6 + 2+ 2+1 == 11 correct lets implement htis 
*/
void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int &i : A)cin >> i;
    
    map<int,int> M;
    long long res = 1LL;
    long long ans = 0LL;
    for(int i : A){
        int c = M[i]+1;
        int inv_c = bin_pow(c,mod-2);
        res = (res * inv_c) % mod;
        ans = (ans + res) % mod;
        M[i]++;
        int t = M[i]+1;
        res = (res * t) % mod;
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