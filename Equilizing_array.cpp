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

int main() {
    // Example usage
    vector<int> arr = {10, 20, 30, 40, 50};
    int threshold = 3;
    int d = 2;
    int result = minOperations(arr, threshold, d);
    cout << "Minimum operations: " << result << endl;
    return 0;
}
