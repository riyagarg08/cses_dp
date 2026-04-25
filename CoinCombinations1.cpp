#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;    

int main() {
    int n, m;
    cin >> n >> m;
    int mod = 1000000007;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<long long> dp(m + 1,0);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 ) {
                dp[i] += (dp[i - coins[j]]%mod);
                dp[i] %= mod;
            }
        }
    }
   
        cout << dp[m] << endl;
    
    return 0;
}