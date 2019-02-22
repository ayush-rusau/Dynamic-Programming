#include <bits/stdc++.h>
using namespace std;
#define max 10005
int solve(string s,string v)
{
	// Write your code here.
  int m=s.size();
    int n = v.size();
    int dp[m+1][n+1];

    for(int i = 0;i<=m;i++) dp[i][0] = 1;
    for(int i = 0;i<=n;i++) dp[0][i] = max;

    for(int i = 1;i<=m;i++) {
        for(int j = 1;j<=n;j++) {
            int k;
            for(k = j-1;k>=0;k--) {
                if(v[k] == s[i-1]) break;
            }
            if(k == -1) dp[i][j] = 1;
            else dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
    // for(int i = 0;i<=m;i++) {
    //     for(int j = 0;j<=n;j++) cout << dp[i][j]  << " ";
    //     cout << endl;
    // }
    int ans = dp[m][n];
    if(ans>=max) return -1;
    return ans;
}

int main() {
    string s, v;
    cin >>s >> v;
    int ans = solve(s, v);
    cout << ans << endl;
    return 0;
}