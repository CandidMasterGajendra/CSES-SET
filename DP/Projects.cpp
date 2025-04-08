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
// #define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
/*--------------------------------------------------------------------------------------------------------------------------*/
int binSearch(ll& st, int i, vector<pair<ll, pair<ll, ll>>>& a){
    int ans = -1;   
    int s = 0, e = i-1;
    while(s <= e){
        int mid = (s + e) / 2;
        if(a[mid].ss.ff < st){
            ans = mid;
            s = mid+1;
        } else e = mid-1;
    }

    return ans;
}
void FlameKaizer() {
    int n;
    cin>>n;

    // map<pair<ll, ll>, ll>mp;
    vector<pair<ll, pair<ll, ll>>>a(n);
    for(int i = 0; i < n; i++){
        ll x, y, w;
        cin>>x>>y>>w;
        a[i].ff = x;
        a[i].ss.ff = y;
        a[i].ss.ss = w;
    }

    sort(all(a), [&](pair<ll, pair<ll, ll>>& aa, pair<ll, pair<ll, ll>>& yy){
        return aa.ss.ff < yy.ss.ff;
    });

    vector<ll>dp(n, 0);
    dp[0] = a[0].ss.ss;
    for(int i = 1; i < n; i++){
        ll st = a[i].ff;
        ll end = a[i].ss.ff;

        int idx = binSearch(st, i, a);
        dp[i] = max(a[i].ss.ss + (idx >= 0 ? dp[idx]: 0LL), dp[i-1]);
    }

    ll ans = -1;
    for(auto& i: dp){
        // cout << i << " ";
        ans = max(ans, i);
    }
    cout << ans << "\n";

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
