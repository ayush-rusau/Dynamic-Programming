#include <bits/stdc++.h>
using namespace std;

int solve(int **input, int n, int m) {
    int dp[n][m];
    for(int i = 0;i<n;i++) {
        if(input[i][0]) dp[i][0] = 0;
        else dp[i][0] = 1;
    }
    for(int i = 0;i<m;i++) {
        if(input[0][i]) dp[0][i] = 0;
        else dp[0][i] = 1;
    }
    
    for(int i =1;i<n;i++) {
        for(int j = 1;j<m;j++) {
            if(input[i][j] == 0) {
                // int len1 = 0, len2 =0  ;
                // for(int k1 = i-1;k1>=0;k1--) {if(input[k1][j]) {flag = false; break;} else {len1++ ;}}
                // for(int k2 = j-1;k2>=0;k2--) {if(input[i][k2]) {flag = false; break;} else {len2++ ;}}
                // int len = dp[i-1][j-1];
               
                // if(len1>=len && len2 >= len) dp[i][j] = dp[i-1][j-1] + 1;
                // else dp[i][j] = min(len1, len2) + 1;

                //Better Approach
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int max = 0;
    for(int i = 0;i<n;i++) {
        for(int j =0;j<m;j++) {
            if(dp[i][j] > max) max = dp[i][j];
        }
    }

    return max;
}


int main() {
    int n, m;
    cin >> n >> m;
    int **input = new int*[n];
    for(int i = 0;i<n;i++) input[i] = new int[m];

    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin >> input[i][j];
    
    int ans = solve(input, n, m);
    cout << ans << endl;

    for(int i = 0;i<n;i++) delete [] input[i];
    delete [] input ;

    return 0;
}