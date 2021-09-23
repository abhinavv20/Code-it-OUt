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
const ll m = 2e5+1;
ll dp[m];
#define ll long long
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
int count(ll n){
  if(n == 1){
    return 1;
  }
  if(dp[n]){
    return dp[n];
  }
  else{
    for (int i = 1; i < n+1; ++i){
      dp[n]+= count(n-i);
    }
  }
  return dp[n];
}
void solve(){
  ll t = 1;
  // cin >> t;
  while(t--){
    ll n,k;
    cin >> n >> k;
    vll v(n);
    mll m;
    for (int i = 0; i < n; ++i){
      cin >> v[i];
    }
    vll pre(n);
    pre[0] = v[0];
    m[pre[0]]++;
    for (int i = 1; i < n; ++i){
      pre[i] = pre[i-1] + v[i];
      m[pre[i]]++;
    }
    ll ans = 0;
    for(int i = n-1; i >= 0 && pre[i] >= k; --i){
      if(pre[i] == k){
        ans++;
        break;
      }
      ll x = pre[i] - k;
      if(bs(all(pre),x)){
        ans+=m[x];
      }
    }
    cout << ans << endl;
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
