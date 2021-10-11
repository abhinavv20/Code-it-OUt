#include <bits/stdc++.h>
using namespace std;
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
    ll n;
    cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; ++i){
      cin >> v[i];
    }
    vector<ll>dp(n + 1, INF);
    dp[0] = 0;
    for (ll i = 0; i < n; ++i){
      for(ll j = i + 1; j <= i + 2; ++j){
        if(j >= n){
          break;
        }
        dp[j] = min(dp[j] , dp[i] + abs(v[j] - v[i]));
      }
    }
    cout << dp[n - 1] << endl;
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
