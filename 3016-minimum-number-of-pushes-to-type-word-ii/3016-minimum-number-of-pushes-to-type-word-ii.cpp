class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        sort(count.rbegin(), count.rend());
        
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) break;
            // The first 8 get 1 push, next 8 get 2, etc.
            int multiplier = (i / 8) + 1;
            totalPushes += count[i] * multiplier;
        }
        
        return totalPushes;
    }
};