class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        
        // dp[r][c] stores the maximum score to reach (r, c) from the start (n-1, n-1)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // paths[r][c] stores the number of ways to reach (r, c) with the max score
        vector<vector<int>> paths(n, vector<int>(n, 0));
        
        // Base case: Starting position
        dp[n - 1][n - 1] = 0;
        paths[n - 1][n - 1] = 1;
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                // Skip the starting point
                if (r == n - 1 && c == n - 1) continue;
                
                // Skip obstacles
                if (board[r][c] == 'X') continue;
                
                int max_val = -1;
                
                // Look at the three possible previous cells (Down, Right, Down-Right)
                if (r + 1 < n && dp[r + 1][c] != -1) max_val = max(max_val, dp[r + 1][c]);
                if (c + 1 < n && dp[r][c + 1] != -1) max_val = max(max_val, dp[r][c + 1]);
                if (r + 1 < n && c + 1 < n && dp[r + 1][c + 1] != -1) max_val = max(max_val, dp[r + 1][c + 1]);
                
                // If max_val is still -1, this cell is completely unreachable
                if (max_val == -1) continue;
                
                long long ways = 0;
                
                // Add up the paths from the directions that yielded the max_val
                if (r + 1 < n && dp[r + 1][c] == max_val) ways = (ways + paths[r + 1][c]) % mod;
                if (c + 1 < n && dp[r][c + 1] == max_val) ways = (ways + paths[r][c + 1]) % mod;
                if (r + 1 < n && c + 1 < n && dp[r + 1][c + 1] == max_val) ways = (ways + paths[r + 1][c + 1]) % mod;
                
                // Calculate the score for the current cell (treat 'E' as 0)
                int score = 0;
                if (board[r][c] != 'E' && board[r][c] != 'S') {
                    score = board[r][c] - '0';
                }
                
                dp[r][c] = max_val + score;
                paths[r][c] = ways;
            }
        }
        
        // If there are no valid paths to the destination 'E', return {0, 0}
        if (paths[0][0] == 0) return {0, 0};
        
        return {dp[0][0], paths[0][0]};
    }
};