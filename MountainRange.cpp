
// Idea:
// Process mountains in increasing height order.
// For each mountain, expand left and right while neighbors are smaller (visible).
// Use already computed dp values of smaller mountains to build current answer.
//
// 'dp[i]' = max path starting from this mountain
// 'size' helps skip entire processed blocks → O(n) total traversal
//
// At each step:
// - Take best dp from left and right reachable ranges
// - Merge them into one block
//
// This is like building answers bottom-up (small → big) 
// and reusing previously computed segments efficiently.

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstdint>
#include<stack>
#include<functional>
#include<cmath>
using namespace std;


struct Node {
    int h;       // height
    int size;    // merged range size
    int dp;      // max path length
};

int main() {
    int n;
    cin >> n;

    vector<Node> a(n);
    vector<int> order(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].h;
        a[i].size = 1;
        a[i].dp = 1;
        order[i] = i;
    }

    // sort indices by height
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i].h < a[j].h;
    });

    int ans = 1;

    for (int id : order) {
        Node cur = a[id];

        int L = id;
        int R = id;

        // go left
        while (L > 0 && a[L - 1].h < cur.h) {
            Node left = a[L - 1];
            cur.dp = max(cur.dp, left.dp + 1);
            L -= left.size; // jump whole block
        }

        // go right
        while (R < n - 1 && a[R + 1].h < cur.h) {
            Node right = a[R + 1];
            cur.dp = max(cur.dp, right.dp + 1);
            R += right.size; // jump whole block
        }

        // update merged range
        cur.size = R - L + 1;

        ans = max(ans, cur.dp);

        // store at boundaries
        a[L] = a[R] = cur;
    }

    cout << ans << endl;
}