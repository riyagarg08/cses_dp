// You are given a row of numbers, and two players take turns picking either the first or last element. Both play optimally.
// The goal is to find the maximum score you can guarantee, assuming the opponent also plays smart.
// Instead of calculating exact scores directly (which gets complicated), we use a simpler idea:
//  track difference = (your score − opponent’s score)
// For any subarray [i…j], it is your turn and you have two choices:
// pick the left element
// pick the right element
// After your move, the opponent plays on the remaining subarray and will try to maximize their own advantage.
// Since the opponent’s gain reduces your advantage, you subtract their result from your current choice.
// For both choices (left and right), you evaluate:
//  (value you pick − opponent’s best result from remaining part)
// You then choose the option that gives you the maximum value, because you want to stay as far ahead as possible.
// The base case is simple: if only one element is left, you take it.
// The final result gives the difference between your score and opponent’s score, not the exact score.
// To get your actual score, combine this difference with the total sum of all elements.
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
using namespace std;

using ll = long long;
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
    cout<<(sum+dp[0][n-1])/2<<endl;
    return 0;
}
