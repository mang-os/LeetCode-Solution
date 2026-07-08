class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> nz_pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                nz_pos.push_back(i);
            }
        }

        int C = nz_pos.size();
        vector<long long> pref_sum(C + 1, 0);
        vector<long long> pref_val(C + 1, 0);

        for (int i = 0; i < C; i++) {
            int d = s[nz_pos[i]] - '0';
            pref_sum[i + 1] = pref_sum[i] + d;
            pref_val[i + 1] = (pref_val[i] * 10 + d) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int i = lower_bound(nz_pos.begin(), nz_pos.end(), l) - nz_pos.begin();
            int j = upper_bound(nz_pos.begin(), nz_pos.end(), r) - nz_pos.begin() - 1;

            if (i > j) {
                ans.push_back(0);
            } else {
                int I = i + 1;
                int J = j + 1;
                long long S = pref_sum[J] - pref_sum[I - 1];
                long long X = (pref_val[J] - (pref_val[I - 1] * pow10[J - I + 1]) % MOD + MOD) % MOD;
                long long res = (X * (S % MOD)) % MOD;
                ans.push_back((int)res);
            }
        }
        
        return ans;
    }
};