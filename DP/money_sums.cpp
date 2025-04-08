////////////////////////////////
// Created by: GAJENDRA DHAKAD
////////////////////////////////
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
/*--------------------------------------------------------------------------------------------------------------------------*/
void FlameKaizer() {
    ll n;
    cin>>n;

    vector<ll>w(n);
    for(auto& i: w) cin>>i;
    
    vector<vector<int>>dp(n+1, vector<int>(100004, 0));

    // using first i coins , creating sum of j
    // dp[i][j] 
    dp[0][0] = 1;
    // dp[0][w[0]] = 1;
    for(int i = 1; i <= n; i++){
        for(int s = 0; s <= 1e5+4; s++){
            dp[i][s] = dp[i-1][s];
            ll left = s - w[i-1];
            if(left >= 0){
                dp[i][s] |= dp[i-1][left];
            }
        }
    }

    ll cnt = 0;
    vector<ll>ans;
    for(int s = 0; s <= 1e5; s++){
        if(s == 0) continue;
        if(dp[n][s]) {
            ans.pb(s);
            cnt++;
        }
    }

    cout << cnt << "\n";
    for(auto& i: ans){
        cout << i << " ";
    }

    cout << "\n";
}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    FlameKaizer();
    return 0;
}
