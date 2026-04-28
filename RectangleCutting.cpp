#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
#include<cstring>
#include<map>
#include<utility>
using namespace std;    

const int maxi=507;
long long dp[maxi][maxi];
int main() {
   int n,m;
    cin >> n >> m;
   for(int i = 0; i < maxi; i++) {
    for(int j = 0; j < maxi; j++) {
        dp[i][j] = 1e10; // large value
    }
}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            //horizontal cut
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
            }
            //vertical cut
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
    