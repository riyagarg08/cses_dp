#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
using namespace std;    


int main(){
   int n;
   cin>>n;
   int mod=1e9+7;
    vector<int> a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        a[i]=i+1;
        sum+=a[i];
    }
    if(sum%2!=0){
        cout<<0<<endl;
    }
    else{
       vector<long long> dp(sum/2+1,0);
       dp[0]=1;
       for(int i=0;i<n;i++){
           for(int j=sum/2;j>=a[i];j--){
               dp[j]=(dp[j]%mod+dp[j-a[i]]%mod)%mod;    
           }
        }
        cout << (dp[sum/2] * 1LL * 500000004) % mod << endl;
    }
    return 0;
}