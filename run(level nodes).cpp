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
vector<int>adj[100001];
vector<int>vis(100001 ,0);
ll bfs(int node,int x){
  ll level  = 1;
  ll ans2 = 0;
  ll ans = 0;
  vis[node] = 1;
  queue<int>q;
  q.push(node);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    level++;
    vis[node] = 1;
    for(auto it : adj[node]){
      if(!vis[it]){
        ans++;
        vis[it] = 1;
        q.push(it);
      }
    }
    if(level == x - 1){
      ans2 = ans;
    }
    if(level == x){
      break;
    }
  }
  return ans - ans2;    
}
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
void solve(){
  ll tt = 1;
  while(tt--){
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int x;
    cin >> x;
    ll level = 1;
    ll ans = bfs(1,x);
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
