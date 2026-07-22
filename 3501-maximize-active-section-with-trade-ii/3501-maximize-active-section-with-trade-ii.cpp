class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_1s = 0;
        for (char c : s) {
            if (c == '1') total_1s++;
        }

        vector<pair<int, int>> zeros;
        vector<pair<int, int>> ones;

        int i = 0;
        // 1. Split consecutive zeros and ones into segments
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if (s[i] == '1') ones.push_back({i, j - 1});
            else zeros.push_back({i, j - 1});
            i = j;
        }

        // Store the start and end indices of the 0-segments for quick lookup
        vector<int> left_zero_start(n, -1);
        vector<int> right_zero_end(n, -1);
        for (auto& z : zeros) {
            for (int k = z.first; k <= z.second; ++k) {
                left_zero_start[k] = z.first;
                right_zero_end[k] = z.second;
            }
        }

        int M = ones.size();
        vector<int> u(M), v(M), x(M, -1), y(M, -1), C(M, 0);

        // 2. Precompute the constant gain for each 1-segment
        for (int k = 0; k < M; ++k) {
            u[k] = ones[k].first;
            v[k] = ones[k].second;
            // Only care about 1-segments that are bounded by 0s in the original string
            if (u[k] > 0 && v[k] < n - 1) {
                x[k] = left_zero_start[u[k] - 1];
                y[k] = right_zero_end[v[k] + 1];
                if (x[k] != -1 && y[k] != -1) {
                    C[k] = (u[k] - x[k]) + (y[k] - v[k]);
                }
            }
        }

        // 3. Build a Sparse Table for range maximum queries on fully covered inner segments
        int LOG = 0;
        while ((1 << LOG) <= M) LOG++;
        vector<vector<int>> st(M, vector<int>(max(1, LOG)));
        
        for (int k = 0; k < M; ++k) {
            st[k][0] = C[k];
        }
        for (int j = 1; j < LOG; ++j) {
            for (int k = 0; k + (1 << j) <= M; ++k) {
                st[k][j] = max(st[k][j - 1], st[k + (1 << (j - 1))][j - 1]);
            }
        }

        auto query_st = [&](int l, int r) {
            if (l > r) return 0;
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);
            return max(st[l][k], st[r - (1 << k) + 1][k]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        // 4. Process each query
        for (auto& q : queries) {
            int L = q[0];
            int R = q[1];

            // Find the range of 1-segments strictly inside [L, R]
            int j_start = upper_bound(u.begin(), u.end(), L) - u.begin();
            int j_end = lower_bound(v.begin(), v.end(), R) - v.begin() - 1;

            int max_gain = 0;
            
            // If there's at least one strictly enclosed 1-segment
            if (j_start <= j_end) {
                // Calculate boundary gain for the first valid segment
                int j1 = j_start;
                int gain1 = min(u[j1] - x[j1], u[j1] - L) + min(y[j1] - v[j1], R - v[j1]);
                max_gain = max(max_gain, gain1);

                // Calculate boundary gain for the last valid segment
                int j2 = j_end;
                int gain2 = min(u[j2] - x[j2], u[j2] - L) + min(y[j2] - v[j2], R - v[j2]);
                max_gain = max(max_gain, gain2);

                // Maximize with all fully inner segments using the Sparse Table
                if (j_start + 1 <= j_end - 1) {
                    max_gain = max(max_gain, query_st(j_start + 1, j_end - 1));
                }
            }
            // Add the optimal local trade gain to the total number of 1s
            ans.push_back(total_1s + max_gain);
        }

        return ans;
    }
};