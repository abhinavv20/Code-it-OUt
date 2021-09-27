#include <bits/stdc++.h>

using namespace std;
#define ll  long long
#define mod 1000000007
#define ms0(s) memset(s,0,sizeof s)
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
ll ncr(ll n, ll r){
  if(n < r){
    return 0;
  }
  if(n - r < r){
    r = n - r;
  }
  ll dp[r+1];
  ms0(dp);
  dp[0] = 1;
  for (ll i = 1; i <= n; ++i){
    for (ll j = min(r,i); j > 0; --j){
      dp[j] = (dp[j] + dp[j-1])%mod;
    }
  }
  return dp[r];
}
/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int solve(int n, int m) {
 ll x = max(n,m);
ll k = 1,ans = 0;
while(k <= min(n,m)){
    ll y = ncr(x + 1 , k);
    ll z = ncr(min(n,m) - 1 , k - 1);
    ll x = (y%mod * z%mod)%mod;
    ans = (ans%mod + x%mod)%mod;
    k++;
}
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = solve(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
