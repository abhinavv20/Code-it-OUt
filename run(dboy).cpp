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
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
void solve(){
  ll tt = 1;
  cin >> tt;
  while(tt--){
    ll n;
    cin >> n;
    vector<ll>v(n);
    vector<ll>l(n);
    for (int i = 0; i < n; ++i){
      cin >> v[i];
    }
    for (int i = 0; i < n; ++i){
      cin >> l[i];
    }
    ll z = *max_element(all(v));
    vector<ll>dp((2*z) + 1 , INF);
    dp[0] = 0;
    sort(all(l));
    ll ans = 0;
    for (int i = 0; i < n; ++i){
      ll x = 2*v[i];
      if(dp[x] != INF){
          ans = ans + dp[x];
          continue;
      }
      for (int j = 0; j < x + 1; ++j){
        for (auto k : l){
          if(k > j) break;
          dp[j] = min(dp[j] , dp[j - k] + 1);
        }
      }
      ans = ans + dp[x];
    }
    cout << ans << endl;
  }
}
int main(){ 
  fast();
  solve();
}
