#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;    

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<long long> dp(m + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != LLONG_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[m] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[m] << endl;
    }
    return 0;
}