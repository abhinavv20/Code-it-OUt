//created:abhinav
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define pob pop_back()
#define ms0(s) memset(s,0,sizeof s)
#define ff first
#define ss second
typedef long long int ll;
#define mmll multimap<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define prq priority_queue<ll>
#define psq priority_queue<ll,vector<ll>,greater<ll>>
#define m_p make_pair
#define vcc vector<char>
#define vss vector<string>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define setbit(n) __builtin_popcountll(n)
const ll INF = 1e9 + 5;
const ll m = 1e6+1;
ll dp[m];
#define ll long long
ll ncr(ll n, ll r){
  if(n < r){
    return 0;
  }
  if(n - r < r){
    r = n - r;
  }
  ll dp[r+1];
  ms0(dp);
  dp[0] = 1;
  for (ll i = 1; i <= n; ++i){
    for (ll j = min(r,i); j > 0; --j){
      dp[j] = (dp[j] + dp[j-1])%mod;
    }
  }
  return dp[r];
}
ll calc(ll x,ll y){
  ll ans=1;
  x = x % mod;
  if(x == 0){
    return 0;
  }
  while(y>0){
    if(y&1){
      ans=(ans*x)%mod;
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
  //cin >> t;
  while(t--){
    ll n;
    cin >> n;
    ll dp[n+1];
    ms0(dp);
    dp[0] = 1;
    for (ll i = 1; i <= n; ++i){
      for (ll j = 1; j <= min(6ll,i); ++j){
        dp[i] = ((dp[i])%mod + (dp[i - j])%mod)%mod;
      }
    }
    cout << dp[n] << endl;
  }
}
int main(){ 
//   #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   #endif
  fast();
  solve();
}
