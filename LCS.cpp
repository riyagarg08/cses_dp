#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
#include<cstring>
#include<map>
#include<utility>
using namespace std;    

const int maxi=1007;
long long dp[maxi][maxi];
int main() {
   int n,m;
    cin >> n >> m;
   vector<long long> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
  
    cout << dp[n][m] << endl;
    int x=n,y=m;
    vector<long long> ans;
    while(x>0 && y>0){
        if(a[x-1]==b[y-1]){
            ans.push_back(a[x-1]);
            x--;
            y--;
        }
        else if(dp[x-1][y]>dp[x][y-1]) x--;
        else y--;
    }
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
    return 0;
}
    