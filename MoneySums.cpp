#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

// set<int> ans;
// void solve(int idx, int sum, int n, vector<int> &coins){
//     if(idx == n){
//         ans.insert(sum);
//         return;
//     }
//     solve(idx+1, sum, n, coins);
//     solve(idx+1, sum + coins[idx], n, coins);
// }
int main(){
    int n;
    cin >> n;

    vector<int> coins(n);
    int sum=0;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        sum += coins[i];
    }
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= coins[i]; j--){
           if(dp[j-coins[i]]){
               dp[j] = true;
           }
        }    }
        vector<int> ans;
        for(int i=1;i<=sum;i++){
            if(dp[i]) ans.push_back(i);
        }
      cout << ans.size() << endl;
      for(int i : ans) cout << i << " ";    
    return 0;
}