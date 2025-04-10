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
int findBest(map<ll, ll>& mpp, ll val){
    auto it = mpp.lower_bound(val);
    if(it == mpp.begin()){
        return 0;
    }

    it--;
    return it->ss;
}

void insert_(map<ll, ll>& mpp, ll val, ll adv){
    if(mpp[val] >= adv) return;
    mpp[val] = adv;

    auto it = mpp.find(val);
    it++;
    while(it != mpp.end() and it->ss <= adv){
        auto temp = it;
        it++;
        mpp.erase(temp);
    }
}
void FlameKaizer() {
    int n;
    cin>>n;

    vector<ll>a(n);
    for(auto&i: a) cin>>i;

    map<ll, ll>mpp;
    vector<ll>dp(n);
    dp[0] = 1LL;
    mpp[a[0]] = dp[0];

    for(int i = 1; i < n; i++){
        dp[i] = 1 + findBest(mpp, a[i]);
        insert_(mpp, a[i], dp[i]);
    }

    ll ans = LLONG_MIN;
    for(auto& i: dp){
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
