class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_num = 0;
        for (int x : nums) max_num = max(max_num, x);

        // 1. Count occurrences of each number
        vector<int> cnt(max_num + 1, 0);
        for (int x : nums) cnt[x]++;

        // 2. Count pairs with gcd being a multiple of i
        vector<long long> gcd_counts(max_num + 1, 0);
        for (int i = 1; i <= max_num; ++i) {
            long long div_cnt = 0;
            for (int j = i; j <= max_num; j += i) {
                div_cnt += cnt[j];
            }
            gcd_counts[i] = (div_cnt * (div_cnt - 1)) / 2;
        }

        // 3. Inclusion-Exclusion: Convert to exact counts
        for (int i = max_num; i >= 1; --i) {
            for (int j = 2 * i; j <= max_num; j += i) {
                gcd_counts[i] -= gcd_counts[j];
            }
        }

        // 4. Prefix sums to allow binary search
        vector<long long> prefix_gcd(max_num + 1, 0);
        for (int i = 1; i <= max_num; ++i) {
            prefix_gcd[i] = prefix_gcd[i - 1] + gcd_counts[i];
        }

        // 5. Answer queries using binary search (lower_bound/upper_bound)
        vector<int> results;
        for (long long q : queries) {
            // Find the first GCD where the cumulative count is strictly greater than the query index q
            auto it = upper_bound(prefix_gcd.begin(), prefix_gcd.end(), q);
            
            // The index of the iterator IS the GCD value (removed the -1)
            results.push_back(distance(prefix_gcd.begin(), it));
        }

        return results;
    }
};