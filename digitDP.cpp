#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b;

ll dp[20][20][2];
int d, k;

ll count(vector<int> digits, int pos, int freq, int check) {

    if(pos == digits.size()) {
        
        if(freq == k) return 1;
        else return 0;
    }

    if(dp[pos][freq][check] > -1) return dp[pos][freq][check];

    int lim;
    if(check) lim = 9;
    else lim = digits[pos];
    int currCount = 0;
    for(int i = 0;i<=lim;i++) {
        if(i < digits[pos]) {
            if(i == d)
                currCount += count(digits, pos+1, freq+1, 1);
            else
                currCount += count(digits, pos+1, freq, 1);
        } else {
            if(i == d) 
                currCount += count(digits, pos+1, freq+1, check);
   
            else    
                currCount += count(digits, pos+1, freq, check);
        }
    }
    dp[pos][freq][check] = currCount;
    return currCount ;
}

ll solve(ll num) {
    memset(dp, -1, sizeof dp);

    vector<int> digits;
    while(num > 0) {
        int temp = num%10;
        num /= 10;
        digits.push_back(temp);
    }
    reverse(digits.begin(), digits.end());
    
    ll ans = count(digits, 0, 0, 0);
    return ans;
}

int main() {
    cin >> a >> b >> d >> k;
    ll ans1 = solve(b);
    ll ans2 = solve(a-1);
    cout << ans1 - ans2 << endl;
    return 0;
}