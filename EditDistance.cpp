#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
#include<cstring>
using namespace std;    

const int maxi=5007;
int dp[maxi][maxi];
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(),m=s2.size();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
    