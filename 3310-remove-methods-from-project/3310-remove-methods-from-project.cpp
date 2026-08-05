class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the adjacency list for the directed graph
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: Find all suspicious methods using BFS
        vector<bool> suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next_node : adj[curr]) {
                if (!suspicious[next_node]) {
                    suspicious[next_node] = true;
                    q.push(next_node);
                }
            }
        }
        
        // Step 3: Check if any non-suspicious method invokes a suspicious method
        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }
        
        // Step 4: Construct the result array
        vector<int> ans;
        if (can_remove) {
            // If we can remove them, only add the non-suspicious ones
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {
                    ans.push_back(i);
                }
            }
        } else {
            // If we cannot remove them, return all methods
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};