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
const ll INF = 1e5 + 5;
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
      ans=(ans*x);
    }
    x=(x*x);
    y=y>>1;
  }
  return ans;
}
ll count(ll n){
  if(n <= 1){
    return 1;
  }
  if(dp[n]){
    return dp[n];
  }
  else{
    for (ll i = 0; i < min(6ll,n); ++i){
      ll x = count(n-i);
      dp[n]+= x;
    }
  }
  return dp[n];
}
ll gcd(ll a, ll b){
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
void solve(){
  ll t = 1;
  cin >> t;
  while(t--){
    ll n,k;
    cin >> n >> k;
    vll v(k);
    for (int i = 0; i < k; ++i){
      cin >> v[i];
    }
    vll dp(k+1 , INF);
    dp[0] = 0;
    for (int i = 1; i < k+1; ++i){
      for (int j = 0; j < k; ++j){
        if(v[j] == -1) continue;
        if(j + 1 > i) continue;
        dp[i] = min(dp[i] , dp[i - (j+1)] + v[j]);
      }
    }
    if(dp[k] == INF){
      cout << -1 << endl;
    }
    else{
      cout << dp[k] << endl;
    }
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
