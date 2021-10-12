#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define ms0(s) memset(s,0,sizeof s)
#define ff first
#define ss second
typedef long long int ll;
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e9+9;
#define ll long long
ll calc(ll x,ll y){
  ll ans=1;
  x = x%mod;
  if(x == 0){
    return 0;
  }
  while(y>0){
    if(y&1){
      ans = (ans*x)%mod;
    }
    x=(x*x)%mod;
    y=y>>1;
  }
  return ans;
}
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
void solve(){
  ll t = 1;
  // cin >> t;
  while(t--){
    ll n,k;
    cin >> n >> k;
    vector<int>coins(n);
    for (ll i = 0; i < n; ++i){
      cin >> coins[i];
    }
    vector<int>dp(k + 1 , INF);
    dp[0] = 0;
    for (int i = 1; i < k + 1; ++i){
      for(auto x : coins){
        if(x > i){
          continue;
        }
        dp[i] = min(dp[i] , dp[i - x] + 1);
      }
    }
    if(dp[k]!=INF)
      cout << dp[k] << endl;
    else
      cout << -1 << endl;
  }
}
int main(){ 
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  fast();
  solve();
}
