class Solution {
public:
   long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        // Store precomputed LCM and the sign for inclusion-exclusion (+1 for odd subsets, -1 for even)
        vector<pair<long long, int>> subsetData;
        
        for (int i = 1; i < (1 << n); ++i) {
            long long currentLCM = 1;
            int bits = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    bits++;
                    currentLCM = std::lcm(currentLCM, (long long)coins[j]);
                }
            }
            int sign = (bits % 2 == 1) ? 1 : -1;
            subsetData.push_back({currentLCM, sign});
        }
        
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long left = 1;
        long long right = minCoin * k; 
        long long ans = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            
            // Inclusion-Exclusion Principle
            for (const auto& data : subsetData) {
                count += data.second * (mid / data.first);
            }
            
            if (count >= k) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};