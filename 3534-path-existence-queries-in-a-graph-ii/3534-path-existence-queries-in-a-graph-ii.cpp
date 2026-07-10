class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Store original indices and sort nodes by their values
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        // Map to quickly find the sorted position of any original index
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nodes[i].second] = i;
        }

        // Step 2: Build the Binary Lifting (Sparse) Table
        int LOG = 20; 
        vector<vector<int>> up(n, vector<int>(LOG, 0));

        // Base case: up[i][0] is the furthest right node reachable in 1 jump
        int right = 0;
        for (int i = 0; i < n; ++i) {
            while (right + 1 < n && sorted_nodes[right + 1].first <= sorted_nodes[i].first + maxDiff) {
                right++;
            }
            up[i][0] = right;
        }

        // Fill the rest of the table for 2^k jumps
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }

        // Step 3: Answer each query
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            
            // Distance to itself is 0
            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int p_u = pos[u];
            int p_v = pos[v];

            // Ensure we are always jumping left-to-right (smaller value to larger)
            if (p_u > p_v) {
                swap(p_u, p_v);
            }

            // If the furthest we can ever reach is still before our target, no path exists
            if (up[p_u][LOG - 1] < p_v) {
                ans.push_back(-1);
                continue;
            }

            // Binary lift to find the exact minimum jumps needed
            int curr = p_u;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; --k) {
                // If jumping 2^k steps keeps us strictly before the target, take the jump
                if (up[curr][k] < p_v) {
                    curr = up[curr][k];
                    jumps += (1 << k);
                }
            }

            // `curr` is now at the last possible node BEFORE the target.
            // One final jump will reach or surpass the target.
            ans.push_back(jumps + 1);
        }

        return ans;
    }
};