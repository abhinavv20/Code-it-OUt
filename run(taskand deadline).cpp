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
#define ll long long
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
    ll a[n],b[n];
    vector<pair<ll,ll>> v;
    for (int i = 0; i < n; ++i){
      ll x,y;
      cin >> x >> y;
      v.push_back({x,y});
    }
    sort(all(v));
    ll sum = 0,count = 0;
    for (int i = 0; i < n; ++i){
      count+=v[i].first;
      sum+=(v[i].second-count);
    } 
    cout << sum << endl;
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
