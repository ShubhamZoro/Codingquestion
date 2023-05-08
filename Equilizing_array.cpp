#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int minOperations(vector<int>& arr, int threshold, int d) {
    unordered_map<int, pair<int, int>> dp;
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for (int x : arr) {
        int steps = 0;
        while (true) {
            dp[x].first++;
            dp[x].second += steps;
            if (dp[x].first >= threshold) {
                ans = min(ans, dp[x].second);
            }
            if (x == 0) {
                break;
            }
            x /= d;
            steps++;
        }
    }
    return ans;
}
