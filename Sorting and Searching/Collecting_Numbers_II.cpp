#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

int testcase = 0;
/*
    1,2  2,3   3,5   4,1   5,4
*/
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> index(n+1),arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        index[arr[i]] = i+1;
    }

    int c = 1;
    for(int i = 2 ; i <= n ; i++){
        if(index[i-1] > index[i]){
            c++;
        }
    }


    while(q--){
        int a,b;
        cin >> a >> b;
        if(a > b)swap(a,b);
        int num1 = arr[a-1];
        int num2 = arr[b-1];

        /*
        4 3
        a b 
        c--;
        */
        
        /*
        3 4
        a b 
        c++;
        */
        if(num1 == num2+1){
            c--;
            // if(num1+1 <= n && a < index[num1+1] && index[num1+1] < b)c++;
            // if(num2-1 >= 1 && a < index[num1-1] && index[num1-1] < b)c++;
        }
        if(num1+1 == num2){
            // if(num1-1 >= 1 && index[num1-1] > a && index[num1-1] < b)c--;
            // if(num2+1 <= n && index[num2+1] > a && index[num2+1] < b)c--;
            c++;
        }
        /*
            4 1 2 5 3
            3 1 2 5 4
        */
        if(num1-1 >= 1 && a < index[num1-1] && index[num1-1] < b)c--;
        if(num1+1 <= n && a < index[num1+1] && index[num1+1] < b)c++;

        
        if(num2-1 >= 1 && a < index[num2-1] && index[num2-1] < b)c++;
        if(num2+1 <= n && a < index[num2+1] && index[num2+1] < b)c--;

        cout << c << endl;
        swap(arr[a-1],arr[b-1]);
        index[num1] = b;
        index[num2] = a;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    if(testcase) cin>>t;
    while(t--) solve();
    return 0;
}