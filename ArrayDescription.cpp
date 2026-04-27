#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
using namespace std;    

int main() {
    int n,m;
    cin >> n >> m;
    int mod = 1e9 + 7;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if(arr[0]==0){
        for(int j=1;j<=m;j++){
            dp[0][j]=1;
        }
    }else{
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
           if(arr[i]!=0 && arr[i]!=j) continue;
           dp[i][j]=dp[i-1][j];
          
            dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
         if(j<m)  dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
        }
    }
   int ans=0;
    for(int j=1;j<=m;j++){
        ans=(ans+dp[n-1][j])%mod;
    }
    cout << ans << endl;
    return 0;
}