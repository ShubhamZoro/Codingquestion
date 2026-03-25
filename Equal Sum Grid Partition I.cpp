// Brute Force

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                total += grid[i][j];
            }
        }

        // If total sum is odd → cannot split
        if(total % 2 != 0) return false;

        // Try horizontal cuts
        long long running = 0;
for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m; j++){
        running += grid[i][j];
    }

    if(running == total - running) return true;
}

        // Try vertical cuts
         running = 0;
for(int j = 0; j < m - 1; j++){
    for(int i = 0; i < n; i++){
        running += grid[i][j];
    }

    if(running == total - running) return true;
}

        return false;
    }
};
