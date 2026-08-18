#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;

/*
        1 2 3 4 5 6 7 1 3 5 7 3 7 7   
        2 4 5 6 1 5 7 5 
*/ 

void solve(){
    int  n;
    cin >> n;
    vector<int> v;
    for(int i = 1 ; i <= n ; i++)v.push_back(i);
    int e = 1;
    while(!v.empty()){
        vector<int> temp;
        for(int i = 0 ; i < v.size() ; i++){
            if((i&1) == e){
                cout << v[i] << " "; 
            }else{
                temp.push_back(v[i]);
            }
        }
        if(((int)v.size())&1){
            if(e){
                e = 0;
            }else{
                e = 1;
            }
        }else{
            if(e){
                e = 1;
            }else{
                e = 0;
            }
        }
        v = temp;
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