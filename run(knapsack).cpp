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
  // cin >> tt;
  while(tt--){
    ll n,w;
    cin >> n >> w;
    vector<ll>weight(n);
    vector<ll>value(n);
    for (int i = 0; i < n; ++i){
      cin >> weight[i] >> value[i];
    }
    ll dp[n + 1][w + 1];
    for (int i = 1; i < n + 1; ++i){
      dp[i][0] = 1;
    }
    for (int i = 0; i < w + 1; ++i){
      dp[0][i] = 0;
    }
    for (ll i = 1; i < n + 1; ++i){
      for (ll j = 1; j < w + 1; ++j){
        if(weight[i - 1] <= j){
          dp[i][j] = max((value[i - 1] + dp[i - 1][j - weight[i - 1]]), (dp[i - 1][j]));
        }
        else{
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    cout << dp[n][w] << endl;
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
