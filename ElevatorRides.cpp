#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define ll long long

int main() {

    int n;
    ll x;

    cin >> n >> x;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[mask] = {rides, last ride weight}
    vector<pair<ll,ll>> dp(1 << n);

    dp[0] = {1, 0};

    for (int mask = 1; mask < (1 << n); mask++) {

        dp[mask] = {1e18, 1e18};

        for (int i = 0; i < n; i++) {

            // if ith person is present in mask
            if (mask & (1 << i)) {

                int prevMask = mask ^ (1 << i);

                auto prev = dp[prevMask];

                ll rides = prev.first;
                ll weight = prev.second;

                // put in current ride
                if (weight + a[i] <= x) {
                    weight += a[i];
                }

                // start new ride
                else {
                    rides++;
                    weight = a[i];
                }

                dp[mask] = min(dp[mask], {rides, weight});
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}