// created : abhinav
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
vector<ll> adj[100001];
vector<ll>vis(100001 , 0);
vector<pair<int,int>>f;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
ll bfs(ll node,ll x,vector<ll>v){
  ll size = 0;
  queue<pair<ll,ll>>q;
  ll ans = 0;
  vis[node] = 1;
  ans++;
  q.push({node , v[0]});
  while(!q.empty()){
    int node = q.front().first;
    int par = q.front().second;
    // f.push_back(make_pair(node,par));
    q.pop();
    for(auto it:adj[node]){
      if(!vis[it]){
        q.push({it,node});
        f.push_back(make_pair(it,node));
        vis[it] = 1;
        size++;
      }
    }
  }
  return size;
}
void solve(){
  ll tt = 1;
  while(tt--){
    ll n,k;
    cin >> n >> k;
    vector<ll>v(n + 1);
    for (int i = 1; i <= n; ++i){
      cin >> v[i];
    }
    for (int i = 0; i < n - 1; ++i){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> iN(n + 1,0);
    vector<int> ouT(n + 1,0);
    for(int i=0;i<=n;i++){
      ouT[i] = adj[i].size();
      for(int j=0;j<adj[i].size();j++)
        iN[adj[i][j]]++;
    }
    ll size = bfs(1ll,k,v);
    for (int i = 2; i < 100001; ++i){
      vis[i] = 0;
    }
    vector<ll>ans;
    vector<ll>vr(n + 1 , 0);
    ll count;
    ll y = v[1];
    if(y == 0){
      vr[1] = 0;
    }
    else{
      vr[1] = 1;
    }
    for(auto i : f){
      ll y = vr[i.ss] + v[i.ff];
       if(y <= k){
         vis[i.ff] = 1;
         if(v[i.ff] == 0){
             vr[i.ff] = 0;
             continue;
         }
         vr[i.ff] = y;
         continue;
       }
       if(y > k){
           vis[i.ff] = -1;
       }
       vr[i.ff] = y;
    }
    ll finans = 0;
    for(int i= n ;i >= 2; -- i){
      if(iN[i] == 1 && vis[i] <= k && vis[i] != -1 && ouT[i] == 1){
          finans++;
          continue;
      }
    }
    cout << finans << endl;
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
