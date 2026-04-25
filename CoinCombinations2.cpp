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
    sort(coins.begin(), coins.end());
coins.erase(unique(coins.begin(), coins.end()), coins.end());
n = coins.size();
    vector<long long> dp(m + 1 ,0);
    dp[0] = 1;
    for(int j=0;j<n;j++){
       for(int i=coins[j];i<=m;i++){
           dp[i] += (dp[i - coins[j]]%mod);
           dp[i] %= mod;
       }
    }
   
                cout << dp[m] << endl;
            
            return 0;
        }