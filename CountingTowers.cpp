
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
using namespace std;    

int main() {
    const int MOD = 1e9+7;
int t;
cin>>t;
vector<int> temp;
    int maxn=0;
while(t--){
int n;
cin>>n;
      maxn=max(maxn,n);
      temp.push_back(n);
}
  vector<vector<long long>> dp(maxn+1,vector<long long>(2,0));
 

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= maxn; i++) {
        dp[i][0] = ((2 * dp[i-1][0])%MOD + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + (4ll * dp[i-1][1])%MOD) % MOD;
    }

    for(int x: temp){
        cout<<(dp[x][0] + dp[x][1]) % MOD<<endl;
    }
   return 0;
}