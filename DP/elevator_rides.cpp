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
    ll n, x;
    cin>>n>>x;

    vector<ll>w(n);
    for(auto& i: w) cin>>i;

    vector<pair<ll, ll>>dp((1LL << n), {1e18, 1e18});
    dp[0] = {1, 0};
    for(int i = 0; i < (1LL << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1LL << j)) {
                // do nothing
            } else{
                ll r = dp[i].ff;
                ll weight = dp[i].ss;

                if(weight + w[j] <= x){
                    dp[i | (1LL << j)] = min(dp[i | (1LL << j)], {r, w[j] + weight});
                } else{
                    dp[i | (1LL << j)] = min(dp[i | (1LL << j)], {r+1, w[j]});
                }
            }
        }
    }

    cout << dp[(1LL << n) - 1].ff << "\n";
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
