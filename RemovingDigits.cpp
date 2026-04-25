#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
using namespace std;    

int main() {
    int n;
    cin >> n;
   
    vector<long long> dp(n + 1 ,INT64_MAX);
    dp[0] = 0;
       for(int i=1;i<=n;i++){
        int x =i;
        while(x>0){
            int d = x%10;
            x/=10;
            if(d>0 && d<=i){
                dp[i] = min(dp[i],dp[i-d]+1);
            }
        }
       }
            cout << dp[n] << endl;           
            return 0;
        }