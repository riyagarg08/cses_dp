#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
using namespace std;    

int main() {
    int n;
    cin >> n;
   vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
   vector<vector<long long>> dp(n  ,vector<long long>(n , 0));
    if (grid[n-1][n-1] == '*') dp[n-1][n-1] = 0;
    else dp[n-1][n-1] = 1;
       for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if(i+1 < n && i+1>=0) {
                    dp[i][j] += dp[i+1][j];
                    dp[i][j] %= 1000000007;
                }
                if(j+1 < n && j+1>=0) {
                    dp[i][j] += dp[i][j+1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
       }
            cout << dp[0][0] << endl;           
            return 0;
        }
    