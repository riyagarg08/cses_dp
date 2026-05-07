#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define ll long long
//sort + dp+ binary search

int main() {

    int n;
    cin >> n;

    vector<vector<ll>> projects(n);

    for (int i = 0; i < n; i++) {
        ll start, end, reward;
        cin >> start >> end >> reward;

        projects[i] = {end, start, reward};
    }

    // sort by ending day
    sort(projects.begin(), projects.end());

    vector<ll> dp(n);

    // store ending days separately
    vector<ll> ends;

    for (auto &p : projects) {
        ends.push_back(p[0]);
    }

    for (int i = 0; i < n; i++) {

        ll end = projects[i][0];
        ll start = projects[i][1];
        ll reward = projects[i][2];

        // take current project
        ll take = reward;
  
        // find last project with end < start
        int idx = lower_bound(ends.begin(), ends.end(), start)
                  - ends.begin();

        idx--;
        // cout<<idx<<" ";
        if (idx >= 0) {
            take += dp[idx];
        }
    //    cout<<take<<" ";
        // skip current project
        ll skip = (i > 0 ? dp[i - 1] : 0);
        // cout<<skip<<" ";
        dp[i] = max(take, skip);
        // cout<<endl;
    }

    cout << dp[n - 1] << endl;
}