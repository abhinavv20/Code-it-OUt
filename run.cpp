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
    ll n,count = 0;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; ++i){
       cin >> v[i];
    }
    if(n == 1){
      cout << 1 << endl;
      cout << "R" << endl;
    }
    else{
    ll l = 0,r = n-1,min = 1;
    string s1;
    vll le,ri;
    while(r>l){
      le.pb(l);
      ri.pb(r);
      if(v[l] < v[r]){
        if(v[l] >= min){
        min = v[l];
        s1.push_back('L');
        l++;
        continue;
        }
        if(v[r] >= min){
        min = v[r];
        s1.push_back('R');
        r--;
        continue;  
        }
        else{
          break;
        }
      }
      if(v[r] < v[l]){
        if(v[r] >= min){
        min = v[r];
        s1.push_back('R');
        r--;
        continue;
        }
        if(v[l] >= min){
        min = v[l];
        s1.push_back('L');
        l++;
        continue;  
        }
        else{
          break;
        }
      }
    }
    // cout << min << endl;
    ll left = le[int(le.size())-1];
    ll right = ri[int(ri.size())-1];
    // cout << left << right << endl;
    if(v[left] > min){
      s1.push_back('L');
    }
    if(v[right] > min){
      s1.push_back('R');
    }
    if(s1.length() == n){
      s1.erase(s1.length()-1,1);
      if(v[0] == 1)
      s1.push_back('L');
      if(v[n-1] == 1)
      s1.push_back('R');
    }
    cout << s1.length() << endl;
    cout << s1;
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