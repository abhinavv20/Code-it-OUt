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
vector<ll>adj[100001];
vector<int>vis(100001);
ll bfs(ll node){
  ll count = 0;
  vis[node] = 1;
  queue<ll>q;
  q.push(node);
  count++;
  while(!q.empty()){
    ll node = q.front();
    q.pop();
    for(auto it : adj[node]){
      if(!vis[it]){
        vis[it] = 1;
        q.push(it);
        count++;
      }
    }
  }
  return count;     
}
void solve(){
  ll tt = 1;
  cin >> tt;
  while(tt--){
    ll n,m,x = 0;
    cin >> n >> m;
    ms0(adj);
    for (int i = 1; i <= 100001; ++i){
      vis[i] = 0;
    }
    for (ll i = 1; i <= m; ++i){
      ll u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ll ans = 0,z = 1;
    for (ll i = 1; i <= n; ++i){
      if(vis[i] == 0){
        ans++;
        z = (((z)%(mod))*((bfs(i))%(mod)))%mod;
      }
    }
    cout << (ans)%mod << " " << (z%mod) << endl;
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
