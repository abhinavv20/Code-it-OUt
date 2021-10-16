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
vector<int>adj[100001];
vector<int>vis(100001 ,0);
void bfs(int node){
  vis[node] = 1;
  queue<int>q;
  q.push(node);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
      if(!vis[it]){
        vis[it] = 1;
        q.push(it);
      }
    }
  }       
}
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}
void solve(){
  ll tt = 1;
  while(tt--){
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int head;
    cin >> head;
    ll count = 0,ans = 0;
    for (int i = head; i <= n; ++i){
        if(count >= 1){
            ans = 0;
            for (int i = 1; i <= n; ++i){
              if(vis[i] == 0){
                ans++;
              }
            }
            break;
        }
        if(vis[i] == 0){
           count++;
           bfs(i);
        }
    }
    cout << ans << endl;
  }
}
int main(){ 
  fast();
  solve();
}
