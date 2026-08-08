class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // suf[i] stores the max length of word2's suffix that is a subsequence of word1[i...]
        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i] = suf[i + 1] + 1;
                j--;
            } else {
                suf[i] = suf[i + 1];
            }
        }
        
        vector<int> ans;
        bool changed = false;
        j = 0;
        
        // Greedily match from left to right for lexicographically smallest indices
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                // Exact match: always optimally safe to take
                ans.push_back(i);
                j++;
            } else if (!changed && suf[i + 1] >= m - 1 - j) {
                // Use our 1 available change here because the rest of word2 can exactly match
                changed = true;
                ans.push_back(i);
                j++;
            }
        }
        
        // If we successfully matched all characters of word2, return the sequence
        if (j == m) {
            return ans;
        }
        
        return {}; // No valid sequence found
    }
};