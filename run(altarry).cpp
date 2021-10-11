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
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; ++i){
      cin >> v[i];
    }
    vector<ll>dp(n , 0);
    dp[n - 1] = 1;
    ll flag = v[n - 1]/abs(v[n - 1]);
    for (int i = n - 2; i >= 0; --i){
      ll x = (v[i]/abs(v[i]));
      //cout << x << endl;
      if(x != flag){
        dp[i] = dp[i + 1] + 1;
        flag = x;
      }
      else{
        dp[i] = 1;
        flag = x;
      }
    }
    for(auto i : dp){
      cout << i << " ";
    }
    cout << endl;
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
